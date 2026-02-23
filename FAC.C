#include <stdio.h>
#include <time.h>
long factorial(int n) {
 if(n == 0)
 return 1;
 return n * factorial(n - 1);
}
int main() {
 int n = 20;
 clock_t start, end;
 double cpu_time;
 clrscr();
 start = clock();
 factorial(n);
end = clock();
delay(200);
 cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
 printf("Time taken for recursive factorial: %f seconds\n", cpu_time);
 return 0;
}