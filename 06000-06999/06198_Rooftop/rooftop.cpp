#include    <iostream>
#include    <stack>

using namespace std;

typedef long long int   int64;

typedef pair<int,int64> State;  // first: height, second: num_of_visible

const static int MAX_SIZE = 80000+1;

static int  N,h[MAX_SIZE];

int64 simulate(void)
{
    int64   ret = 0;
    stack<State>    st;

    for (int i=N;i>=1;i--) {
        State   cur = {h[i],0};
        int64&  cnt = cur.second;

        for (;!st.empty()&&st.top().first<cur.first;st.pop()) {
            cnt += st.top().second+1;
            ret += st.top().second;
        }

        st.push(cur);
    }

    for (;!st.empty();st.pop()) {
        ret += st.top().second;
    }

    return  ret;
}

void input(void)
{
    cin>>N;
    for (int i=1;i<=N;i++) cin>>h[i];
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}