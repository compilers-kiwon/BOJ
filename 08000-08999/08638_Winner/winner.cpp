#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,max_score,i;
    char    player;
    string  winner;
    
    cin>>N;
    max_score = 0;

    for (i=1,player='A';i<=N;i++,player++) {
        int s;

        cin>>s;

        if (s >= max_score) {
            if (s > max_score) winner.clear();
            winner.push_back(player);
            max_score = s;
        }
    }

    cout<<winner<<'\n';
    return  0;
}