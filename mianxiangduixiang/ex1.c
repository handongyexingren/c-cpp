#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define ERROR 0
int FALSE=-1;
int OK=1;

typedef int elemtype;
typedef struct STACK{
    int  *elems;	//申请内存用于存放栈的元素
    int   max;	//栈能存放的最大元素个数
    int   pos;	//栈实际已有元素个数，栈空时pos=0;
}STACK,stack,*L;
int initSTACK(STACK *const p, int m);	//初始化p指向的栈：最多m个元素
int initSTACK(STACK *const p, const STACK *s); //用栈s初始化p指向的栈
int  size (const STACK *const p);		//返回p指向的栈的最大元素个数max
int  howMany (const STACK *const p);	//返回p指向的栈的实际元素个数pos
int  getelem (const STACK *const p, int x);	//取下标x处的栈元素
STACK *const push(STACK *const p, int e); 	//将e入栈，并返回p
STACK *const pop(STACK *const p, int *e); 	//出栈到e，并返回p
STACK *const assign(STACK*const p, const STACK&s); //赋s给p指的栈,并返回p
int print(const STACK*const p);			//打印p指向的栈
void destroySTACK(STACK*const p);		//销毁p指向的栈  
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
                printf("\t 1.初始化栈           2.最大元素\n");
                printf("\t 3.最大元素个数        4.实际元素个数\n");
                printf("\t 5.取元素             6.入栈\n");
                printf("\t 7.出栈               8.assign\n"); 
                printf("\t 9.打印栈             10.销毁栈\n");
                scanf("%d",&op);
        switch(op){
                case 1:
                int m;
                printf("请输入栈大小：");
                scanf("%d",&m);
                if(initSTACK(p,m)==OK){
                        printf("栈初始化成功！\n");
                }
                else printf("栈初始化失败！\n");
                getchar();getchar();
                break;
                case 2:
                break;
                case 3:
                int siz;
                if((siz=size(p))==FALSE){
                        printf("请初始化栈！");
                        getchar();getchar();
                        break;
                }
                else printf("栈允许存入的最大元素个数为%d",siz);
                getchar();getchar();
                break;
                case 4:
                int hwm;
                if((hwm=howMany(p))==FALSE){
                        printf("请初始化栈！");
                        getchar();getchar();
                        break;
                }
                else {
                        printf("栈中共有%d个元素",hwm);
                }
                getchar();getchar();
                break;
                case 5:
                int i;
                int glm;
                printf("请输入想输出的元素次序：");
                scanf("%d",&i);
                if((glm=getelem(p,i))==FALSE){
                        printf("该次序的数不存在或者栈未初始化！");
                        getchar();getchar();
                        break;
                }
                else {
                        printf("第%d个元素值为：%d",i,glm);
                }
                getchar();getchar();
                break;
                case 6:
                int e;
                scanf("%d",&e);
                if(push(p,e)==ERROR){
                        printf("栈满，无法入栈！");
                        getchar();getchar();
                        break;
                }
                else{
                        printf("请输入要入栈的元素：");
                        printf("入栈成功！");
                }
                getchar();getchar();
                break;
                case 7:
                int o;
                if(pop(p,&o)==ERROR){   //不用FLASE,是因为pop的输出类型不能为int型
                        printf("栈空，无法出栈！");
                        getchar();getchar();
                        break;
                }
                else{
                        printf("出栈成功，出栈元素为：%d",o);
                        }
                getchar();getchar();
                break;
                case 8:
                break;
                case 9:
                if(print(p)==FALSE){
                        printf("请初始化栈！");
                        getchar();getchar();
                        break;
                }
                getchar();getchar();
                break;
                case 10:
                destroySTACK(p);
                printf("栈销毁成功！");
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
        if(x<1||x>p->pos||!(p->max)){     //这里把数组中下表为零的元素作为第一个元素，因此x可以等于pos
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
