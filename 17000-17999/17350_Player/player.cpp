#include <iostream>
#include <string>
#include <set>

using namespace std;

void input(set<string>& players)
{
    int N;
    
    cin>>N;
    
    for(int i=1;i<=N;i++)
    {
        string name;
        
        cin>>name;
        players.insert(name);
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<string> players;
    
    input(players);
    cout<<"뭐야"<<(players.find("anj")!=players.end()?';':'?');
    
    return 0;
}