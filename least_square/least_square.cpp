#include "Eigen/Dense"
#include <vector>
#include <iostream>
using namespace std;
using namespace Eigen;

template <typename Type>
void print(const vector<Type>&A )
{
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template <typename Type>
void print(const vector<vector<Type>>&A )
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


template <typename Type>
void print(const vector<vector<vector<Type>>>&A )
{
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            for(int k=0;k<A[i][j].size();k++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
}

void norm2(const MatrixXd& m_An,const VectorXd& m_Bn,VectorXd& m_result)
{
    VectorXd m_Tn(m_Bn.size());
    m_result.setZero();
    cout<<m_An<<endl;
    do
    {
        m_Tn=m_An.transpose()*(m_An*m_result-m_Bn);
        m_result=m_result-0.01*m_Tn;
        if (pow(m_Tn(0),2)+pow(m_Tn(1),2)<=0.0000001)
        {
            break;
        }
    }while(1);
    cout<<m_result<<endl;
}
VectorXd norm2(const MatrixXd& m_An,const VectorXd& m_Bn)
{
    MatrixXd m_Tn;
    VectorXd m_result(m_Bn.size());
    m_result.setZero();
    m_Tn=m_An.transpose()*m_An;
    m_result=m_Tn.inverse()*m_An.transpose()*m_Bn;

    return m_result;
}

void small2(const MatrixXd& m_An,const VectorXd& m_Bn,VectorXd& m_result)
{
    VectorXd m_Tn(m_Bn.size());
    m_result.setZero();
    do
    {
        m_Tn=m_An.transpose()*(m_An*m_result-m_Bn);
        m_result=m_result-0.01*m_Tn;
        if (pow(m_Tn(0),2)+pow(m_Tn(1),2)<=0.0000001)
        {
            break;
        }
    }while(1);
    cout<<m_result<<endl;
}

VectorXd small2(const MatrixXd& m_An,const VectorXd& m_Bn)
{
    MatrixXd m_Tn;
    VectorXd m_result(m_Bn.size());
    m_result.setZero();
    m_Tn=m_An*m_An.transpose();
    m_result=m_An.transpose()*m_Tn.inverse()*m_Bn;

    return m_result;
}


int main()
{
    //最小二乘法解
    MatrixXd m_An(3,3);
    m_An<<1,-2,2,1,-1,0,-1,1,1;
    VectorXd m_Bn(3);
    m_Bn<<5,-1,5;
    VectorXd m_result(3);

    norm2(m_An,m_Bn,m_result);
    m_result=norm2(m_An,m_Bn);
    cout<<m_result<<endl;
    //极小范数解,线性方程组有多个解时,求最小解
    MatrixXd m_An(2,3);
    m_An<<1,-2,2,1,-1,0;
    VectorXd m_Bn(2);
    m_Bn<<5,-1;
    VectorXd m_result(3);
    small2(m_An,m_Bn,m_result);
    m_result=small2(m_An,m_Bn);
    cout<<m_result<<endl;
    cout<<"****************"<<endl;
    m_result=norm2(m_An,m_Bn);
    cout<<m_result<<endl;
    return 0;
}