#include    <iostream>
#include    <vector>
#include    <string>
#include    <cmath>

using namespace std;

typedef pair<int,int>   Pos;    // first: row, second: col

const vector<Pos> star = {
    {0,2},
    {1,2},
    {2,0},{2,1},{2,2},{2,3},{2,4},
    {3,1},{3,2},{3,3},
    {4,1},{4,3}
};

int input(vector<string>& grid)
{
    int N;

    cin>>N;

    for (int row=0;row<pow(5,N);row++) {
        grid.push_back(string(pow(5,N),' '));
    }

    return  N;
}

void simulate(int row,int col,
                int len,vector<string>& grid)
{
    if (len == 1) {
        grid[row][col] = '*';
        return;
    }

    int cur_len = len/5;

    for (int i=0;i<star.size();i++) {
        int cur_row = row+star[i].first*cur_len;
        int cur_col = col+star[i].second*cur_len;
        simulate(cur_row,cur_col,cur_len,grid);
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<string> grid;
    
    N = input(grid);
    simulate(0,0,pow(5,N),grid);
    
    for (int i=0;i<grid.size();i++) {
        cout<<grid[i]<<'\n';
    }

    return  0;
}