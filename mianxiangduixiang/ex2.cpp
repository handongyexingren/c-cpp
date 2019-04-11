#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class STACK{
    int  *const  elems;	//申请内存用于存放栈的元素
    const  int   max;	//栈能存放的最大元素个数
    int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
STACK(int m);		//初始化栈：最多m个元素
STACK(const STACK&s); //用栈s拷贝初始化栈
int  size ( ) const;		//返回栈的最大元素个数max
int  howMany ( ) const;	//返回栈的实际元素个数pos
int  getelem (int x) const;	//取下标x处的栈元素
STACK& push(int e); 	//将e入栈,并返回栈
STACK& pop(int &e); 	//出栈到e,并返回栈
STACK& assign(const STACK&s); //赋s给栈,并返回被赋值的栈
void print( ) const;		//打印栈
~STACK( );				//销毁栈
};

STACK::STACK(int m):max(m),elems(new int(m)){
	pos=0;
}
STACK::STACK(const STACK&s):max(s.max),elems(new int(s.max)){
	pos=0;
	for(;pos<)
}
int STACK::size() const{
	return max;
}
int STACK::howMany() const{
	return pos+1;
}
int STACK::getelem(int x) const{
	if(pos<=0){
		cout<<"当前栈为空!\n";
	}
	else if(x>pos){
		cout<<"元素不存在\n";
	}
	else return elems[x-1];
}
STACK&STACK::push(int e){
	if(pos>=max){
		cout<<"栈已满！\n";
	}
	else if{
		elems[pos++]=e;
	}
	return(*this);
}
STACK&STACK::pop(&e){
	if(pos<=0){
		cout<<"栈为空！\n";
	}
	else{
		e=elems[--pos];
	}
	return(*this);
}
STACK& STACK::assign(const STACK&s)	{
	pos=s.pos;
	return(*this);
}
STACK::void print( ) const{
	int i;
	for(i=0;i<pos;i++){
		cout<<elems[i]<<"\n";
		
	}
}
SYACK::~STACK( ){
	delete []elems;
	max=0;
	pos=0;
}
int main(){
	int op;
	int max;
	int i,e,epop,op7,op8;
	cout<<"请输入栈的大小!\n";
	cin>>max;
	STACK s1(max);
	STACK s2(s1);
	cout<<"初始化站成功\n";
	do
	{
		cout<<"请选择要进行的活动：";
		cin>>op;
		switch(op){
			case 1:
			cout<<"栈的大小为："<<s1.size();
			break;
			case 2:
			cout<<"栈中元素个数为："<<s1.howMany();
			break;
			case 3:
			cout<<"请输入要返回元素位次：";
			break;
			cin>>i;
			cout<<s1.getelem(i);
			break;
			case 4:
			cout<<"请输入要压入栈的元素:";
			cin>>e;
			s1.push(e);
			cout<<"压栈成功!";
			break;
			case 5:
			s1.pop(epop);
			cout<<"出栈成功！出栈元素为："<<epop;
			break;
			case 6:
			s2=s2.assign(s1);
			break;
			case 7:
			cout<<"请选择你要打印的栈（输入”1“或”2“）：";
			cin>>op7;
			if(op7==1){
				s1.print();
			}
			else if(op7==2){
				s2.print();
			}
			else printf("输入有误，请输入“1”或“2”!");
			break;
			case 8:
			cout<<"请输入“1”或“2”选择你要销毁的栈";
			cin>>op8;
			if(op8==1){
				s1.~STACK();
			}
			else if(op8==2){
				s2.~STACK();
			}
			else printf("输入有误，请输入“1”或“2”!");
			break;
			default:
			cout<<"输入有误，请输入1~8的数字";
			break;
		}
	}while(op);
	return 0;
}
			
		
			

	
	
	
	
	
	
	
	
	

