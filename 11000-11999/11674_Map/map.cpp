#include    <iostream>

using namespace std;

const static int dx[4] = {0,1,0,1};
const static int dy[4] = {0,0,1,1};

#define get_idx(c)      ((int)((c)-'0'))
#define erase_head(s)   ((s).erase(0,1))

int dfs(int& x,int& y,string& pos)
{
    if( pos.empty() )
    {
        return  0;
    }

    int len = 1<<(pos.length()-1);
    int cur_x = dx[get_idx(pos.front())];
    int cur_y = dy[get_idx(pos.front())];

    erase_head(pos);
    
    x += cur_x*len;
    y += cur_y*len;

    return  dfs(x,y,pos);    
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     x,y;
    string  s;

    cin>>s;

    x = y = 0;
    cout<<s.length()<<' ';

    dfs(x,y,s);
    cout<<x<<' '<<y<<'\n';

    return  0;
}