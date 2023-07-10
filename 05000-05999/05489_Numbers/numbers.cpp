#include    <iostream>

using namespace std;

#define MAX_NUM (10000)

static int  N,X[MAX_NUM+1];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int num;

        cin>>num;
        X[num]++;
    }

    return  0;
}

int solve(void)
{
    int ret,max_num_of_appears;

    max_num_of_appears = 0;

    for(int i=1;i<=MAX_NUM;i++)
    {
        if( X[i] >= max_num_of_appears )
        {
            ret = (X[i]==max_num_of_appears)?min(ret,i):i;
            max_num_of_appears = X[i];
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<solve()<<'\n';

    return  0;
}