#include    <iostream>

using namespace std;

const static int    MAX_SIZE = 100000+1;

static int N,M,a[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    for (int i=1;i<=N;i++) cin>>a[i];

    for (int t=0,g=1;g<=N;t++) {
        int num_of_people = 0;

        for (;g<=N&&num_of_people<M;g++) {
            if (num_of_people+a[g] > M) break;
            cout<<t<<'\n';
            num_of_people += a[g];
        }
    }

    return  0;
}