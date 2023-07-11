#include    <iostream>

using namespace std;

#define MAX_NUM (500000+1)

static int  N,num[MAX_NUM];
static int  pos[MAX_NUM],dist[MAX_NUM];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>num[i];
        pos[num[i]] = i;
    }

    return  0;
}

int sort(void)
{
    for(int i=1;i<=N;i++)
    {
        // min_num's information
        int n1 = i;
        int p1 = pos[n1];

        // cur_num's information
        int n2 = num[i];
        int p2 = pos[n2];

        // always (min_num's pos)>=(cur_num's pos)
        dist[n1] += p1-p2;
        dist[n2] += p1-p2;

        // place cur_num at min_num's pos
        num[p1] = n2;
        pos[n2] = p1;
    }

    return  0;
}

int print_distance(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<dist[i]<<((i==N)?'\n':' ');
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort();
    print_distance();

    return  0;
}