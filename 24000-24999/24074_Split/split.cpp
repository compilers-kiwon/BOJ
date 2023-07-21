#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int input(int arr[],int& max_pos)
{
    int ret,max_num;

    cin>>ret;
    max_num = 0;

    for(int i=1;i<=ret;i++)
    {
        cin>>arr[i];
        
        if( arr[i] > max_num )
        {
            max_pos = i;
            max_num = arr[i];
        }
    }

    return  ret;
}

int get_sum(int arr[],int l,int r)
{
    int ret = 0;
    for(int i=l;i<=r;i++) ret+=arr[i];
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A[MAX_SIZE],split_pos;

    N = input(A,split_pos);

    cout<<get_sum(A,1,split_pos-1)<<
            '\n'<<get_sum(A,split_pos+1,N)<<'\n';
    
    return  0;
}