#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define NUM_OF_GAMES    16
#define init(m,p)       ((m).find((p))==(m).end()?(m)[(p)]=true:0)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int c;

    cin>>c;

    for (int i=1;i<=c;i++) {
        map<string,bool>    player;

        for (int n=1;n<=NUM_OF_GAMES;n++) {
            string  t1,t2;
            int     g1,g2;

            cin>>t1>>t2>>g1>>g2;

            init(player,t1);
            init(player,t2);

            player[t1] &= (g1>g2);
            player[t2] &= (g1<g2);
        }

        map<string,bool>::iterator it = player.begin();
        
        for (;it!=player.end();it++) {
            if (it->second == true ) {
                cout<<it->first<<'\n';
                break;
            }
        }
    }

    return  0;
}