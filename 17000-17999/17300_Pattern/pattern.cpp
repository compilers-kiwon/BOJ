#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_NUMBER      9
#define INITIAL_NUMBER  0

const int adj[MAX_NUMBER+1][MAX_NUMBER+1] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,2,0,0,0,4,0,5},
    {0,0,0,0,0,0,0,0,5,0},
    {0,2,0,0,0,0,0,5,0,6},
    {0,0,0,0,0,0,5,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,5,0,0,0,0,0},
    {0,4,0,5,0,0,0,0,0,8},
    {0,0,5,0,0,0,0,0,0,0},
    {0,5,0,6,0,0,0,8,0,0},
};

#define TRUE    1
#define FALSE   0

int is_valid(const vector<int>& pattern)
{
    int     current = INITIAL_NUMBER;
    bool    visited[MAX_NUMBER+1] = {true,false,};

    for(int i=0;i<pattern.size();i++)
    {
        int via = adj[current][pattern[i]];

        if( visited[pattern[i]]==true || visited[via]==false )
        {
            return  FALSE;
        }

        current = pattern[i];
        visited[current] = true;
    }

    return  TRUE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         L;
    vector<int> pattern;

    cin>>L;

    for(int i=1;i<=L;i++)
    {
        int A;

        cin>>A;
        pattern.push_back(A);
    }

    cout<<(is_valid(pattern)?"YES":"NO")<<'\n';

    return  0;
}