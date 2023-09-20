#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Z;

    cin>>Z;

    for (int i=1;i<=Z;i++) {
        int     N,C;
        string  s;

        cin>>N>>C>>s;
        for (int j=1;j<=C;j++) {
            s = s.substr(N)+s;
        }

        cout<<s<<'\n';
    }

    return  0;
}