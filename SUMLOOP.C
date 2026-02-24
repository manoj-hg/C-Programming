#include <stdio.h>
#include <time.h>
int main() {
 int n = 1000000,i;
 long sum = 0;
clock_t start, end;
start = clock();
 for(i = 1; i <= n; i++)
 sum += i;
 end = clock();
 printf("Loop Method Time: %f seconds\n",
 (double)(end-start)/CLOCKS_PER_SEC);
 return 0;
}