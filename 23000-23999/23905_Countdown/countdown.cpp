#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    
    cin>>T;

    for (int t=1;t<=T;t++) {
        int N,K,cnt,expected;
        
        cin>>N>>K;
        cnt = 0;
        expected = K;

        for (int i=1;i<=N;i++) {
            int A;

            cin>>A;
            expected = (A==expected)?
                    expected-1:K-(A==K?1:0);
            if (expected == 0) cnt++,expected=K;
        }

        cout<<"Case #"<<t<<": "<<cnt<<'\n';
    }
    
    return  0;
}