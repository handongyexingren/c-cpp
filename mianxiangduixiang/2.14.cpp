#include <stdio.h>
char *&weekday(int &day){
    static char *week[7]={"Sun","Man","The","Wed","Thu","Fri","Sat"};//week为一个二维数组，一维元素为为一个字符指针，二维元素为char
    return week[day++];
}
int main(void){
    int day=0;
    printf(weekday(day));//weekday(day),a point to a string
    weekday(day)="Mon";//将指针元素替换为，指向“Mon”的指针
    printf(weekday(day));//用右值给引用，生成匿名变量
    printf(weekday(day=0));
    *(weekday(day)+1)='u'; 
    getchar();
}