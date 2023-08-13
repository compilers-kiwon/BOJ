#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define get_num_of_less(n,arr) \
    (lower_bound((arr).begin(),(arr).end(),(n))-(arr).begin())

#define read_numbers(size,arr) \
    {for(int i=1;i<=(size);i++){int n;cin>>n;(arr).push_back((n));}}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,cnt;
    vector<int> A,B;

    cnt = 0;
    cin>>N>>M;

    read_numbers(N,A);
    read_numbers(M,B);

    sort(B.begin(),B.end());

    for (int i=0;i<N;i++) {
        cnt += M-get_num_of_less(A[i],B);
    }

    cout<<cnt<<'\n';
    return  0;
}