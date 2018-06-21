#include <iostream>
#include<set>
#include<vector>
#include<iterator>
#include<map>
#include<algorithm>
using namespace std;

template  <typename Type>
void print(const vector<Type>&A)
{
    for(auto item:A)
    {
        cout<<item<<" ";
    }
    cout<<endl;
}

template  <typename Type>
void print(const vector<vector<Type>> &A)
{
    for(auto item:A)
    {
        for(auto it:item)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


typedef map<string,int> m_map;

int main()
{
    set<int> m_set;
    for(int i=0;i<10;i++)
        m_set.insert(i);

    int number[]={1,12,14,5,6,47,8,13,9};
    m_set.insert(number,number+9);
    copy(m_set.begin(),m_set.end(),ostream_iterator<int>(cout," "));
    pair<set<int>::iterator,bool> ret=m_set.insert(20);

    m_map map1;
    for(int i=0;i<3;i++)
    {
        string stringword;
        cin>>stringword;
        map1[stringword]++;
    }

    for(auto item:map1)
        cout<<item.first<<" "<<item.second<<endl;


    int a[]={1,2,3,4,5,6,7,87,8,9};
    int b[]={1,2,3,34,5,46,7,84,28,19};
    multiset<int> A;
    multiset<int> B;
    multiset<int> C;
    A.insert(a,a+10);
    B.insert(b,b+10);
    copy(A.begin(),A.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    cout<<"the union between A and B is:"<<endl;
    set_union(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    cout<<"the intersection between A and B is:"<<endl;
    set_intersection(A.begin(),A.end(),B.begin(),B.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.end()));
    cout<<"the difference between A and B is:"<<endl;
    for( auto item:C)
        cout<<item<<endl;
    cout<<endl;


    return 0;
}
