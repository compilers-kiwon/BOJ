#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static map<string,char> conversion = {
    {"@",'a'},{"[",'c'},{"!",'i'},{";",'j'},{"^",'n'},
    {"0",'o'},{"7",'t'},{"\\'",'v'},{"\\\\'",'w'}
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

string  restore(const string& str)
{
    string  tmp,ret;
    int     cnt = 0;

    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];

        if( IN_RANGE('a',c,'z') )
        {
            ret.push_back(c);
            continue;
        }

        tmp.push_back(c);

        if( conversion.find(tmp) != conversion.end() )
        {
            ret.push_back(conversion[tmp]);
            tmp.clear();cnt++;
        }
    }

    if( !tmp.empty() || cnt*2>=ret.length() )
    {
        ret = "I don\'t understand";
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        cout<<restore(str)<<'\n';
    }

    return  0;
}