//
// Created by zf on 18-5-6.
//

#include <iostream>
#include <algorithm>
#include <ctime>
#include <tuple>
#include <string>
#include <map>
using namespace std;
using VI=vector<int>;
int main()
{
    //tuple learning
    tuple<int,float,string> t(1,2.0,"hello");
    cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<endl;
    int a=0;
    int b=3;
    string str="hello tuple";
    tie(b,a,str)=make_tuple(a,b,str);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<str<<endl;

    //Iinitialization learning
    int a[]={1,2,3,4,5};
    VI v={1,2,3,4,56,7};
    map<int,string> map{{1,"a"},{2,"b"}};
    v={2,5,6,7};
    cout<<v.size()<<endl;
    VI vs={5};
    int y(2);
    cout<<y<<endl;
    for(auto x:vs)
        cout<<x<< " ";
    cout<<endl;

    return 0;
}