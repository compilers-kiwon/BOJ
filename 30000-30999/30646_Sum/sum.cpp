#include    <iostream>
#include    <vector>
#include    <map>

using namespace std;

const static int MAX_SIZE = 200000+1;

typedef vector<int> Pos;
typedef long long int int64;

static int N;
static int64 sum[MAX_SIZE];
static map<int,Pos> pos;

void input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) {
        int a;
        cin>>a;

        sum[i] = sum[i-1]+(int64)a;
        pos[a].push_back(i);
    }
}

int64 simulate(int& cnt)
{
    int64 ret;
    map<int,Pos>::iterator  it;

    for (it=pos.begin(),ret=cnt=0;it!=pos.end();it++) {
        int h = it->second.front();
        int t = it->second.back();
        int64 s = sum[t]-sum[h-1];

        if (s >= ret) {
            cnt = (s>ret)?1:cnt+1;
            ret = s;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt;
    int64 max_sum;

    input();
    max_sum = simulate(cnt);
    cout<<max_sum<<' '<<cnt<<'\n';

    return  0;
}