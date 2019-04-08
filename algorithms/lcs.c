#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

static int c[max][max];
static char b[max][max];   //将c,b定义为静态数组，这样可以在多个函数中共享 

 void LCS_LENGTH(char *X,char *Y,int m,int n){
    int i,j;
    for(i=1;i<=m;i++){
        c[i][0]=0;
    }
    for(j=0;j<=n;j++){
        c[0][j]=0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){      //如果末尾两个字母相同，则转化为求其子问题
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='s';         //用字母s代替斜向上的箭头
            }
            else if(c[i-1][j]>=c[i][j-1]){    //取各自子序列较长的那个
                    c[i][j]=c[i-1][j];
                    b[i][j]='u';   //用up的首字母代替向上的箭头
                }
            else {
                    c[i][j]=c[i][j-1];
                    b[i][j]='l'; //用left  的首字母代替向左的箭头
                } 
        }
    }
}
void PRINT_LCS(char *X,int m,int n){
    if(m==0||n==0){
        return;
    }
    if(b[m][n]=='s'){
        PRINT_LCS(X,m-1,n-1);
        printf("%c",X[m-1]);
    }
    else if(b[m][n]=='u'){
        PRINT_LCS(X,m-1,n);
    }
    else PRINT_LCS(X,m,n-1);
    }
int main(int argc, char *argv[]) {
    int m,n;
    char X[max],Y[max];
    int x,y;
    printf("请依次输入X序列:\n");
    	gets(X);
    printf("请依次输入Y序列：\n");
     	gets(Y);
    m=strlen(X);
    n=strlen(Y);
    LCS_LENGTH(X,Y,m,n);
    printf("最大子序列长度为：%d\n",c[m][n]);
    PRINT_LCS(X,m,n);
    
    getchar();
    return 0;
}