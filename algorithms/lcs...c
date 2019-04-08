#include <stdio.h>
#include <stdlib.h>

#define max 100

static int c[max][max];
static char b[max][max];

LCS_LENGTH(char *X,char *Y,int m,int n){
    int i,j;
    for(i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(j=0;j<=n;j++){
        c[0][j]=0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(X[i]==Y[i]){      //如果末尾两个字母相同，则转化为求其子问题
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
PRINT_LCS(char B[][max],char *X,int m,int n){
    if(m==0||n==0){
        return 0;
    }
    if(b[m][n]=='s'){
        PRINT_LCS(b,X,m-1,n-1);
        printf("%c",X[m]);
    }
    else if(b[m][n]=='u'){
        PRINT_LCS(b,X,m-1,n);
    }
    else PRINT_LCS(b,X,m,n-1);
    }
int main(int argc, char *argv[]) {
    int m,n;
    printf("请输入大写字母序列X的长度：");
    scanf("%d",&m);
    printf("请输入大写字母序列Y的长度：");
    scanf("%d",&n);
    char X[max],Y[max];
    int x,y;
    printf("请依次输入X序列的%d个元素：",m);
    for(x=1;x<m+1;x++){
        scanf("%c",X+x);
    }
    printf("请依次输入Y序列的%d个元素：",n);
    for(y=1;y<n+1;y++){
        scanf("%c",Y+y);
    }
    LCS_LENGTH(X,Y,m,n);
    printf("最大子序列长度为：%d",c[m][n]);
    PRINT_LCS(b,X,m,n);
    
    getchar();
    return 0;
}