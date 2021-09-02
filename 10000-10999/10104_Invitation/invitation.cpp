#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_ROUND   (100+1)

int K,M,r[MAX_ROUND];

void    input(vector<int>& f)
{
    cin>>K>>M;

    f.push_back(0);

    for(int i=1;i<=K;i++)
    {
        f.push_back(i);
    }

    for(int i=1;i<=M;i++)
    {
        cin>>r[i];
    }
}

void    remove_friend(vector<int>& f,int num_of_rounds)
{
    if( num_of_rounds > M )
    {
        for(int i=1;i<f.size();i++)
        {
            cout<<f[i]<<'\n';
        }

        return;
    }

    vector<int> result;

    result.push_back(0);

    for(int i=1;i<f.size();i++)
    {
        if( i%r[num_of_rounds] != 0 )
        {
            result.push_back(f[i]);
        }
    }

    remove_friend(result,num_of_rounds+1);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> friends;

    input(friends);
    remove_friend(friends,1);

    return  0;
}