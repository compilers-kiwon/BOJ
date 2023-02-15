#include    <iostream>

using namespace std;

#define MAX_SIZE    (500000+1)

static int  N,K,A[MAX_SIZE],cnt,tmp[MAX_SIZE],answer;

int input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    return  0;
}

int merge(int low,int mid,int high)
{
    int i,j,t;

    for(i=low,j=mid+1,t=1;i<=mid&&j<=high;t++)
    {
        if( A[i] <= A[j] )
        {
            tmp[t]=A[i];i++;
        }
        else
        {
            tmp[t]=A[j];j++;
        }
    }

    for(;i<=mid;t++,i++) tmp[t]=A[i];
    for(;j<=high;t++,j++) tmp[t]=A[j];

    for(i=low,t=1;i<=high;i++,t++)
    {
        A[i] = tmp[t];

        if( ++cnt == K )
        {
            answer = A[i];
        }
    }

    return  0;
}

int merge_sort(int low,int high)
{
    if( low < high )
    {
        int mid = (low+high)/2;

        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    answer = -1;

    merge_sort(1,N);
    cout<<answer<<'\n';

    return  0;
}