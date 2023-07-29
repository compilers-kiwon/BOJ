#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define INF 0x7FFFFFFF

int input(vector<int>& arr)
{
    int size;

    cin>>size;

    for(int i=1;i<=size;i++)
    {
        int n;

        cin>>n;
        arr.push_back(n);
    }

    return  size;
}

int simulate(int size,vector<int>& arr)
{
    int ret = 0;

    for(int i=0;i<size-1;i++)
    {
        int min_pos,min_num;

        min_num = INF;

        for(int j=i;j<size;j++)
        {
            if( arr[j] < min_num )
            {
                min_num = arr[j];
                min_pos = j;
            }
        }

        ret += min_pos-i+1;
        reverse(arr.begin()+i,arr.begin()+min_pos+1);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int N;
        vector<int> L;

        N = input(L);
        cout<<"Case #"<<t<<": "<<simulate(N,L)<<'\n';
    }

    return  0;
}