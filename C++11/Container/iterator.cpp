#include <iostream>
#include<set>
#include<vector>
#include<iterator>
#include<map>
#include<algorithm>
#include<assert.h>
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
    //simple stl lterator example
    vector<int> list;
    for(int i=0;i<10;i++)
        list.emplace_back(i);
    for(vector<int>::iterator i=list.begin();i!=list.end();i++)
        cout<<*i<<endl;

    //input lterator example
    list.erase(list.begin(),list.end());
    for(istream_iterator<int> i=cin;
            i!=istream_iterator<int> ();i++)
    {
        list.emplace_back(*i);
        if(list.size()>3)
            break;
    }
    for(auto i: list)
        cout<<i<<endl;

    //stl output Iterator example
    list.erase(list.begin(),list.end());
    for(int i=0;i<10;i++)
        list.emplace_back(i);
    copy(list.rbegin(),list.rend(),ostream_iterator<int>(cout," "));
    cout<<endl;

    //stl forward iterator example

    vector<int> v(3,1);
    for(auto item:v)
        cout<<item<<endl;
    v.push_back(4);
    my_replace(v.begin(),v.end(),4,1);
    for(auto item:v)
        cout<<item<<endl;
    assert(find(v.begin(),v.end(),7)==v.end());
    return 0;
}