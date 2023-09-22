#include    <iostream>
#include    <stack>

using namespace std;

#define MAX_LENGTH  (10000*2+1)

static bool knot[MAX_LENGTH];

bool    fold_rope(int p,int rope_length)
{
    stack<int>  left_knots,right_knots;

    for (int cur=0;cur<p;cur++) {
        if (knot[cur]) {
            left_knots.push(p-cur);
        }
    }

    for (int cur=rope_length;cur>p;cur--) {
        if (knot[cur]) {
            right_knots.push(cur-p);
        }
    }

    for(;!left_knots.empty()&&!right_knots.empty();
            left_knots.pop(),right_knots.pop()) {
        if (left_knots.top() != right_knots.top()) {
            return  false;
        }
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,L,cnt;

    cin>>N>>L;
    cnt = 0;

    for (int i=1;i<=N;i++) {
        int k;
        cin>>k;
        knot[k*2] = true;
    }

    for (int pos=1;pos<L*2;pos++) {
        if (fold_rope(pos,L*2) == true) {
            cnt++;
        }
    }

    cout<<cnt<<'\n';
    return  0;
}