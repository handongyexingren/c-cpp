#include <conio.h>
#include <stdio.h>
void gotoxy(int x,int y){
    int i,j;
    for(j=1;j<y;j++){
        printf("\n");
        }
    for(i=1;i<x;i++){
        printf(" ");
    }
}
int sayatxy(char *msg,int x=1,int y=1){
    gotoxy(x,y);
    printf(msg);
}
int main(void){
    sayatxy("default Position");
    printf("\n");
    sayatxy("default Line",30);
    printf("\n");
    sayatxy("Specified",1,2);
    getchar();
    return 0;
}