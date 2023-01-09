#include    <iostream>

using namespace std;

#define MAX_NUM_OF_GAMES    6

const int   group[MAX_NUM_OF_GAMES+1] = {-1,3,3,2,2,1,1};

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_wins = 0;

    for(int i=1;i<=MAX_NUM_OF_GAMES;i++)
    {
        char    result;

        cin>>result;
        num_of_wins += (result=='W')?1:0;
    }

    cout<<group[num_of_wins]<<'\n';

    return  0;
}