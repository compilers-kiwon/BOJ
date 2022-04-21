#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A_score,B_score;

    cin>>N;
    A_score = B_score = 0;

    for(int i=1;i<=N;i++)
    {
        int A,B;

        cin>>A>>B;

        if( A == B )
        {
            A_score += A;
            B_score += B;
        }
        else
        {
            if( A > B )
            {
                A_score += A+B;
            }
            else
            {
                B_score += A+B;
            }
        }
    }

    cout<<A_score<<' '<<B_score<<'\n';

    return  0;
}