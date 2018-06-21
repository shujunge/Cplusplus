opencv_eigen3_C++
===
内存泄漏检测:
---
```apple js
>> valgrind --tool=memcheck --leak-check=yes ./out

```

cuda命令行编译
---
```
>>> nvcc filename.cu -o filename
>>> nvprof ./filename

```
