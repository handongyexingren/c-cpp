#include <iostream>
#include <stdio.h>
class ARRAY{
    int size;
    int *p;
    public :
    int get(int x);
    ARRAY(int s);
    ~ARRAY();
};
int ARRAY::get(int x){
    return p[x];
}
ARRAY::ARRAY(int s){
    int i;
    p=new int[size=s];
    for(i=0;i<s;i++){
        p[i]=1;
    }
    std::cout<<"construct ARRAY("<<s<<")"<<std::endl;
}
ARRAY::~ARRAY(){
    int i;
    if(p){
        delete p;
        p=0;
    }
    std::cout<<"deconstruct ARRAY("<<size<<")"<<std::endl;
}
void func(ARRAY y){
    std::cout<<"func:";
}
int main(void){
    std::cout<<"main:";
    ARRAY a(6);
    std::cout<<"main:a[0]="<<a.get(0)<<"\n";
    func(a);
    int *q=new int[6];
    q[0]=8;
    std::cout<<"main:a[0]="<<a.get(0)<<"\nmain:";
    getchar();
    return 0;
}