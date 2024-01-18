#include    <iostream>
#include    <queue>

using namespace std;

void input(queue<int>& required,
            priority_queue<int>& box)
{
    int N,M;

    cin>>N>>M;

    for (int i=1;i<=N;i++) {
        int c;
        cin>>c;
        box.push(c);
    }

    for (int i=1;i<=M;i++) {
        int w;
        cin>>w;
        required.push(w);
    }
}

bool simulate(queue<int>& required,
                priority_queue<int>& box)
{
    for (;!required.empty();required.pop()) {
        int c = box.top();

        if (required.front() > c) {
            return  false;
        }

        box.pop();
        box.push(c-required.front());
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int>  w;
    priority_queue<int> c;

    input(w,c);
    cout<<(simulate(w,c)?1:0)<<'\n';

    return  0;
}