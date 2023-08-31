#include    <iostream>
#include    <string>

using namespace std;

string  simulate(string& s,int num_of_operations)
{
    if (num_of_operations == 0) return  s;
    
    string  str;
    int     cnt;

    cnt = 0;
    s.push_back(' ');

    for (int i=0;i<s.length();i++) {
        if (cnt==0 || s[i-1]==s[i]) {
            cnt++;
            continue;
        }

        str += to_string(cnt);
        str.push_back(s[i-1]);
        cnt = 1;
    }

    return  simulate(str,num_of_operations-1);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    string  s;

    cin>>n>>s;
    cout<<simulate(s,n)<<'\n';

    return  0;
}