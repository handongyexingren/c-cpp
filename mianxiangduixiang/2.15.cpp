#include <iostream>
#include <stdio.h>
using namespace std;
int &f(int i){
    int &j=i;
    return j;
}
int &g(){
    int k=6,&m=k;
    return m;
}
int main(void){
    int &x=f(10),x1=x;
    std::cout<<"x="<<x<<"x1="<<x1<<'\n';
    int &y=g(),y1=y;
    std::cout<<"y="<<y<<"y1="<<y1<<'\n';
    getchar();
    return 0;
}