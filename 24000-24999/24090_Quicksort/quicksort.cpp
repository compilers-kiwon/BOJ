#include    <iostream>

using namespace std;

#define MAX_SIZE    (10000+1)

static int  N,K,A[MAX_SIZE];
static int  cnt,min_num,max_num;

#define record_swap(cond,n1,n2) \
    {if((cond))min_num=min((n1),(n2)),max_num=max((n1),(n2));}

int input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    return  0;
}

int partition(int p,int r)
{
    int x = A[r];
    int i = p-1;

    for(int j=p;j<=r-1;j++)
    {
        if( A[j] <= x )
        {
            swap(A[++i],A[j]);
            record_swap(++cnt==K,A[i],A[j]);
        }
    }

    if( i+1 != r )
    {
        swap(A[i+1],A[r]);
        record_swap(++cnt==K,A[i+1],A[r]);
    }

    return  i+1;
}

int quick_sort(int p,int r)
{
    if( p < r )
    {
        int q = partition(p,r);

        quick_sort(p,q-1);
        quick_sort(q+1,r);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    quick_sort(1,N);

    if( cnt < K )
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<min_num<<' '<<max_num<<'\n';
    }

    return  0;
}