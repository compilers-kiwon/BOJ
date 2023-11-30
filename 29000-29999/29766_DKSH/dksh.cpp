#include    <iostream>
#include    <string>

using namespace std;

const static string DKSH = "DKSH";

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt;
    string str;

    cin>>str;
    cnt = 0;

    for (int i=0;i<str.length()-DKSH.length()+1;i++) {
        if (str.substr(i,4) == DKSH) cnt++;
    }

    cout<<cnt<<'\n';
    return  0;
}