#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        int N;
        string S,sub;

        cin>>N>>S;
        cout<<"Case #"<<t<<": ";

        for (int i=0;i<S.length();i++) {
            if (!sub.empty() && S[i]<=sub.back()) {
                sub.clear();
            } 
            
            sub.push_back(S[i]);
            cout<<sub.length()<<
                    (i==S.length()-1?'\n':' ');
        }
    }

    return  0;
}