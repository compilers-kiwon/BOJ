#include    <iostream>

using namespace std;

#define SEC_PER_MINUTE  (60)
#define SEC_PER_HOUR    (60*SEC_PER_MINUTE)
#define SEC_PER_DAY     (24*SEC_PER_HOUR)

int get_time(void)
{
    int hh,mm,ss;

    scanf("%d:%d:%d",&hh,&mm,&ss);
    return  hh*SEC_PER_HOUR+mm*SEC_PER_MINUTE+ss;
}

int get_available_time(int s,int e)
{
    int ret;

    if (s == e) ret=SEC_PER_DAY;
    else if (s < e) ret=e-s;
    else ret=SEC_PER_DAY-s+e;

    return  ret;
}

int simulate(int s_time,int e_time,int t)
{
    int available_time = get_available_time(s_time,e_time);

    if (t <= available_time) puts("Perfect");
    else if (t <= available_time+SEC_PER_HOUR) puts("Test");
    else puts("Fail");

    return  0;
}

int main(void)
{
    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        int S,F,k;

        S = get_time();
        F = get_time();
        scanf("%d",&k);

        simulate(S,F,k*SEC_PER_MINUTE);
    }

    return  0;
}