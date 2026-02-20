#include<stdio.h>
#include<time.h>
void main(){
int i,n;
clock_t start,end;
double cpu_time;
clrscr();
start=clock();
for(i=0;i<n;i++)
end=clock();
cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("Time taken for a loop Statement: %f",cpu_time);
getch();
}