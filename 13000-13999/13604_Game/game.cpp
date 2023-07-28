#include    <iostream>

using namespace std;

#define MAX_NUM_OF_PLAYERS  (500+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int J,R,winner,max_score;
    int score[MAX_NUM_OF_PLAYERS] = {0,};
    
    cin>>J>>R;
    max_score = -1;

    for(int r=1;r<=R;r++)
    {
        for(int j=1;j<=J;j++)
        {
            int n;

            cin>>n;
            score[j] += n;

            if( score[j] >= max_score )
            {
                max_score = score[j];
                winner = j;
            }
        }
    }

    cout<<winner<<'\n';
    return  0;
}