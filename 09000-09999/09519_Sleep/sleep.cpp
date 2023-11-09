#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

static string blink(const string& str)
{
    string  ret = string(str.length(),' ');
    int     pos,h,t;

    for (pos=0,h=0,t=str.length()-1;;) {
        if (pos < str.length()) ret[h++]=str[pos++];
        else break;

        if (pos < str.length()) ret[t--]=str[pos++];
        else break;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X,cnt;
    string str,tmp;
    vector<string> history;

    cin>>X>>str;
    tmp = str;
    history.push_back(str);

    for (cnt=1;cnt<=X;cnt++) {
        tmp = blink(tmp);
        if (str == tmp) break;
        history.push_back(tmp);
    }
    
    cout<<history[X%cnt]<<'\n';

    return  0;
}