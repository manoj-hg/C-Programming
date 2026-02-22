#include<stdio.h>
#include<time.h>
void main(){
int i,j,n=10000;
clock_t start,end;
double cpu_time;
clrscr();
start=clock();
for(i=0;i<n;i++){
for(j=0;j<n;j++){
}
}
end=clock();
cpu_time=((double)(end-start))/CLOCKS_PER_SEC;
printf("Time taken for the nested lops : %f",cpu_time);
getch();
}