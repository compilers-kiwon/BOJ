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
        if( IN_RANGE(N*0,row,N*1) )
        {
            for(int col=0*N;col<3*N;col++) cout<<CHAR;
            for(int col=3*N;col<4*N;col++) cout<<' ';
            for(int col=4*N;col<5*N;col++) cout<<CHAR;
        }

        if( IN_RANGE(N*1,row,N*4) )
        {
            for(int col=0*N;col<1*N;col++) cout<<CHAR;
            for(int col=1*N;col<2*N;col++) cout<<' ';
            for(int col=2*N;col<3*N;col++) cout<<CHAR;
            for(int col=3*N;col<4*N;col++) cout<<' ';
            for(int col=4*N;col<5*N;col++) cout<<CHAR;
        }

        if( IN_RANGE(N*4,row,N*5) )
        {
            for(int col=0*N;col<1*N;col++) cout<<CHAR;
            for(int col=1*N;col<2*N;col++) cout<<' ';
            for(int col=2*N;col<5*N;col++) cout<<CHAR;
        }

        cout<<'\n';
    }

    return  0;
}