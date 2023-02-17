#include    <iostream>

using namespace std;

#define INF                 0x7FFFFFFF
#define get_num_of_two(n,f) (((n)-(f)*5)/2)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,min_num_of_coins;

    cin>>n;
    min_num_of_coins = INF;

    for(int num_of_five=0;num_of_five*5<=n;num_of_five++)
    {
        if( (n-(num_of_five*5))%2 != 0 )
        {
            continue;
        }

        min_num_of_coins = min(min_num_of_coins,
                num_of_five+get_num_of_two(n,num_of_five));
    }

    min_num_of_coins = 
        (min_num_of_coins==INF)?-1:min_num_of_coins;
    
    cout<<min_num_of_coins<<'\n';

    return  0;
}