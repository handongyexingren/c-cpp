#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
const int n=14;
//创建一个装有数组A以每5个元素为1组共n/5组，每组的中位数放入到数组B中，组成一组含有n/5个中位数的数组B
int Find(int A[n],int p,int r);//递归当前数组A中从p到r个元素，以找到辅助中位数数组B的中位数。
int PARTITION(int A[],int p,int r,int t)//t代表中位数数组B中的中位数，这里t代表为主元。
{
    int i=p-1,k=0;
    for (int j=p;j<=r;j++)
    {
        if (A[j]<t)//将比主元t大的元素交换到数组A的右边去，比主元t小的到数组A的左边。
        {
            i++;
            swap(A[i],A[j]);
        }
        if (A[j]==t)//如果A[j]等于主元
        {
            k=j;//那么记录下主元在A中的位置。
        }
    }
    swap(A[i+1],A[k]);//完成划分操作，主元左边的元素都小于主元，主元右边的元素都大于主元。
    return i+1;
}
int SELECT(int A[],int p,int r,int i)//i表示第i小的数。
{
    if (p>=r)
    {
        return A[p];
    }
    int t=Find(A,p,r);//返回的t代表辅助数组B的中位数。    
    int q=PARTITION(A,p,r,t);
    int k=q-p+1;
    if (i==k)
    {
        return A[q];
    }
    else if(i<k)
    {
        return SELECT(A,p,q-1,i);
    }
    else return SELECT(A,q+1,r,i-k);
}
int Find(int A[n],int p,int r)
{    
    int key=0,t=0,m=r-p+1,h=0;
    if (m%5==0)//如果当前数组A的大小能被5整除，那么这以5个元素为一组的m/5组数，没有余数那一组
    {
        h=m/5;
    }
    else//否则，应该加上含有余数的那一组。
    {
        h=m/5+1;
     }
    int *B=new int[h];
    for(int j=0;j<h;j++)
    {
        B[j]=0;
    }
    for (int k=0;k<h;k++)//5个数一组，共h组。进行插入排序。
    {//经过最多h=n/5+1次循环，那么总共循环了25h=25(n/5+1)=5n+25=O(n)次
        for (int j=t+1+p;j<=5+t+p&&j!=r+2;j++)//h组中每组进行插入排序。注意加上数组初始坐标p(当前数组A的初值坐标)+t(在p基础上每5个为1组)
        {//运行时间分析：5个一组运行插入排序，每次插入排序需要的时间是O(n^2)=5^2=25是基于固定划分的固定常数
            key=A[j-1];
            int i=j-1;
            while (i>t+p&&A[i-1]<key)
            {
                A[i]=A[i-1];
                i=i-1;
            }
            A[i]=key;
        }
        t+=5;//进入下一个5个元素为一组的插入排序
    }
    int k=0;
    for (int i=0;i<h&&k<h;i++)//经过最多h=n/5+1次循环(O(n))，将当前数组A中的每组的中位数依次放入到B中
    {
        if (i<h-1)
        {
            B[k]=A[2+5*i+p];
            k++;
            continue;
        }
        if(m%5!=0)
        {
            B[k]=A[5*i+p+(m%5)/2];
        }
        else 
        {
            B[k]=A[2+5*i+p];
            k++;
        }
    }
    if (h==1)
    {
       return B[0];//当辅助数组B只剩下一个数时，那么这个数就是中位数的中位数。
    }
    else
    {
       return SELECT(B,0,h-1,(h-1)/2+1);//如果数组B元素个数是偶数，那么取数组B中的较小值。
    }
}
int main()
{
    int A[n]={0};
    //随机输入数组
    srand( (unsigned)time( NULL ) );
    for (int i=0;i<n;i++)
    {
        A[i]=rand()%100;
        cout<<A[i]<<"\t";
    }
    cout<<endl;
    cout<<"第"<<5<<"小的数="<<SELECT(A,0,n-1,5)<<endl;

    getchar();
    return 0;
}