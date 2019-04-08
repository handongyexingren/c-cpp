#include <iostream>
#include <stdio.h>
int main(void){
    class RANDOM{
        int x;
        public:
        int random(){
            return x=(23*x+19)%101;
        }
        RANDOM(int s){
            x=s;
        }
    };
    int x=0;
    RANDOM r(x+1);
    for(x=0;x<10;x++){
        std::cout<<r.random()<<'\n';
    }
    getchar();
    return 0;
}