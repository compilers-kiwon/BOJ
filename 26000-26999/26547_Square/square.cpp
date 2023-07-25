#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define build_grid(g,len)   {for(int i=0;i<(len);i++)(g).push_back(string((len),' '));}

int get_square(vector<string>& g,int row,int col,
        int row_offset,int col_offset,const string& str,int len)
{
    for(int i=0;i<len;i++,row+=row_offset,col+=col_offset)
    {
        g[row][col] = str[i];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int k;
        string w;
        vector<string> grid;

        cin>>w;
        k = w.length();

        build_grid(grid,k);

        get_square(grid,0,0,1,0,w,k);
        get_square(grid,0,0,0,1,w,k);
        get_square(grid,k-1,k-1,-1,0,w,k);
        get_square(grid,k-1,k-1,0,-1,w,k);

        for(int i=0;i<w.length();i++)
        {
            cout<<grid[i]<<'\n';
        }
    }

    return  0;
}