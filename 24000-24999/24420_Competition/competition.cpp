#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,sum,min_score,max_score;

    cin>>N;
    sum = 0;

    min_score = 100;
    max_score = 0;

    for(int i=1;i<=N;i++)
    {
        int A;

        cin>>A;
        sum += A;

        min_score = min(min_score,A);
        max_score = max(max_score,A);
    }

    cout<<sum-(min_score+max_score)<<'\n';

    return  0;
}