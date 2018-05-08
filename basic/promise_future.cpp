//
// Created by zf on 18-5-6.
//

#include <iostream>
#include <algorithm>
#include <future>
#include <regex>
#include <chrono>
using namespace std;

void add(promise<int>&&pro,int x,int y)
{
    pro.set_value(x+y);
}

int main()
{
    auto start=chrono::system_clock::now();
    int a=23;
    int b=45;
    //implicitly by async
    future<int> sum=async([=]{return a+b;});
    cout<<sum.get()<<endl;

    //explicity by future and promise
    promise<int> sumpromise;
    future<int> futsum=sumpromise.get_future();
    thread sumthread(&add,move(sumpromise),a,b);
    sumthread.join();
    cout<<futsum.get()<<endl;


    auto time=chrono::system_clock::now()-start;
    auto totaltime=chrono::duration<double>(time).count();
    cout<<"programming running time is: "<<totaltime<<"s"<<endl;

    return 0;
}
