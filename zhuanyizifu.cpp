#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    std::cout<<"\115"<<std::endl;
    std::cout<<'\115'<<'\n';
    std::cout<<"\115";
    std::cout<<'\115';
    printf("\n");
    double Double =9.0;
    std::cout<<Double<<std::endl;
    //为什么输出的是9，而不是9.0呢
    //Double变量定义正确
    getchar();
    return 0;
}
