#include    <iostream>

using namespace std;

int collect_entry_fee(int num_of_people,int fee_of_each_person)
{
    int ret = 0;

    for(int i=1;i<=num_of_people;i++)
    {
        int A;

        cin>>A;
        ret += min(fee_of_each_person,A);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int N,M,sum;

        cin>>N>>M;

        if( N==0 && M==0 )
        {
            break;
        }

        sum = collect_entry_fee(N,M/N);
        cout<<sum<<'\n';
    }

    return  0;
}