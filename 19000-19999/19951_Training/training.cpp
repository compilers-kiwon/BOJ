#include    <iostream>

using namespace std;

const static int MAX_SIZE = 100000+1;

static int N,M,H[MAX_SIZE],task[MAX_SIZE+1];

void input(void)
{
    cin>>N>>M;

    for (int i=1;i<=N;i++) {
        cin>>H[i];
    }

    for (int i=1;i<=M;i++) {
        int a,b,k;
        cin>>a>>b>>k;

        task[a] += k;
        task[b+1] -= k;
    }
}

void simulate(void)
{
    int cur_k = 0;

    for (int i=1;i<=N;i++) {
        cur_k += task[i];
        H[i] += cur_k;
    }
}

void print(void)
{
    for (int i=1;i<=N;i++) {
        cout<<H[i]<<(i==N?'\n':' ');
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();
    
    return  0;
}