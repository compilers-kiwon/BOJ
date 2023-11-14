#include    <iostream>
#include    <stack>

using namespace std;

const static int NUM_OF_STACKS = 4;
const static int NONE = 0;

static int  N;
static stack<int> st[NUM_OF_STACKS+1];

int get_stack(int num) {
    int ret = NONE;

    for (int i=1;i<=NUM_OF_STACKS;i++) {
        if (st[i].empty() || num>st[i].top()) {
            ret = i;
            break;
        }
    }

    return  ret;
}

bool input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) {
        int A,pos;
        cin>>A;

        if ((pos=get_stack(A)) == NONE) {
            return  false;
        }  
        st[pos].push(A);
    }

    return  true;
}

bool simulate(void)
{
    for (int i=N;i>=1;i--) {
        int pos;

        for (pos=1;pos<=NUM_OF_STACKS;pos++) {
            if (!st[pos].empty() && st[pos].top()==i) break;
        }

        if (pos > NUM_OF_STACKS) return false;
        st[pos].pop();
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cout<<(!input()||!simulate()?"NO":"YES")<<'\n';
    return  0;
}