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
        if( IN_RANGE(N*0,row,N*1) || IN_RANGE(N*2,row,N*3) || IN_RANGE(N*4,row,N*5) )
        {
            for(int col=0;col<5*N;col++) cout<<CHAR;
        }
        else
        {
            for(int col=0;col<N;col++) cout<<CHAR;
        }

        cout<<'\n';
    }

    return  0;
}