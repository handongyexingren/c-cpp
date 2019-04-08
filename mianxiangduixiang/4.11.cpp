#include <conio.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

class ACCOUNT{
    char password[10];
    int salary,balance;
    public:
        char name[10];
        int ACCOUNT::*get(char *item,char*pswd);    //返回类型为，指针，指向的是类中的int类型的成员
        ACCOUNT(char *name,char *pswd,int salary,int balance);
};
ACCOUNT::ACCOUNT(char *name,char *pswd,int salary,int balance){
    strcpy(ACCOUNT::name,name);
    strcpy(password,pswd);
    ACCOUNT::salary=salary;
    ACCOUNT::balance=balance;
}
int ACCOUNT::*ACCOUNT::get(char *item,char *pswd){   //首先声明，get是ACCOUNT的成员函数，返回类型为指向ACCOUNT中int类型的指针
    if(stricmp(pswd,password)){   //密码对了，表达式值为0；这个password是类中的private,可以被get使用
        return 0;   //密码不符，退出
    }
    if(stricmp(item,"salary")==0){
        return &ACCOUNT::salary;
    }
    if(stricmp(item,"balance")==0){
        return &ACCOUNT::balance;
    }
    return 0;
}
char *getpswd(const char *name){    //返回一个指针
    int i=0;
    static char pswd[10];
    std::cout<<
    name<<",please input your password:";
    while(((pswd[i]=getch()))!='\r'){
        if(i<9){
            i++;
        }
    }
    pswd[i]=0;
    std::cout<<"\n\n";
    return pswd;    //返回输入的密码地址
}
ACCOUNT yang("Yang","123456789",2000,20000);
ACCOUNT wang("Wang","abcdefghi",1000,10000);
int main(void){
    ACCOUNT *y=&yang;
    char *pswd=getpswd(yang.name);      //外部的变量pswd被屏蔽了
    int ACCOUNT::*p;    //定义了一个成员指针
    p=y->get("balance",pswd);   //如果密码是正确的，则可以读出余额     这个不用加   y->(yang.)get()
    if(p==0){
        std::cout<<"密码或者查询项目不存在！\n";
        return 0;
    }
    std::cout<<"your balance"<<y->*p<<std::endl;   
    std::cout<<"your salary"<<y->*yang.get("salary",pswd)<<std::endl;    //不能写成 y->*get()   得加上yang.
    pswd=getpswd(wang.name);
    std::cout<<"your balance"<<wang.*wang.get("balance",pswd)<<std::endl;
    std::cout<<"your salary"<<wang.*wang.get("salary",pswd)<<std::endl;    //取内容
    getchar();
    return 0;
}