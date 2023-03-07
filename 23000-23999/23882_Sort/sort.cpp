#include    <iostream>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_SIZE    (10000+1)

static int  N,K,A[MAX_SIZE];
static map<int,int> idx;
static priority_queue<int>  pq;

#define swap_number(big_idx,small_idx) \
    {idx[A[(small_idx)]]=(big_idx);\
     swap(A[(big_idx)],A[(small_idx)]);K--;}

int input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        pq.push(A[i]);
        idx[A[i]] = i;
    }

    return  0;
}

int sort(void)
{
    for(int last=N;last>=2&&K>0;last--,pq.pop())
    {
        int greatest_number = pq.top();
        int idx_of_greatest_number = idx[greatest_number];

        if( idx_of_greatest_number == last )
        {
            continue;
        }

        swap_number(idx_of_greatest_number,last);
        idx.erase(greatest_number);
    }

    return  0;
}

int print_arr(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<A[i]<<((i==N)?'\n':' ');
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort();

    if( K != 0 )
    {
        cout<<"-1\n";
    }
    else
    {
        print_arr();
    }

    return  0;
}