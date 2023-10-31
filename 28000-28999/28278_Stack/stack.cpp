// can be compiled by C++98 only
#include    <iostream>
#include    <stack>

using namespace std;

static inline void push(stack<int>& st) {
    int X;
    cin>>X;
    st.push(X);
}

static inline void pop(stack<int>& st) {
    if (st.empty()) {
        cout<<"-1\n";
    } else {
        cout<<st.top()<<'\n';
        st.pop();
    }
}

static inline void get_size(stack<int>& st) {
    cout<<st.size()<<'\n';
}

static inline void is_empty(stack<int>& st) {
    cout<<(st.empty()?1:0)<<'\n';
}

static inline void get_top(stack<int>& st) {
    if (st.empty()) cout<<"-1\n";
    else cout<<st.top()<<'\n';
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    stack<int> st;

    enum {
        PUSH = 1,
        POP = 2,
        SIZE = 3,
        EMPTY = 4,
        TOP = 5
    };

    cin>>N;

    for (int i=1;i<=N;i++) {
        int op;

        cin>>op;

        switch (op) {
            case PUSH:push(st);break;
            case POP:pop(st);break;
            case SIZE:get_size(st);break;
            case EMPTY:is_empty(st);break;
            case TOP:get_top(st);break;
            default:/*do nothing*/;break;
        }
    }

    return  0;
}