#include <stdio.h>
#include <time.h>
int main() {
 int n = 1000000;
 long sum;
 clock_t start, end;
 start = clock();
 sum = n * (n + 1) / 2;
 end = clock();
 clrscr();
 delay(200);
 printf("Formula Method Time: %f seconds\n",
 (double)(end-start)/CLOCKS_PER_SEC);
 return 0;
}