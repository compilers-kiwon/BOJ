#include    <iostream>
#include    <string>

using namespace std;

const static string K = "KOREA";
const static string Y = "YONSEI";
const static int INF = 0x7FFFFFFF;

int find_sub_str(const string& src,
                    const string& sub)
{
    int pos,i;

    for (i=pos=0;i<src.length()&&pos<sub.length();i++) {
        if (src[i] == sub[pos]) pos++;
    }

    return  (pos==sub.length())?i:INF;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  S;

    cin>>S;
    cout<<((find_sub_str(S,K)<find_sub_str(S,Y))?K:Y)<<'\n';

    return  0;
}