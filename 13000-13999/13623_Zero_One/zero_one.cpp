#include    <iostream>
#include    <string>

using namespace std;

const string    names = "ABC";

#define MAX_SIZE    2
#define NONE        "*"

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  winner = NONE;
    string  players[MAX_SIZE];

    for(int i=0;i<names.length();i++)
    {
        int n;

        cin>>n;
        players[n].push_back(names[i]);
    }

    for(int i=0;i<MAX_SIZE;i++)
    {
        if( players[i].length() == 1 )
        {
            winner = players[i];
            break;
        }
    }

    cout<<winner<<'\n';

    return  0;
}