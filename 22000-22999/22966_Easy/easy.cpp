#include    <iostream>
#include    <string>

using namespace std;

#define INF 0x7FFFFFFF

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,difficulty;
    string  subject;

    cin>>N;
    difficulty = INF;

    for(int i=1;i<=N;i++)
    {
        string  str;
        int     d;

        cin>>str>>d;

        if( d < difficulty )
        {
            difficulty = d;
            subject = str;
        }
    }

    cout<<subject<<'\n';

    return  0;
}