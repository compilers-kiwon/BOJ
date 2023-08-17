#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+2)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A[MAX_SIZE],cur_len,max_len;

    cin>>N;A[N+1]=0;
    for (int i=1;i<=N;i++) cin>>A[i];

    cur_len = max_len = 0;

    for (int i=1;i<=N+1;i++) {
        if (A[i] == 0) {
            max_len = max(max_len,cur_len);
            cur_len = 0;
        } else {
            cur_len++;
        }
    }

    cout<<max_len+1<<'\n';
    return  0;
}