#include    <iostream>

using namespace std;

#define MAX_SIZE    (50000+1)
#define MOD(a)      (((a)*(a))%2010)

static int  n,m,arr[MAX_SIZE];

int perform_mod(int from,int to)
{
    for(int i=from;i<=to;i++) arr[i]=MOD(arr[i]);
    return  0;
}

int get_sum(int from,int to)
{
    int ret = 0;

    for(int i=from;i<=to;i++) ret+=arr[i]; 
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    cin>>m;

    for(int i=1;i<=m;i++)
    {
        int k,l,r;

        cin>>k>>l>>r;

        if(k==1) perform_mod(l,r);
        else cout<<get_sum(l,r)<<'\n';
    }

    return  0;
}