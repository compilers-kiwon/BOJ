#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    for (cin>>T;T>0;T--) {
        string  s;
        int     a,b;

        cin>>s;
        a = b = 0;

        for (int i=0;i<s.length();i++) {
            (s[i]=='a')?a++:b++;
        }

        cout<<min(a,b)<<'\n';
    }

    return  0;
}