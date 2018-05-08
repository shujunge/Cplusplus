//
// Created by zf on 18-5-6.
//

#include <iostream>
#include <algorithm>
#include <future>
#include <string>
#include <regex>
#include <chrono>
using namespace std;


template  <typename T,typename U>

T createOject(U && u)
{
    return T(forward<U>(u));
};

int main()
{
    auto start=chrono::system_clock::now();
    //move learning
    string str1{"hello world"};
    string str2;
    str2=move(str1);
    cout<<str2<<endl;//"hello world"
    cout<<str1<<endl;// nothing

    //perfect forwarding learning
    int my=createOject<int>(5);  //Rvalue
    int five=5;
    int my_five=createOject<int>(five); //lvalue
    cout<<my_five<<endl;

    //regular expressions learning

    string str="hello 2344 world3.14.2.5.622";
    regex renum(R"(\d+)");

    sregex_token_iterator it(str.begin(),str.end(),renum);
    sregex_token_iterator end;
    while(it!=end)
    {
        cout<<*it++<<endl;
    }
    auto time=chrono::system_clock::now()-start;
    auto totaltime=chrono::duration<double>(time).count();
    cout<<"programming running time is: "<<totaltime<<"s"<<endl;
    return 0;
}
