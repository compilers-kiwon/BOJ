#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt,H_cur,H_prev;

    cin>>N;
    cnt = H_prev = 0;

    for (int i=1;i<=N;i++) {
        cin>>H_cur;
        cnt += ((H_cur>=H_prev)?1:0);
        H_prev = H_cur;
    }

    cout<<cnt<<'\n';
    return  0;
}