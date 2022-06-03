#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    int64   prev_weight,sum_of_weight_loss,max_weight_loss;

    cin>>n;
    prev_weight = sum_of_weight_loss = max_weight_loss = 0;

    for(int i=1;i<=n;i++)
    {
        int64   w;

        cin>>w;

        if( w >= prev_weight )
        {
            max_weight_loss = max(max_weight_loss,sum_of_weight_loss);
            sum_of_weight_loss = 0;
        }
        else
        {
            sum_of_weight_loss += prev_weight-w;
        }

        prev_weight = w;
    }

    cout<<max(max_weight_loss,sum_of_weight_loss)<<'\n';

    return  0;
}