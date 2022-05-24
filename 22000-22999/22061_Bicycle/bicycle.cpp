#include    <iostream>

using namespace std;

bool    add_conis(int one,int two,int sum)
{
    int num_of_used_two_coins = min(sum/2,two);
    int num_of_used_one_coins = min(one,sum-2*num_of_used_two_coins);

    return  (num_of_used_two_coins*2+num_of_used_one_coins==sum);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        
        cin>>a>>b>>c;
        cout<<(add_conis(a,b,c)?"YES":"NO")<<'\n';
    }

    return  0;
}