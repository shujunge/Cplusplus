//
// Created by zf on 18-5-6.
//

#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
int main()
{
    int a[10] = {0};
    srand(time(NULL));
    generate(a,a+10,[]()->int { return rand() % 100; });
    cout<<"before sort: "<<endl;
    for_each(a, a+10, [&](int i){ cout<< i <<" "; });
    cout<<endl;
    cout<<"After sort"<<endl;
    sort(a,a+10);
    for_each(a, a+10, [&](int i){ cout<< i <<" "; });
    return 0;
}