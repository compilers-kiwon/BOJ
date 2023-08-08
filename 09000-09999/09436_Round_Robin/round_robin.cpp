#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    100

#define TRUE    1
#define FALSE   0

int input(queue<int>& counts)
{
    int N,T;

    cin>>N;
    if (N == 0) return FALSE;

    cin>>T;
    for (int i=1;i<=N;i++) counts.push(0);

    return  T;
}

int check_counts(queue<int>& counts)
{
    int ret = TRUE;
    int c = counts.front();

    for (int i=1,size=counts.size();i<=size;i++) {
        if (counts.front() != c) ret = FALSE;
        counts.push(counts.front());counts.pop();
    }

    return  ret;
}

int simulate(queue<int>& counts,int num_of_turns)
{
    for (;;) {
        for (int t=1;t<num_of_turns;t++) {
            counts.push(counts.front()+1);
            counts.pop();
        }

        counts.pop();

        if (check_counts(counts) == TRUE) break;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int T;
        queue<int> counts;

        if ((T=input(counts)) == FALSE) break;
        simulate(counts,T);
        cout<<counts.size()<<' '<<counts.front()<<'\n';
    }

    return  0;
}