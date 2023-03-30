#include <stdio.h>
 
int nums[10], i, j;
 
void f();
void print();
 
void f(){
    ++j;
    print();
    if(nums[j]<0)printf("%d ", nums[j]);
    ++j;
}
 
void print(){
    if(nums[j]>0){
        printf("%d ", nums[j]);
        f();
    }
    else if(nums[j]<0){
        f();
    }
    else {
        j=0;
    }
}
 
int main(){
    for (i=0; i<10; i++){
        scanf("%d", &nums[i]);
    }
    print();
    return 0;
}