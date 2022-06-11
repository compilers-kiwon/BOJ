#include    <iostream>

using namespace std;

#define MAX_NUM         1000000000000000
#define TARGET_NUMBER   5
#define get_digit(n,b)  (((n)/(b))%10)

typedef long long int   int64;

int get_num_of_target_number(int64 n)
{
    int ret = 0;

    for(;n>0;n/=10)
    {
        if( n%10 == TARGET_NUMBER )
        {
            ret++;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   N,num;
    int     K;

    cin>>N>>K;
    num = N;

    for(int64 base=1;;base*=10)
    {
        if( num>N && get_num_of_target_number(num)>=K )
        {
            break;
        }

        int64   d = get_digit(num,base);

        if( d == TARGET_NUMBER )
        {
            continue;
        }
        else
        {
            if( d < TARGET_NUMBER )
            {
                num += (TARGET_NUMBER-d)*base;
            }
            else
            {
                num += (10+TARGET_NUMBER-d)*base;
            }
        }
    }

    if( get_num_of_target_number(num) > K )
    {
        int64   base;

        for(base=MAX_NUM;num/base==0;base/=10);

        for(;base!=0;base/=10)
        {
            int64 tmp;

            if( get_digit(num,base) == TARGET_NUMBER )
            {
                tmp = num-base*TARGET_NUMBER;

                if( tmp > N )
                {
                    num = tmp;
                    break;
                }
            }
        }
    }

    cout<<num<<'\n';

    return  0;
}