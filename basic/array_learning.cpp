//
// Created by zf on 18-5-6.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <tuple>
#include <string>
#include <map>
#include <array>
#include <thread>
#include <mutex>
using namespace std;
mutex m;
void run(size_t n)
{
//    m.lock();
//    for(size_t i=0;i<5;i++)
//    {
//        cout<<n<<":"<<i<<endl;
//    }
//    m.unlock();
//等价于下面
    lock_guard<mutex> lm(m);
    for(size_t i=0;i<5;i++)
    {
        cout<<n<<":"<<i<<endl;
    }

}
template <class T>
void print_list(T value)
{
    cout<<value<<endl;
}

template <class T,class ... Rest>
void print_list(T value,Rest ... rest)
{
    cout<<value<<",";
    print_list(rest...);
}

int main()
{
    //Variadic templates learning
    print_list(12);
    print_list(12,2,3,4,'4',2.3,"hello");
    
    //array learning
    array<int,3> a={1,2,3};
    auto x=a.data();
    cout<<*(x+1)<<endl;
    cout<<a.size()<<endl;
    a.at(1)=23;
    x=a.data();
    cout<<*(x+1)<<endl;
    cout<<a.size()<<endl;

    //thread learning
    thread t1(run,1);
    thread t2(run,2);
    thread t3(run,3);

    t1.join();
    t2.join();
    t3.join();


    return 0;
}
