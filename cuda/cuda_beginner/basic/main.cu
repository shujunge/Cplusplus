#include <iostream>
#include<cstdlib>

#include <cublas_v2.h>
#include <cuda.h>

using namespace std;

#define N 1024

__global__ void add(int * a,int *b,int *c)
{
 c[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x];
}
void random_ints(int* x, int size)
{
        int i;
        for (i=0;i<size;i++) {
                x[i]=rand()%10;
        }
}
int main() {
    int *h_a, *h_b, *h_c;
    int *d_a, *d_b, *d_c;

    int size = N * sizeof(int);

    cudaMalloc((void**)&d_a,size);
    cudaMalloc((void**)&d_b,size);
    cudaMalloc((void**)&d_c,size);
    h_a = (int *)malloc(size);
    h_b = (int *) malloc(size);
    h_c = (int *) malloc(size);
    random_ints(h_a, N);
    random_ints(h_b, N);
    random_ints(h_c, N);

    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);
    // Launch add() kernel on GPU
    add<<<N,1>>>(d_a, d_b, d_c);
    // Copy result back to host
    cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);
    // Cleanup
/*    for(int i=0;i<N;i++)
    {
       cout<< h_c[i]<<" ";
    }
    cout<<endl;
*/
    free(h_a);free(h_b);free(h_c);
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
//    cout <<"c= "<< h_c << endl;
    return 0;
}

