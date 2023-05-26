#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

#define MAX_NUM_OF_QUEENS   (100000+1)

#define NONE        0   // b00
#define CHECK       1   // b01
#define STALEMATE   2   // b10
#define CHECKMATE   3   // b11
#define MAX_STATE   4   

const static string state_str[MAX_STATE] = {
    "NONE","CHECK","STALEMATE","CHECKMATE"
};

static int  N,K,KR,KC;
static int  QR[MAX_NUM_OF_QUEENS],QC[MAX_NUM_OF_QUEENS];

#define TRUE    1
#define FALSE   0

#define check_bit_pos   0
#define mate_bit_pos    1

#define meet(r1,c1,r2,c2) \
    ((r1)==(r2)||(c1)==(c2)||abs((r1)-(r2))==abs((c1)-(c2)))

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int is_check_state(int row,int col)
{
    for(int i=1;i<=K;i++)
    {
        if( meet(row,col,QR[i],QC[i]) == true )
        {
            return  TRUE;
        }
    }

    return  FALSE;
}

int is_mate_state(int row,int col)
{
    for(int d_row=-1;d_row<=1;d_row++)
    {
        for(int d_col=-1;d_col<=1;d_col++)
        {
            if( d_row==0 && d_col==0 )
            {
                continue;
            }

            if( !IN_RANGE(1,row+d_row,N)
                    || !IN_RANGE(1,col+d_col,N) )
            {
                continue;
            }

            if( is_check_state(row+d_row,col+d_col) == FALSE )
            {
                return  FALSE;
            }
        }
    }

    return  TRUE;
}

int input(void)
{
    cin>>N>>K>>KR>>KC;

    for(int i=1;i<=K;i++)
    {
        cin>>QR[i]>>QC[i];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int state = 0;

    input();

    state |= (is_check_state(KR,KC)<<check_bit_pos); 
    state |= (is_mate_state(KR,KC)<<mate_bit_pos);

    cout<<state_str[state]<<'\n';

    return  0;
}