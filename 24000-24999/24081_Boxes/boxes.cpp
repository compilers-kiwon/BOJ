#include    <iostream>

using namespace std;

#define MAX_NUM (2000)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,cnt;
    int A[MAX_NUM+1] = {0,};
    int B[MAX_NUM+1] = {0,};

    cin>>N>>M;
    cnt = 0;

    for (int i=1;i<=N;i++) {
        int n;
        cin>>n;A[n]++;    
    }

    for (int i=1;i<=M;i++) {
        int n;
        cin>>n;B[n]=1;
    }

    for (int i=1;i<=MAX_NUM;i++) {
        cnt += (B[i]==1)?A[i]:0;
    }

    cout<<cnt<<'\n';
    return  0;
}