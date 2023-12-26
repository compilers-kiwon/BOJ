#include    <iostream>
#include    <string>

using namespace std;

bool is_approved(const string& s)
{
    int num_of_agrees = 0;

    for (int i=0;i<s.length();i++) {
        num_of_agrees += (s[i]=='O'?1:0);
    }

    return  (num_of_agrees*2 >= s.length());
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,cnt;

    cnt = 0;
    cin>>N>>M;

    for (int i=1;i<=N;i++) {
        string v;

        cin>>v;
        cnt += (is_approved(v)?1:0);
    }

    cout<<cnt<<'\n';
    return  0;
}