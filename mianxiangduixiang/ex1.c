#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define FALSE 0
#define TRUE 1
#define OK 1

/*typedef struct STACK{
    int  *elems;	//�����ڴ����ڴ��ջ��Ԫ��
    int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;	//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
}stack,*L;
void initSTACK(STACK *const p, int m);	//��ʼ��pָ���ջ�����m��Ԫ��
void initSTACK(STACK *const p, const STACK&s); //��ջs��ʼ��pָ���ջ
int  size (const STACK *const p);		//����pָ���ջ�����Ԫ�ظ���max
int  howMany (const STACK *const p);	//����pָ���ջ��ʵ��Ԫ�ظ���pos
int  getelem (const STACK *const p, int x);	//ȡ�±�x����ջԪ��
STACK *const push(STACK *const p, int e); 	//��e��ջ��������p
STACK *const pop(STACK *const p, int &e); 	//��ջ��e��������p
STACK *const assign(STACK*const p, const STACK&s); //��s��pָ��ջ,������p
void print(const STACK*const p);			//��ӡpָ���ջ
void destroySTACK(STACK*const p);		//����pָ���ջ  */
int main(int argc, char* argv[])
{
printf("\n--------************************---------\n\n");
printf("\t 1.��ʼ��ջ           2.���Ԫ��\n");
printf("\t 3.���Ԫ�ظ���       4.ʵ��Ԫ�ظ���\n");
printf("\t 5.ȡԪ��             6.��ջ\n");
printf("\t 7.��ջ               8.assign\n"); 
printf("\t 9.����ջ");
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
