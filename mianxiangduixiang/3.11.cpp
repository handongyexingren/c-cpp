#include <iostream>
#include <stdio.h>

enum ALPHA{a,b,c,d};
class SWITCH{
    int power:3;
    int water:5;
    int gas:5;
    int oil:6;
    int start:1;
    int alarm:3;
    ALPHA stop:1;
    int manual:4;
};
union STATE{
    int speed:4;
    unsigned run:2;
};
int main(void){
    std::cout<<"STATE:"<<sizeof(STATE)<<"bytes\n";
    std::cout<<"SWITCH:"<<sizeof(SWITCH)<<"bytes\n";
    std::cout<<"int:"<<sizeof(int)<<"bytes\n";
    getchar();
    return 0;
}