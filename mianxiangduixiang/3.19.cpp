#include <iostream>
#include <stdio.h>
struct MESSAGE{
    char flag;  //消息类型
    int size;   //消息长度
    char buff[255]; //消息缓冲区
    long sum;   //消息累加和
};
int main(){
    std::cout<<"sizeof(char)"<<sizeof(char)<<std::endl;
    std::cout<<"sizeof(int)"<<sizeof(int)<<std::endl;
    std::cout<<"sizeof(long)"<<sizeof(long)<<std::endl;
    std::cout<<"sizeof(MESSAGE)"<<sizeof(MESSAGE)<<std::endl;
    getchar();
    return 0;
}
//从运行结果看，编译对齐方式为松散型。当占用，261~264字节时，输出的结果都为264字节，说明是以4字节为单位的