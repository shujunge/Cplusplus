#define EIGEN_USE_MKL_ALL

#include <iostream>
#include <Eigen/Dense>
#include<time.h>
#include<stdlib.h>
using namespace::Eigen;

#define DEFAULT_SIZE_M 1024

typedef Eigen::Matrix<int, Dynamic, Dynamic> IntMatrix;

int main(int argc, char* argv[])
{
    int m_size;
    if (argc > 1) {
        m_size = atoi(argv[1]);
    } else {
        m_size = DEFAULT_SIZE_M;
    }
    clock_t start,finish;
    start = clock();
    IntMatrix mat1(m_size,m_size);
    IntMatrix mat2(m_size,m_size);
    IntMatrix result(m_size,m_size);
    mat1.setRandom();
    mat2.setRandom();

    result = mat1 * mat2;
    finish = clock();
    std::cout<<" total times:"<< (double)(finish-start)/CLOCKS_PER_SEC<< std::endl;
    //std::cout<<result<< std::endl;
    std::cout << "finished" << std::endl;
}
