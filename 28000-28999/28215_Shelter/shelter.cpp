#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (50+1)
#define INF         0x7FFFFFFF

typedef pair<int,int>   Pos;    // fisrt: X, second: Y

static int  N,K;
static Pos  p[MAX_SIZE];

#define get_distance(p1,p2) \
    (abs(p[(p1)].first-p[(p2)].first)+abs(p[(p1)].second-p[(p2)].second))

int get_max_distance(const vector<int>& shlters)
{
    int ret = 0;

    for (int i=1;i<=N;i++) {
        int nearest = INF;

        for (int s=0;s<shlters.size();s++) {
            nearest = min(nearest,get_distance(i,shlters[s]));
        }

        ret = max(ret,nearest);
    }

    return  ret;
}

int solve(int idx,vector<int>& shelters,int& min_nearest_dist)
{
    if (shelters.size() == K) {
        min_nearest_dist =
            min(min_nearest_dist,get_max_distance(shelters));
        return 0;
    }

    for (int i=idx;i<=N;i++) {
        shelters.push_back(i);
        solve(i+1,shelters,min_nearest_dist);
        shelters.pop_back();
    }

    return  0;
}

int input(void)
{
    cin>>N>>K;

    for (int i=1;i<=N;i++) {
        cin>>p[i].first>>p[i].second;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int answer = INF;
    vector<int> shelters;

    input();
    solve(1,shelters,answer);

    cout<<answer<<'\n';
    return  0;
}