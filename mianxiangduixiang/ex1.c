#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
int FALSE=-1;
int OK=1;

typedef int elemtype;
typedef struct STACK{
    int  *elems;	//�����ڴ����ڴ��ջ��Ԫ��
    int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;	//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
}STACK,stack,*L;
int initSTACK(STACK *const p, int m);	//��ʼ��pָ���ջ�����m��Ԫ��
int initSTACK(STACK *const p, const STACK *s); //��ջs��ʼ��pָ���ջ
int  size (const STACK *const p);		//����pָ���ջ�����Ԫ�ظ���max
int  howMany (const STACK *const p);	//����pָ���ջ��ʵ��Ԫ�ظ���pos
int  getelem (const STACK *const p, int x);	//ȡ�±�x����ջԪ��
STACK *const push(STACK *const p, int e); 	//��e��ջ��������p
STACK *const pop(STACK *const p, int *e); 	//��ջ��e��������p
STACK *const assign(STACK*const p, const STACK&s); //��s��pָ��ջ,������p
int print(const STACK*const p);			//��ӡpָ���ջ
void destroySTACK(STACK*const p);		//����pָ���ջ  
int main(){
        stack q,s;
        L p=&q,r=&s;
        p->max=0;
        p->pos=0;
        r->max=0;
        r->pos=0;
        int op=1;
        while(op){
                system("cls");
                printf("--------************************---------\n");
                printf("\t 1.��ʼ��ջ           2.���Ԫ��\n");
                printf("\t 3.���Ԫ�ظ���        4.ʵ��Ԫ�ظ���\n");
                printf("\t 5.ȡԪ��             6.��ջ\n");
                printf("\t 7.��ջ               8.assign\n"); 
                printf("\t 9.��ӡջ             10.����ջ\n");
                scanf("%d",&op);
        switch(op){
                case 1:
                int m;
                printf("������ջ��С��");
                scanf("%d",&m);
                if(initSTACK(p,m)==OK){
                        printf("ջ��ʼ���ɹ���\n");
                }
                else printf("ջ��ʼ��ʧ�ܣ�\n");
                getchar();getchar();
                break;
                case 2:
                break;
                case 3:
                int siz;
                if((siz=size(p))==FALSE){
                        printf("���ʼ��ջ��");
                        getchar();getchar();
                        break;
                }
                else printf("ջ�����������Ԫ�ظ���Ϊ%d",siz);
                getchar();getchar();
                break;
                case 4:
                int hwm;
                if((hwm=howMany(p))==FALSE){
                        printf("���ʼ��ջ��");
                        getchar();getchar();
                        break;
                }
                else {
                        printf("ջ�й���%d��Ԫ��",hwm);
                }
                getchar();getchar();
                break;
                case 5:
                int i;
                int glm;
                printf("�������������Ԫ�ش���");
                scanf("%d",&i);
                if((glm=getelem(p,i))==FALSE){
                        printf("�ô�����������ڻ���ջδ��ʼ����");
                        getchar();getchar();
                        break;
                }
                else {
                        printf("��%d��Ԫ��ֵΪ��%d",i,glm);
                }
                getchar();getchar();
                break;
                case 6:
                int e;
                scanf("%d",&e);
                if(push(p,e)==ERROR){
                        printf("ջ�����޷���ջ��");
                        getchar();getchar();
                        break;
                }
                else{
                        printf("������Ҫ��ջ��Ԫ�أ�");
                        printf("��ջ�ɹ���");
                }
                getchar();getchar();
                break;
                case 7:
                int o;
                if(pop(p,&o)==ERROR){   //����FLASE,����Ϊpop��������Ͳ���Ϊint��
                        printf("ջ�գ��޷���ջ��");
                        getchar();getchar();
                        break;
                }
                else{
                        printf("��ջ�ɹ�����ջԪ��Ϊ��%d",o);
                        }
                getchar();getchar();
                break;
                case 8:
                break;
                case 9:
                if(print(p)==FALSE){
                        printf("���ʼ��ջ��");
                        getchar();getchar();
                        break;
                }
                getchar();getchar();
                break;
                case 10:
                destroySTACK(p);
                printf("ջ���ٳɹ���");
        }//switch
        }//while
        getchar();
        return 0;
}
int initSTACK(STACK *const p, int m){
        p->elems=(elemtype*)malloc(m*sizeof(elemtype));
        if(!p->elems){
                exit(FALSE);
        }
        p->max=m;
        p->pos=0;
        return OK;
}
int initSTACK(STACK *const p, const STACK&s){
        p->elems=(elemtype*)malloc((s.max)*sizeof(elemtype));
        p->max=s.max;
        p->pos=0;
        for(int i=0;i <= s.pos;(p->pos)++){
                p->elems[i]=s.elems[i];
        }
        return OK;
}
int  size (const STACK *const p){
        if(!(p->max)){
        return FALSE;}
        else{
        return p->max;
        }
}
int  howMany (const STACK *const p){
        printf("%d",p->max);
        if(!(p->max)){
                return FALSE;}
        else{
        return p->pos;
        }
}
int  getelem (const STACK *const p, int x){
        if(x<1||x>p->pos||!(p->max)){     //������������±�Ϊ���Ԫ����Ϊ��һ��Ԫ�أ����x���Ե���pos
        return FALSE;}
        else{
                return (*(p->elems+x-1));
        }
}
STACK *const push(STACK *const p, int e){
        if((p->pos)>=(p->max)){  //max  is 1...n,while pos is 0...n-1
                return ERROR;
        }
        else {
                *(p->elems+(p->pos)++)=e;
        return p;
        }
 }
STACK *const pop(STACK *const p, int *e){
        if(p->pos<1){
        return ERROR;}
        else{
                *e=*(p->elems+(--(p->pos)));
        }
        return p;
}
/*STACK *const assign(STACK*const p, const STACK* s){
        if(p->elems==0){
                p->elems=(elemtype*)malloc((s.max)*sizeof(elemtype));
        }
        p=&s;
        return p;
}*/
int print(const STACK*const p){
        if(p){
        for(int i=0;i<p->pos;i++){
                printf("%d",*(p->elems+i));
        }
        }
        else{
        return FALSE;}
}
void destroySTACK(STACK*const p){
        free(p->elems);
        p->elems=NULL;
        p->max=0;
        p->pos=0;
}

//---------------------------------------------------------------------------
