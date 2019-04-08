#include <iostream>
#include <stdio.h>
class A{
    int i;
    public:
    A(int i){
        A::i=i;
        std::cout<<i<<std::endl;
    };
        ~A(){
            if(i){
                std::cout<<i<<std::endl;
            };
            i=0;
        }
    };  //类内部 定义类，构造函数，析构函数后有个  ; 号
    void g(A &a){
        std::cout<<"g is running"<<std::endl;
    }
int main(void){
    A a(1),b(2);
    A &p=a;
    A &q=*new A(3);
    A &r=p;
    std::cout<<"call g(b):"<<std::endl;
    g(b);
    std::cout<<"main return"<<std::endl;
    delete &q;
    getchar();
    return 0;
}   //运行结果显示，main函数体结束后没有自动析构 a,b