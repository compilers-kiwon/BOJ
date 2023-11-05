#include    <iostream>
#include    <deque>

using namespace std;

static void push_front(deque<int>& dq) {
    int X;
    cin>>X;
    dq.push_front(X);
}

static void push_back(deque<int>& dq) {
    int X;
    cin>>X;
    dq.push_back(X);
}

static int pop_front(deque<int>& dq) {
    int ret = -1;

    if (!dq.empty()) {
        ret = dq.front();
        dq.pop_front();
    }

    return  ret;
}

static int pop_back(deque<int>& dq) {
    int ret = -1;

    if (!dq.empty()) {
        ret = dq.back();
        dq.pop_back();
    }

    return  ret;
}

static int get_front(deque<int>& dq) {
    return  (dq.empty()?-1:dq.front());
}

static int get_back(deque<int>& dq) {
    return  (dq.empty()?-1:dq.back());
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    enum {
        PUSH_FRONT = 1,
        PUSH_BACK = 2,
        POP_FRONT = 3,
        POP_BACK = 4,
        GET_SIZE = 5,
        IS_EMPTY = 6,
        GET_FRONT = 7,
        GET_BACK = 8 
    };

    int N;
    deque<int> dq;

    cin>>N;

    for (int i=1;i<=N;i++) {
        int op;

        cin>>op;

        switch (op) {
            case PUSH_FRONT:push_front(dq);break;
            case PUSH_BACK:push_back(dq);break;
            case POP_FRONT:cout<<pop_front(dq)<<'\n';break;
            case POP_BACK:cout<<pop_back(dq)<<'\n';break;
            case GET_SIZE:cout<<dq.size()<<'\n';break;
            case IS_EMPTY:cout<<(dq.empty()?1:0)<<'\n';break;
            case GET_FRONT:cout<<get_front(dq)<<'\n';break;
            case GET_BACK:cout<<get_back(dq)<<'\n';break;
            default:/*do nothing*/;break;
        }
    }

    return  0;
}