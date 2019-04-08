#include <stdlib.h>
#define STEP 5
using namespace std;
/**low,high are the index of the array.The smallest low is 0,the largest high is LENGTH_A-1**/
int MEDIAN(int *A,int low,int high){
    /**how to get the mean? ,
    ***1.Divide the A to some sub_array, 5 is a group, the last which's number below 5 is also considered a group;
    ***2.Sort every group, get the MID of every group, get a new array;
    ***3.From the new array, we can get the MID;
    **/
    int length=high-low+1;
    int last_array_length=length%5;
    int array_num=(last_array_length==0) ? (length/5):(length/5+1);
    int first_mids[array_num]={0};

    int num=0;
    int sub[5]={0};//5
    for(int i=low;i<=high-last_array_length;i+=5){
            /**save(copy) the sub array,the sub length is 5**/
            for(int j=0,k=i;j<=4;j++,k++){
                sub[j]=A[k];
            }
            /**use the INSERTION_SORT from "Sort.hpp"**/
            INSERTION_SORT(sub,5);
            first_mids[num++]=sub[2];
    }
    /**consider that the length of A is 4 or 13,last_array_length is 4 or 3**/
    if(last_array_length!=0){
        for(int j=0,k=high-last_array_length+1;j<=last_array_length-1;j++,k++){
            sub[j]=A[k];
        }
        INSERTION_SORT(sub,last_array_length);
        first_mids[num]=sub[last_array_length/2];
    }
    INSERTION_SORT(first_mids,array_num);
    return first_mids[array_num/2];
}
/**just as the QUICKSORT, this is a partition function**/
/**return a mid location**/
int PARTION(int *A,int low,int high,int mid){
    int i=low;
    for(;i<=high;i++){
        if(A[i]==mid) break;
    }
    int temp=A[low];
    A[low]=A[i];
    A[i]=temp;
    while(low<high){
        while(high>low&&A[high]>=mid) high--;
        A[low]=A[high];
        while(low<high&&A[low]<=mid) low++;
        A[high]=A[low];
    }
    A[low]=mid;
    return low;
}
int SELECT(int *A,int low,int high,int i){
    if(low==high){
        return A[low];
    }
    int mid_value=MEDIAN(A,low,high);
    int mid_location=PARTION(A,low,high,mid_value);
    int k=mid_location-low+1;
    if(i==k){
        return A[mid_location];
    }else if(i<k){
        return SELECT(A,low,mid_location-1,i);
    }else{
        return SELECT(A,mid_location+1,high,i-k);
    }
}