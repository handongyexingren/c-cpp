#include <iostream>
#include <stdio.h>
using namespace std;
struct A{
    int a;
    A(int x){
        a=x;
    }
};
struct B:A{
    B(int x):A(x){}
};
struct C{
    C(){}
};
struct D:virtual A,C{
    D(int x):A(x){}
};
struct E:B,D{
    E(int x):A(0),B(x+5),D(x+10){}
};
int main(void){
    E e(0);
    cout<<"e.B::a"<<e.B::a<<endl;
    cout<<"e.D::a"<<e.D::a<<endl;
    //运行前预测，先构造虚基类 A(0);
    //再构造A(0),B(5),    D(10)不再对虚基类进行构造
    getchar();
    return 0;
}