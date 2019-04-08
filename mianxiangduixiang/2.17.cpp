#include <dos.h>
#include <iostream>
#include <stdio.h>
long GetTime(int &hours,int &minutes,int &seconds){
    struct time t;
    gettime(&t);
    hours=t.ti_hour;
    minutes=t.ti_min;
    seconds=t.ti_sec;
    return(long)t.ti_hour*3600+t.ti_minutes*60+t.ti_seconds;
}
int main(void){
    int h,m,s;
    cout<<"now is"<<GetTime(h,m,s)<<"seconds from midnight,"<<"or"<<h<<":"<<m<<":"<<s<<'\n';
    getchar();
    return 0;
}