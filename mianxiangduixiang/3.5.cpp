#include <stdio.h>
union LONG{
    unsigned int x;
    unsigned long y;
    unsigned GetLow();
    LONG(unsigned long);
};
LONG::LONG(unsigned long z){
    y=z;
}
unsigned LONG::GetLow(){
    return x;
}
int main(void){
    unsigned long dw=0x7654321L;
    LONG wd(0x1234567L);
    printf("%x\n",wd.GetLow());
    printf("%x\n",LONG(dw).GetLow());
    printf("%x\n",LONG(0x76L).GetLow());
    getchar();
    return 0;
}