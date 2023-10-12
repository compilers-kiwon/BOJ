#include    <iostream>

using namespace std;

const static int MAX_SIZE = 100+1;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,num[MAX_SIZE],sum;

    cin>>n;
    sum = 0;

    for (int i=1;i<=n;i++) {
        cin>>num[i];
        sum += num[i];
    }

    for (int i=1;i<=n;i++) {
        if (sum-num[i] == num[i]) {
            cout<<i<<'\n';
            break;
        }
    }

    return  0;
}