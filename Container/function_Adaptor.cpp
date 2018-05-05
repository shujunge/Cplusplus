#include <iostream>
#include<set>
#include<vector>
#include<iterator>
#include<map>
#include<algorithm>
#include <functional>
#include<numeric>

using namespace std;


int main()
{
    vector<int> v(10,2),v1;
    for(auto item:v)
        cout<<item<<" ";
    cout<<endl;
    partial_sum(v.begin(),v.end(),back_inserter(v1));
    random_shuffle(v1.begin(),v1.end());
    for(auto item:v1)
        cout<<item<<" ";
    cout<<endl;

    cout<<count_if(v1.begin(),v1.end(),bind2nd(greater<int>(),10))<<endl;

    string s="hello    world    this";
    cout<<s<<endl;
    string::iterator I=remove_if(s.begin(),s.end(),bind2nd(equal_to<char>(),' '));
    s.erase(I,s.end());
    cout<<s<<endl;
    return 0;
}