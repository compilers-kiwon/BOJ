#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

bool    is_jolly(int size)
{
    bool            ret = true;
    vector<int>     numbers;
    vector<bool>    table(size,false);

    for(int i=1;i<=size&&ret!=false;i++)
    {
        int n;

        scanf("%d",&n);

        if( !numbers.empty() )
        {
            int diff = abs(numbers.back()-n);

            if( !IN_RANGE(1,diff,size-1) || table[diff]==true )
            {
                ret = false;
            }

            table[diff] = true;
        }

        numbers.push_back(n);
    }

    for(int tmp;numbers.size()!=size;)
    {
        scanf("%d",&tmp);
        numbers.push_back(tmp);
    }

    return  ret;
}

int     main(void)
{
    for(int n;scanf("%d",&n)!=EOF;)
    {
        puts(is_jolly(n)?"Jolly":"Not jolly");
    }

    return  0;
}