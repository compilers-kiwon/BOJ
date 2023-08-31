#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,cnt;

    cin>>N;
    cnt = 0;

    for (int i=1;i<=N;i++) {
        string  s;

        cin>>s;
        cnt += (s=="A")?1:-1;

        if (cnt < 0) {
            cout<<"NO\n";
            return  0;
        }
    }

    cout<<((cnt==0)?"YES":"NO")<<'\n';
    return  0;
}