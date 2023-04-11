#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  N,M,X[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_num_of_stores;

    cin>>N>>M;
    max_num_of_stores = 0;

    for(int i=1;i<=N;i++)
    {
        int S;

        cin>>S;
        max_num_of_stores = 
            max(max_num_of_stores,++X[S]);
    }

    cout<<max_num_of_stores<<'\n';
    return  0;
}