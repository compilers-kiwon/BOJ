#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        char    D;
        string  N,result;

        cin>>D>>N;
        if (D=='0' && N=="0") break;

        for (int i=0;i<N.length();i++) {
            if (N[i] == D) continue;
            if (N[i]=='0' && result.empty()) continue;
            result.push_back(N[i]);
        }

        if (result.empty()) result.push_back('0');
        cout<<result<<'\n';
    }

    return  0;
}