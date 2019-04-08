#include <iostream>
#include <stdio.h>
namespace ALPHA{
    extern int x;   //声明整型变量
    void g(int);
    void g(long){
        std::cout<<"long"<<std::endl;
    }
}
using ALPHA::x;
using ALPHA::g;     //g(int),g(long)  都能用了
namespace ALPHA{
    int x=5;
    void g(int){
        std::cout<<"int"<<std::endl;
    }
    void g(void){
        std::cout<<"void"<<std::endl;
    }
    void t(char){
        std::cout<<"char"<<std::endl;
    }
}
using namespace ALPHA;   //没有这一行，t 不能用
int main(void){
    g(4);
    g(4L);
    std::cout<<"X="<<x<<std::endl;
    //ALPHA::g(void);   //直接访问,怎么出错了，为什么啊      换种方式吧
    //找到原因了，好想要写成  g();  参数为空
    ALPHA::g(); //对了
    using ALPHA::g;     //不能写成using ALPHA::g()  或者 using ALPHA::g(void);都会报错
    g();
    t('A');
    //命名空间内的函数，要using,否则调用失败。
    //可直接访问（ALPHA::g(void));
    //可声明引用成员,之前的那个using在定义g(void)之前，所以对g(void)无效，（using ALPHA::g)；
    //可指定名字空间,using namespace ALPHA;
    getchar();
    return 0;
}