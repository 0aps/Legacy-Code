#include <stdio.h>
#include <math.h>

#define N 100

int main(void){
    int n=N*log(N/3),a[n],ca=0,i,j;
    for(i = 0; i < n; i++)
        a[i] = 0;
    a[n-1] = 1;
    for(i = 1; i <= N; i++)
        {
        for(j = n - 1; j >= 0; j--){
            ca = i * a[j] + ca;
            a[j] = ca % 10;
            ca /= 10;
        }
        ca = 0;
    }
    ca = 0;
    for(i = 0; i < n; i++)
        ca += a[i];
    printf("%d\n",ca);
    return 0;
}
