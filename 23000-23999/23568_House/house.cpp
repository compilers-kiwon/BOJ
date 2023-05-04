#include    <iostream>
#include    <map>

using namespace std;

typedef pair<char,int>    Move;

static map<int,Move>  pos;

#define get_dir(c)  ((c)=='L'?-1:1)

#define get_pos(p) \
    ((p)+pos[(p)].second*get_dir(pos[(p)].first))

int input(void)
{
    int n,current;

    cin>>n;

    for(int m=1;m<=n;m++)
    {
        int     i,k;
        char    j;
        
        cin>>i>>j>>k;
        pos[i] = make_pair(j,k);
    }

    cin>>current;
    return  current;
}

int simulate(int current)
{
    if( pos.find(current) == pos.end() )
    {
        return  current;
    }

    return  simulate(get_pos(current));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int start;

    start = input();
    cout<<simulate(start)<<'\n';

    return  0;
}