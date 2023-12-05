#include    <iostream>

using namespace std;

const static int MAX_SIZE = 1000+1;
const static int EMPTY = 0;

static int N,M,grid[MAX_SIZE][MAX_SIZE];

void write_new_paper(int row,int col,int paper)
{
    for (int r=row;r<=N;r+=2) {
        for (int c=col;c<=M;c+=2) {
            grid[r][c] = paper;
        }
    }
}

int simulate(void)
{
    int K = 0;

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            if (grid[row][col] == EMPTY) {
                write_new_paper(row,col,++K);
            }
        }
    }

    return  K;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    cout<<simulate()<<'\n';

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=M;col++) {
            cout<<grid[row][col]<<(col==M?'\n':' ');
        }
    }

    return  0;
}