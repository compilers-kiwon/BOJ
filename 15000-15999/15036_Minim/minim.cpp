#include    <iostream>
#include    <map>

using namespace std;

static map<int,int> length = {
    {0,20000},{1,10000},{2,5000},{4,2500},{8,1250},{16,625}
};

#define get_fraction(n) ((n)%10000)
#define get_integer(n)  ((n)/10000)

int main(void)
{
    int N,sum;

    cin>>N;
    sum = 0;

    for(int i=1;i<=N;i++)
    {
        int code;

        scanf("%d",&code);
        sum += length[code];
    }

    printf("%d",get_integer(sum));
    if(get_fraction(sum)!=0) printf(".%04d",get_fraction(sum));
    puts("");

    return  0;
}