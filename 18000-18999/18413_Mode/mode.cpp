#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,max_num;
    int cnt[MAX_SIZE] = {0,};

    cin>>N>>M;
    max_num = 0;

    for(int i=1;i<=N;i++)
    {
        int A;

        cin>>A;
        max_num = max(max_num,++cnt[A]);
    }

    cout<<max_num<<'\n';
    return  0;
}