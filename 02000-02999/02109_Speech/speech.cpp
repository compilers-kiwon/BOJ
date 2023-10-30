#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

const static int MAX_SIZE = 10000;

static vector<int>  s[MAX_SIZE+1];

void input(void)
{
    int n;
    
    cin>>n;
    
    for (int i=1;i<=n;i++) {
        int p,d;
        cin>>p>>d;
        s[d].push_back(p);
    }
}

int simulate(void)
{
    int ret = 0;
    priority_queue<int> money;

    for (int d=MAX_SIZE;d>=1;d--) {
        for (int i=0;i<s[d].size();i++) {
            money.push(s[d][i]);
        }

        if (!money.empty()) {
            ret += money.top();
            money.pop();
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}