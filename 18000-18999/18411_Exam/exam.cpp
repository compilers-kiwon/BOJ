#include    <iostream>

using namespace std;

#define NUM_OF_EXAMS    3
#define INF     0x7FFFFFFF

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum,min_score;

    sum = 0;
    min_score = INF;

    for(int i=1;i<=NUM_OF_EXAMS;i++)
    {
        int score;

        cin>>score;
        sum+=score;min_score=min(min_score,score);
    }

    cout<<sum-min_score<<'\n';

    return  0;
}