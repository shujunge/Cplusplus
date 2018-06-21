//
// Created by zf on 18-5-6.
//

#include <iostream>
#include <algorithm>
#include <future>
using namespace std;

int f(int n)
{
    return n<=2? 1:f(n-1)+f(n-2);
}

int cac1()
{
    return f(20);
}
int cac2()
{
    return f(30);
}
int main()
{
    //start cac1() asynchronoudsly
    future<int> result1=async(cac1);
    //call cac2() synchronoudsly
    int result2=cac2();
    // wait for cac1() and add its result to result2
    result2=result1.get()+result2;
    cout<<result2<<endl;
    return 0;
}
