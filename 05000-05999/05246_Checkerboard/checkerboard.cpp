#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE    8

int input(set<int> board[])
{
    int num_of_pieces;

    cin>>num_of_pieces;

    for(int i=1;i<=num_of_pieces;i++)
    {
        int row,col;

        cin>>col>>row;
        board[row].insert(col);
    }

    return  0;
}

int get_max_num_of_pieces_in_row(set<int> board[])
{
    int ret = 0;

    for(int row=1;row<=MAX_SIZE;row++)
    {
        ret = max(ret,(int)board[row].size());
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_boards;

    cin>>num_of_boards;

    for(int i=1;i<=num_of_boards;i++)
    {
        set<int>    board[MAX_SIZE+1];

        input(board);
        cout<<get_max_num_of_pieces_in_row(board)<<'\n';
    }

    return  0;
}