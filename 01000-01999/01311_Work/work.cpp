#include    <iostream>

using namespace std;

const static int MAX_SIZE = 20;
const static int NONE = 0;
const static int INF = 0x7FFFFFFF;

static int N,D[MAX_SIZE+1][MAX_SIZE+1];
static int dp[MAX_SIZE+1][1<<MAX_SIZE];

void input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin>>D[i][j];
        }
    }
}

int get_dp(int w,int j)
{
    if (w == NONE) return 0;

    int&    ret = dp[w][j];

    if (ret != NONE) return ret;
    ret = INF;

    for (int job_idx=1;job_idx<=N;job_idx++) {
        if ((j&(1<<(job_idx-1))) == 0) continue;
        int prev_jobs = j-(1<<(job_idx-1));
        ret = min(ret,get_dp(w-1,prev_jobs)+D[w][job_idx]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_dp(N,(1<<N)-1)<<'\n';

    return  0;
}