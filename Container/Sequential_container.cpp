#include <iostream>
#include<list>
#include<vector>
#include <iterator>
#include<deque>
#include <string>
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

template  <typename Type,typename N>
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

template  <typename Type>
void print(const list<Type>&A)
{
    for(auto item:A)
    {
        cout<<item<<" ";
    }
    cout<<endl;
}

template  <typename Type,typename N>
void print(const list<list<Type>> &A)
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


int main()
{
    vector<string> str;
    str.emplace_back("12");
    str.emplace_back("world");
    print(str);


    vector<int> vectorone;
    for(int i=0;i<10;i++)
        vectorone.emplace_back(i);
    print(vectorone);

    vector<float> vectorfloat;
    for(int i=0;i<10;i++)
        vectorfloat.emplace_back(i);
    print(vectorfloat);

    vector<double> vectordouble;
    for(int i=0;i<10;i++)
        vectordouble.emplace_back(i);
    print(vectordouble);


    list<string> list_str;
    list_str.emplace_back("12");
    list_str.emplace_back("world");
    print(list_str);


    list<int> list_one;
    for(int i=0;i<10;i++)
        list_one.emplace_back(i);
    print(list_one);

    list<float> list_float;
    for(int i=0;i<10;i++)
        list_float.emplace_back(i);
    print(list_float);

    list<string> list_double;
    list_double.emplace_back("I");
    list_double.emplace_back("am");
    list_double.emplace_back("king");

    print(list_double);

    ostream_iterator<string> out_it(cout,"\n");
    copy(list_double.begin(),list_double.end(),out_it);
    copy(list_double.rbegin(),list_double.rend(),out_it);

    deque<int> a_deck;
    a_deck.emplace_back(3);
    a_deck.emplace_front(23);
    a_deck.pop_back();
    for(auto item:a_deck)
        cout<<item<<endl;
    copy(a_deck.begin(),a_deck.end(),ostream_iterator<int>(cout," "));


    return 0;
}