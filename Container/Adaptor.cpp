#include <iostream>
#include<set>
#include<vector>
#include<iterator>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

template <typename F,typename T>
void my_replace(F frist,F last,const T&old_value,const T&new_value)
{
    for(;frist!=last;++frist)
        if(*frist==old_value)
            *frist=new_value;
};

int main()
{
    vector<int> v(10,100);
    int a[10];
    fill(a,a+10,100);
    fill_n(a,10,200);
    for(auto item:a)
        cout<<item<<" ";
    cout<<endl;

    fill_n(v.begin(),v.size(),120);
    for(auto item:v)
        cout<<item<<" ";
    cout<<endl;

    stack<int> s;
    s.push(1);
    s.push(34);
    s.push(67);
    s.push(35);
    cout<<s.size()<<endl;
    while(!s.empty())
    {
        int e=s.top();
        cout<<e<<" ";
        s.pop();
    }

    queue<int> q;
    q.push(1);
    q.push(34);
    q.push(67);
    q.push(35);
    cout<<q.size()<<endl;
    while(!q.empty())
    {
        int e=q.front();
        cout<<e<<" ";
        q.pop();
    }

    return 0;
}