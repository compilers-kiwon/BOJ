#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define ICON_SIZE   3

const static char   icon[ICON_SIZE][ICON_SIZE] = {
    {'*','x','*'},{' ','x','x'},{'*',' ','*'}
};

int scale_icon(int row,int col,int size,
                    char ch,vector<string>& g)
{
    for (int r=row*size;r<(row+1)*size;r++)
    {
        for (int c=col*size;c<(col+1)*size;c++)
        {
            g[r][c] = ch;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int k;
    vector<string> grid;

    cin>>k;

    for (int i=0;i<k*ICON_SIZE;i++)
    {
        grid.push_back(string(k*ICON_SIZE,' '));
    }

    for (int row=0;row<ICON_SIZE;row++)
    {
        for (int col=0;col<ICON_SIZE;col++)
        {
            if (icon[row][col] != ' ') scale_icon(row,col,k,icon[row][col],grid);
        }
    }

    for (int i=0;i<grid.size();i++)
    {
        cout<<grid[i]<<'\n';
    }

    return  0;
}