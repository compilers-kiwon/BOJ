#include    <iostream>

using namespace std;

#define get_bigger_sum(odd,even) (((odd)==(even))?"TIE":((odd)>(even))?"ODD":"EVEN")

void    get_sum(int n,int& odd,int& even)
{
    for(int i=1;i<=n;i++)
    {
        int num;

        cin>>num;

        if( num%2 == 0 )
        {
            even += num;
        }
        else
        {
            odd += num;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        int k,odd_sum,even_sum;

        cin>>k;
        odd_sum = even_sum = 0;

        get_sum(k,odd_sum,even_sum);
        cout<<get_bigger_sum(odd_sum,even_sum)<<'\n';
    }

    return  0;
}