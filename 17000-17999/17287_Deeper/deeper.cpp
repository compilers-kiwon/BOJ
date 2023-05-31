#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

enum {
    LBRACKET = 0,
    RBRACKET = 1,
    LBRACE = 2,
    RBRACE = 3,
    LPAREN = 4,
    RPAREN = 5,
    NUMBER = 6,
    MAX_TOKEN = 7
};

const int score[MAX_TOKEN] = {3,-3,2,-2,1,-1,0};

#define get_tail(v) ((v).empty()?0:(v).back())

int get_token(char c)
{
    int ret;

    switch(c)
    {
        case '[':ret=LBRACKET;break;
        case ']':ret=RBRACKET;break;
        case '{':ret=LBRACE;break;
        case '}':ret=RBRACE;break;
        case '(':ret=LPAREN;break;
        case ')':ret=RPAREN;break;
        default:ret=NUMBER;break;
    }

    return  ret;
}

int tokenize(const string& str,
                vector<int>& tokens)
{
    for(int i=0;i<str.length();i++)
    {
        int t = get_token(str[i]);

        if( t==NUMBER && 
                get_tail(tokens)==NUMBER )
        {
            continue;
        }

        tokens.push_back(t);
    }

    return  0;
}

int get_score(const vector<int>& t,vector<int>& s)
{
    for(int i=0;i<t.size();i++)
    {
        int cur = score[t[i]]+get_tail(s);
        s.push_back(cur);
    }
    
    return  0;
}

int get_max_score(const vector<int>& t,
                    const vector<int>& s)
{
    int ret = 0;

    for(int i=0;i<t.size();i++)
    {
        if( t[i] == NUMBER )
        {
            ret = max(ret,s[i]);
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string      str;
    vector<int> t,s;

    cin>>str;
    tokenize(str,t);

    get_score(t,s);
    cout<<get_max_score(t,s)<<'\n';

    return  0;
}