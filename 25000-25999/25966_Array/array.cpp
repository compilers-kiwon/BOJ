#include    <iostream>

using namespace std;

#define MAX_SIZE    3000

static int  N,M,q,arr[MAX_SIZE][MAX_SIZE],row_table[MAX_SIZE];

int init(void)
{
    cin>>N>>M>>q;

    for(int row=0;row<N;row++)
    {
        for(int col=0;col<M;col++)
        {
            cin>>arr[row][col];
        }

        row_table[row] = row;
    }

    return  0;
}

int simulate(void)
{
    for(;q>0;q--)
    {
        int op,i,j,k;

        cin>>op>>i>>j;

        if( op == 0 )
        {
            cin>>k;
            arr[row_table[i]][j] = k;
        }
        else    // op == 1
        {
            swap(row_table[i],row_table[j]);
        }
    }

    return  0;
}

int print(void)
{
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<M;col++)
        {
            cout<<arr[row_table[row]][col]<<' ';
        }

        cout<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    simulate();
    print();

    return  0;
}