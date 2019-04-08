#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1
#define OK 1

/*typedef struct STACK{
    int  *elems;	//申请内存用于存放栈的元素
    int   max;	//栈能存放的最大元素个数
    int   pos;	//栈实际已有元素个数，栈空时pos=0;
}stack,*L;
void initSTACK(STACK *const p, int m);	//初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, const STACK&s); //用栈s初始化p指向的栈
int  size (const STACK *const p);		//返回p指向的栈的最大元素个数max
int  howMany (const STACK *const p);	//返回p指向的栈的实际元素个数pos
int  getelem (const STACK *const p, int x);	//取下标x处的栈元素
STACK *const push(STACK *const p, int e); 	//将e入栈，并返回p
STACK *const pop(STACK *const p, int &e); 	//出栈到e，并返回p
STACK *const assign(STACK*const p, const STACK&s); //赋s给p指的栈,并返回p
void print(const STACK*const p);			//打印p指向的栈
void destroySTACK(STACK*const p);		//销毁p指向的栈  */
int main(int argc, char* argv[])
{
printf("\n--------************************---------\n\n");
printf("\t 1.初始化栈           2.最大元素\n");
printf("\t 3.最大元素个数       4.实际元素个数\n");
printf("\t 5.取元素             6.入栈\n");
printf("\t 7.出栈               8.assign\n"); 
printf("\t 9.销毁栈");
        return 0;
}
void initSTACK(STACK *const p, int m){
        p=(L)malloc(m*sizeof(int));
        *p.max=m;
        *p.pos=0;
        if(p){
        return OK;}
        else{
        return FALSE;}
}
void initSTACK(STACK *const p, const STACK&s);{
        p=s.elmes;
        *p.max=s.max;
        *p.pos=s.pos;
        if(p==s.elmes){
        return OK;}
        else{
        return FALSE;
        }
}
int  size (const STACK *const p){
        if(p!=FALSE){
        return FALSE;}
        else{
        return *p.max;
        }
}
int  howMany (const STACK *const p){
        if(p!=FALSE){
        return FALSE;}
        else{
        return *p.pos;
        }
}
int  getelem (const STACK *const p, int x){
        if(x>pos){
        return FALSE;}
        else{
        L q=p;
        int i=1;
        for(;i<x;i++){
                q.elmes++;
                }
                return *q.elmes;
                }
}
STACK *const push(STACK *const p, int e){
        int i;
        L q;
        q=p;
        if(p.pos>=p.max){
        return FALSE;}
        else {
        for(i=1;i<=p.pos;i++){
        q.elmes++;}
        *(q.elmes)=e;
        p.pos++;
        }
        return p;
 }
STACK *const pop(STACK *const p, int &e){
        int i;
        L q;
        q=p;
        if((*p).pos<1){
        return FALSE;}
        else(
        for(i=1;i<(*p).pos;i++){
        (*q).elmes++;}
        *e=*(q.elmes);
        p.pos--;
        }
        return p;
}
STACK *const assign(STACK*const p, const STACK&s){
        p=&s;
        int i;
        for(i=1;i<=s.pos;i++){
        ((*p).elmes)++=s.elmes++;}
        (*p).max=s.max;
        (*p).pos=s.pos;
        return p;
}
void print(const STACK*const p){
        int i;
        if(!p){
        for(i=1;i<=(*p).pos;i++){
        printf("%d",*(*p).elmes);
        (*p).elmes++;
        }
        else{
        return FALSE;}
}
void destroySTACK(STACK*const p)

//---------------------------------------------------------------------------
