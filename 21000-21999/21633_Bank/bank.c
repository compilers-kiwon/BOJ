#include    <stdio.h>

#define SCALER              100
#define MIN_COMMISSION      (100*SCALER)
#define MAX_COMMISSION      (2000*SCALER)
#define DEFAULT_COMMISSION  (25*SCALER)

#define min(a,b)    (((a)<(b))?(a):(b))
#define max(a,b)    (((a)>(b))?(a):(b))

int main(void)
{
    int k,c;

    scanf("%d",&k);

    c = k+DEFAULT_COMMISSION;
    c = max(MIN_COMMISSION,min(MAX_COMMISSION,c));
    
    printf("%d.%02d\n",c/SCALER,c%SCALER);

    return  0;
}