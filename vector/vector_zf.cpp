#include <iostream>
#include<vector>
using namespace std;

/*
 * vector<int>,vector<string>,vector<double>
 */
typedef  vector<double> oneTuple;
typedef  vector<oneTuple> twoTuple;
typedef  vector<twoTuple> threeTuple;

void print(oneTuple& list)
{
    for(int i=0;i<list.size();i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

void print(twoTuple& list)
{
    for(int i=0;i<list.size();i++)
    {
       for(int j=0;j<list[i].size();j++)
       {
           cout<<list[i][j]<<" ";
       }
        cout<<endl;
    }
    cout<<endl;
}

void print(threeTuple& list)
{
    for(int i=0;i<list.size();i++)
    {
        for(int j=0;j<list[i].size();j++)
        {
            for(int k=0;k<list[i][j].size();k++)
            {
                cout<<list[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    oneTuple onelist1={1,2,3,4,5,6};
    oneTuple onelist2={-1,-2,-3,-4,-5,-6};
    //１维的vector添加元素
    onelist1.push_back(34);
    //１维vector在指定的地方添加元素
    onelist1.insert(onelist1.begin()+4, 3);   //在指定位置，例如在第五个元素前插入一个元素
    //清除１维的vector
    onelist1.erase(onelist1.begin(),onelist1.end());
    //１维的vector清除指定的位置
    onelist1.erase(onelist1.end());

    //２维vector运算
    twoTuple twolist;
    //２维vector添加１维vector
    twolist.push_back(onelist1);
    //２维vector在指定的位置添加1维vector
    twolist.insert(twolist.begin(),onelist2);
    //２维vector如何添加１个数
    twolist[0].push_back(100);


    //删除整个２维vector
    twolist.erase(twolist.begin(),twolist.end());
    //2维的vector清除指定的位置
    twolist.erase(twolist.end());
    //２维vector如何删除１个数
    twolist[0].pop_back();
    // twolist[0].erase( twolist[0].end()); //error

    //3维vector运算
    threeTuple threelist;
    //3维vector添加2维vector
    threelist.push_back(twolist);

    //删除整个3维vector
    threelist.erase(threelist.begin(),threelist.end());
    //3维的vector清除指定的位置
    threelist.erase(threelist.end());

    cout << "Hello, World!" << endl;
    return 0;
}