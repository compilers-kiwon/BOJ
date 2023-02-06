#include    <iostream>

using namespace std;

#define CHAR        '@'
#define CELL_SIZE   5

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int row=0;row<N*CELL_SIZE;row++)
    {
        if( IN_RANGE(N*1,row,N*2) || IN_RANGE(N*3,row,N*4) )
        {
            for(int col=0;col<5*N;col++) cout<<CHAR;
        }
        else
        {
            for(int col=0;col<N;col++) cout<<CHAR;
            for(int col=N;col<4*N;col++) cout<<' ';
            for(int col=4*N;col<5*N;col++) cout<<CHAR;
        }

        cout<<'\n';
    }

    return  0;
}