#include    <iostream>
#include    <string>

using namespace std;

#define chr2int(c) (int)((c)-'0')

void    simulate(const string& rec,int& A_score,int& B_score)
{
    for(int i=0;i<rec.length();i+=2)
    {
        char    player = rec[i+0];
        char    score = rec[i+1];

        if( player == 'A' )
        {
            A_score += chr2int(score);
        }
        else
        {
            B_score += chr2int(score);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  r;
    int     A_score,B_score;

    cin>>r;
    A_score = B_score = 0;

    simulate(r,A_score,B_score);
    cout<<(A_score>B_score?'A':'B')<<'\n';

    return  0;
}