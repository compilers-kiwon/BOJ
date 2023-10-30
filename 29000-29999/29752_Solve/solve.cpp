#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,max_val,cur_val;

    cin>>N;
    max_val = cur_val = 0;

    for (int i=1;i<=N;i++) {
        int s;

        cin>>s;

        if (s) {
            cur_val++;
        } else {
            max_val = max(max_val,cur_val);
            cur_val = 0;
        }
    }

    cout<<max(max_val,cur_val)<<'\n';
    return  0;
}