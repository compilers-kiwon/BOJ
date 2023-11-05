#include    <iostream>
#include    <queue>

using namespace std;

typedef long long int   int64;

static inline int64 get_num(priority_queue<int64>& cards) {
    int64   ret = -cards.top();
    cards.pop();
    return  ret;
}

int input(priority_queue<int64>& cards)
{
    int n,m;

    cin>>n>>m;

    for (int i=1;i<=n;i++) {
        int64   a;
        cin>>a;
        cards.push(-a);
    }

    return  m;
}

int64 get_sum(priority_queue<int64>& cards)
{
    int64   ret = 0;

    for (;!cards.empty();cards.pop()) {
        ret += -cards.top();
    }

    return  ret;
}

void simulate(int num_of_operations,
            priority_queue<int64>& cards)
{
    for (int i=1;i<=num_of_operations;i++) {
        int64   x,y;

        x = get_num(cards);
        y = get_num(cards);
        
        cards.push(-(x+y));
        cards.push(-(x+y));
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_operations;
    priority_queue<int64> cards;

    num_of_operations = input(cards);
    simulate(num_of_operations,cards);
    cout<<get_sum(cards)<<'\n';

    return  0;
}