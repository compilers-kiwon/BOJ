#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,cnt;
    char    owner;
    string  prev_owner;

    cin>>owner>>N;
    
    cnt = 1;
    prev_owner.push_back(owner);

    for(int i=1;i<=N;i++)
    {
        char    winner,loser;

        cin>>winner>>loser;

        if( owner == loser )
        {
            owner = winner;
            
            if( prev_owner.find(owner) == string::npos )
            {
                cnt++;
                prev_owner.push_back(owner);
            }
        }
    }

    cout<<owner<<'\n'<<cnt<<'\n';

    return  0;
}