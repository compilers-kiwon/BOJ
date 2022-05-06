#include    <iostream>

using namespace std;

#define MAX_DIR 8

const struct{int d_row,d_col;} adj[MAX_DIR] = {
    {-1,2},{-1,-2},{1,2},{1,-2},{-2,1},{-2,-1},{2,1},{2,-1}
};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int     n,r1,c1,r2,c2;
        bool    found;

        cin>>n>>r1>>c1>>r2>>c2;
        found = false;

        for(int d=0;d<MAX_DIR&&found!=true;d++)
        {
            int adj_row = r1+adj[d].d_row;
            int adj_col = c1+adj[d].d_col;

            if( adj_row==r2 && adj_col==c2 )
            {
                found = true;
            }
        }

        cout<<"Case "<<t<<": "<<(found?"YES":"NO")<<'\n';
    }

    return  0;
}