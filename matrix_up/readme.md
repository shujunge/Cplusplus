
首先之前线程数我设置错误了。我的 CPU physically 应该只有两个核，四线程是 hyper－thread 的结果，
多出来的两个线程并不能加速。我把 OMP_NUM_THREADS 改为 2 以后，速度变为 0.55s 左右；

如果计算矩阵乘法，使用B.noalias()=At*A 是个不错的trick，它可以避免生成 temporary 的矩阵存储中间结果。使用这个后缩短为 0.50s 左右；
对 Eigen 3.3 或以上的版本可以加上-mavx 和-mfma两个参数，进一步缩短为 0.40s 左右。

c++算法加速
----

* eigen
* openmp
* 多线程


* cuda
* cublas

编译器命令优化
------
g++ -Ofast

少优化->多优化：

O0 -->> O1 -->> O2 -->> O3

-O0表示没有优化,-O1为缺省值，-O3优化级别最高


