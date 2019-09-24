/*
x=x&(x-1) 统计十进制数中１的个数
x=x|(x+1) 统计十进制数中0的个数
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string>
#include<deque>
using namespace std;

void five_1_solution(char * ss)
{
// inputs=1024 21 2 6
//outputs=2124
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    cout<<"n= "<<n<<endl;
    cout<<"m= "<<m<<endl;
    cout<<"i= "<<i<<endl;
    cout<<"j= "<<j<<endl;
    int max=~0;
    int left= n &((max-((1<<j)-1))|((1<<i)-1));
    int results=(m<<i)|left;
    sprintf(ss,"%o",results);

}
void five_2_solution(char * ss)
{
    string s;
    cin>>s;
    cout<<"input s is:"<<endl<<s<<" sizeof:"<<sizeof(s)<<endl;
//    float results=float(s);
//    cout<<atof(s)<<endl;
    cout<<s[0]<<endl;
}
void five_3_solution(char * ss)
{
    string s;
    cin>>s;
    cout<<"input s is:"<<endl<<s<<" sizeof:"<<sizeof(s)<<endl;
    int hight_number=0;
    int hig,min;
    int i;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='.')
        {
         break;
        }
        hight_number=10*hight_number+s[i]-'0';

    }
    hig=hight_number;
    cout<<hig<<endl;
    float values=0.0;
    i=i+1;
    for (;i<s.size();i++)
    {
    values=10*values+s[i]-'0';

    }
    cout<<values<<endl;
    deque<int> my_s;
    int count=0;
    while(hig)
    {
      my_s.push_back(hig%2);
      hig=hig/2;
    }
//    cout<<"results:"<<my_s<<endl;

for(int i=0;i<my_s.size();i++)
{
 cout<<my_s[i]<<" ";
}
cout<<endl;

}


void five_5_solution()
{
   int m,n;
   int count=0;
   cin>>m>>n;
   int results=m^n;
   while(results)
   {
     ++count;
     results=(results-1)&results;
   }
   cout<<" values 1 count= "<<count<<endl;

   results=m^n;
   int true_zeros=0;
   while(results)
   {
     ++true_zeros;
     results=results>>1;

   }

   cout<<" true 0 count= "<<true_zeros<<endl;

   results=pow(2,15)-1;
   count=0;
   while(results+1)
   {
     ++count;
     results=(results+1)|results;
   }
   cout<<" values 0 count= "<<count<<endl;

}

void five_6_swapOddEvenBits()
{
    int n;
    cin>>n;
   int results=(((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1) );
   cout<<results<<endl;
}

int main()
{

    char ss[32];
//    five_1_solution(ss);
//    five_2_solution(ss);
    five_3_solution(ss);
    cout<<ss<<endl;
}



