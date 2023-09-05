#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_ID  (1000000)
#define NONE    (-1)

static int  N,K;
static vector<int>  pos[MAX_ID+1];

int input(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>K;

    for (int i=1;i<=N;i++) {
        int id;
        
        cin>>id;
        pos[id].push_back(i);
    }

    return  0;
}

bool    is_breed(int p)
{
    vector<int>&    cows = pos[p];

    for (int i=1;i<cows.size();i++) {
        if (cows[i]-cows[i-1] <= K) {
            return  true;
        }
    }

    return  false;
}

int find_maximum_breed_id(void)
{
    int ret = NONE;

    for (int i=0;i<=MAX_ID;i++) {
        if (pos[i].size() <= 1) continue;
        if (is_breed(i)) ret=i;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<find_maximum_breed_id()<<'\n';

    return  0;
}