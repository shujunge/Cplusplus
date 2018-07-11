// Using different memory sapces in CUDA

#include <stdio.h>

/*
 * Using local memory
 */

// a __device__ or __global__ function runs on the GPU
__global__ void use_local_memory_GPU(float in)
{
	float f; // varible "f" is in local memory and private to each thread
	f = in;
}


/*
 * Using global memory
 */

// a __global__ function runs on the GPU & can be called from host
__global__ void use_global_memory_GPU(float* array)
{
	// "array" is a pointer into global memory on the device
	array[threadIdx.x] = 2.0f * (float)threadIdx.x;
}


/*
 * Using shared memory
 */

// for clarity, hardcoding 128 threads/elements and omitting out-of-bounds checks
__global__ void use_shared_memory_GPU(float *array)
{
	// local variables, private to each thread
	int i;
	int index = threadIdx.x;
	float average, sum = 0.0f;

	// __shared__ varibales are visible to all threads in the thread block
	// and have the same lifetime as the thread block
	__shared__ float sh_arr[128];

	// copy data from "array" in global memory to sh_arr in shared memory
	// here, each thread is responsible for copying a single element
	sh_arr[index] = array[index];

	// ensure all the writes wo shared memory have completed
	__syncthreads();

	// now, sh_arr is fully populated. Let's find the average of all previous elements
	for (int i = 0; i < index; i++)
		sum += sh_arr[i];
	average = sum / (index + 1.0f);

	// if array[index] is greater than the average of array[0..index-1], replace with average.
	// since array[] is in global memory, this change will be seen by the host (and potentially
	// other thread blocks, if any)
	if (array[index] > average)
		array[index] = average;

	// the following code has NO EFFECT: it modifies shared memory, but
	// the resulting modified data is never copied back to global memory
	// and vanishes when the thread block completes
	sh_arr[index] = 3.14;
}

int main(int argc, char** argv)
{
	/*
	 * First, call a kernel that shows using local memory
	 */
	use_local_memory_GPU<<<1, 128>>>(2.0f);

	/*
	 * Next, call a kernel that shows using global memory
	 */
	float h_arr[128]; // convention: h_ variables live on host
	float *d_arr;	  // convention: d_ variables live on device (GPU global mem)

	// allocate global memory on the device, place result in "d_arr"
	cudaMalloc((void**)&d_arr, sizeof(float) * 128);
	// now copy data from host memory to device memory
	cudaMemcpy((void *)d_arr, (void*)h_arr, sizeof(float) * 128, cudaMemcpyHostToDevice);
	// launch the kernel
	use_global_memory_GPU<<<1, 128>>>(d_arr);
	// copy the modified array back to the host, overwriting contents of h_arr
	cudaMemcpy((void *)h_arr, (void *)d_arr, sizeof(float) * 128, cudaMemcpyDeviceToHost);
	// ... do other stuff ...
	for (int i = 0; i < 128; ++i)
	{
		printf("%f", h_arr[i]);
		printf((i % 4 != 3) ? "\t" : "\n");
	}

	/*
	 * At last, call a kernel that show using shared memory
	 */

	// as before, pass in a pointer to data in global memory
	use_shared_memory_GPU<<<1, 128>>>(d_arr);
	// copy the modified array back to the host
	cudaMemcpy((void *)h_arr, (void *)d_arr, sizeof(float) * 128, cudaMemcpyDeviceToHost);

	for (int i = 0; i < 128; ++i)
	{
		printf("%f", h_arr[i]);
		printf((i % 4 != 3) ? "\t" : "\n");
	}

	return 0;
}