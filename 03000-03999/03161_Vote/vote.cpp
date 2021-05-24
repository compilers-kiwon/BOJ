#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (50+1)

int M,N,vote_table[MAX_SIZE][MAX_SIZE],score_table[MAX_SIZE][MAX_SIZE];
int num_of_defeats[MAX_SIZE];

void    input(void)
{
    cin>>M>>N;

    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>vote_table[i][j];
        }
    }
}

void    build_score_table(void)
{
    for(int i=1;i<=M;i++)
    {
        for(int w=1;w<N;w++)
        {
            for(int l=w+1;l<=N;l++)
            {
                const int&  winner = vote_table[i][w];
                const int&  looser = vote_table[i][l];

                score_table[winner][looser]++;
            }
        }
    }
}

void    get_num_of_defeats(void)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if( i == j )
            {
                continue;
            }

            if( score_table[i][j] > score_table[j][i] )
            {
                num_of_defeats[i]++;
            }
        }
    }
}

void    find_winner(vector<int>& w)
{
    int max_num_of_defeats = -1;

    for(int i=1;i<=N;i++)
    {
        if( num_of_defeats[i] >= max_num_of_defeats )
        {
            if( num_of_defeats[i] > max_num_of_defeats )
            {
                w.clear();
            }

            w.push_back(i);
            max_num_of_defeats = num_of_defeats[i];
        }
    }
}

void    print_winner(const vector<int>& w)
{
    for(int i=0;i<w.size();i++)
    {
        cout<<w[i]<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    build_score_table();
    get_num_of_defeats();

    vector<int> winner;

    find_winner(winner);
    print_winner(winner);

    return  0;
}