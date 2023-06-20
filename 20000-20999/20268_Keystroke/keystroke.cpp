#include    <iostream>
#include    <vector>
#include    <set>

using namespace std;

#define NUM_OF_KEYS 4

int get_num(int size,set<int>& buf)
{
    for(int i=1;i<=size;i++)
    {
        int n;

        cin>>n;
        buf.insert(n);
    }

    return  0;
}

int input(set<int>& row,set<int>& col)
{
    int m,n;

    cin>>m>>n;
    get_num(m,row);get_num(n,col);

    return  0;
}

int simulate(const vector<int>& p,
            const set<int>& row,const set<int>& col)
{
    set<int>    r,c;

    for(int i=0;i<p.size();i++)
    {
        r.insert((p[i]-1)/2);
        c.insert((p[i]-1)%2);
    }

    return  (r==row)&&(c==col);
}

int dfs(int k,vector<int>& pressed,int& cnt,
            const set<int>& row,const set<int>& col)
{
    if( k > NUM_OF_KEYS )
    {
        cnt += simulate(pressed,row,col);
        return  0;
    }

    pressed.push_back(k);
    dfs(k+1,pressed,cnt,row,col);
    
    pressed.pop_back();
    dfs(k+1,pressed,cnt,row,col);

    return  0;
}

int main(void)
{
    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        vector<int> p;
        set<int>    row,col;
        int         cnt;

        input(row,col);

        cnt = 0;
        dfs(1,p,cnt,row,col);

        cout<<cnt<<'\n';
    }

    return  0;
}