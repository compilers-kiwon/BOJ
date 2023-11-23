#include    <iostream>
#include    <queue>

using namespace std;

const static int NUM_OF_BUTTONS = 10;
const static int MAX_NUM_OF_CHANNEL = 1000000;
const static int INF = 0x7FFFFFFF;
const static int START_CHANNEL = 100;

static int  N,M,dp[MAX_NUM_OF_CHANNEL];
static bool available[NUM_OF_BUTTONS];
static priority_queue<pair<int,int>> pq;

void input(void)
{
    cin>>N>>M;
    fill(&available[0],&available[NUM_OF_BUTTONS],true);

    for (int i=1;i<=M;i++) {
        int b;
        cin>>b;
        available[b] = false;
    }
}

int get_num_of_digits(int n)
{
    int ret = 0;

    for (;n!=0;n/=10,ret++) {
        if (!available[n%10]) return 0;
    }

    return  ret;
}

void init_dp(void)
{
    if (available[0]) {
        dp[0]=1;
        pq.push({-1,0});
    } else {
        dp[0] = INF;
    }

    for (int i=1;i<MAX_NUM_OF_CHANNEL;i++) {
        int n = get_num_of_digits(i);
        
        if (n != 0) {
            dp[i] = n;
            pq.push({-n,i});
        } else {
            dp[i] = INF;
        }
    }

    dp[START_CHANNEL] = 0;
    pq.push({0,START_CHANNEL});
}

int simulate(void)
{
    int ret;

    for (;!pq.empty();pq.pop()) {
        int cur_buttons = -pq.top().first;
        int cur_channel = pq.top().second;

        if (cur_channel == N) {
            ret = cur_buttons;
            break;
        }

        // Press '-'
        if (cur_channel>0 && 
                cur_buttons+1<dp[cur_channel-1]) {
            dp[cur_channel-1] = cur_buttons+1;
            pq.push({-(cur_buttons+1),cur_channel-1});
        }

        // Press '+'
        if (cur_channel<(MAX_NUM_OF_CHANNEL-1) && 
                cur_buttons+1<dp[cur_channel+1]) {
            dp[cur_channel+1] = cur_buttons+1;
            pq.push({-(cur_buttons+1),cur_channel+1});
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    init_dp();

    cout<<simulate()<<'\n';
    return  0;
}