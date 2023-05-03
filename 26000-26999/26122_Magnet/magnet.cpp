#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

typedef pair<char,int>  State;

#define INIT_HEAD           {' ',0}
#define build_magnet(p1,p2) (min((p1),(p2))*2)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             K,max_len;
    string          str;
    vector<State>   s;

    cin>>K>>str;
    s.push_back(INIT_HEAD);

    for(int i=0;i<K;i++)
    {
        if( s.back().first != str[i] )
        {
            s.push_back({str[i],1});
        }
        else
        {
            s.back().second++;
        }
    }

    max_len = 0;

    for(int i=1;i<s.size();i++)
    {
        max_len = max(max_len,
            build_magnet(s[i-1].second,s[i].second));
    }

    cout<<max_len<<'\n';
    return  0;
}