#include    <iostream>

using namespace std;

#define NUM_OF_MEMBERS  3
#define NUM_OF_SKILLS   3

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,difficulty[NUM_OF_SKILLS],max_score;

    for(int i=0;i<NUM_OF_SKILLS;i++)
    {
        cin>>difficulty[i];
    }

    cin>>N;
    max_score = 0;

    for(int i=1;i<=N;i++)
    {
        int current_score = 0;

        for(int j=0;j<NUM_OF_MEMBERS;j++)
        {
            for(int k=0;k<NUM_OF_SKILLS;k++)
            {
                int n;

                cin>>n;
                current_score += n*difficulty[k];
            }
        }

        max_score = max(max_score,current_score);
    }

    cout<<max_score<<'\n';

    return  0;
}