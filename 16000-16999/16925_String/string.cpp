#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_LEN (100+1)

static char visited[MAX_LEN];
static string in[MAX_LEN*2];
static vector<string> s[MAX_LEN];

#define TRUE    1
#define FALSE   0

#define is_prefix(str,sub,len)  ((str).substr(0,(len))==(sub))
#define is_postfix(str,sub,len) ((str).substr((str).length()-(len),(len))==(sub))

#define PREFIX  1
#define POSTFIX 2

int input(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=2*N-2;i++)
    {
        string& str = in[i];

        cin>>str;
        s[str.length()].push_back(str);
    }

    return  N;
}

int check_spell(const string& str,int len)
{
    for(int i=1;i<=len-1;i++)
    {
        string& s1 = s[i].front();
        string& s2 = s[i].back();

        if( !(is_prefix(str,s1,i) && is_postfix(str,s2,i))
                && !(is_prefix(str,s2,i) && is_postfix(str,s1,i)) )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

string  simulate(int len)
{
    string  str1,str2;

    str1 = s[len-1].front();
    str1.push_back(s[len-1].back().back());

    str2 = s[len-1].back();
    str2.push_back(s[len-1].front().back());

    return  check_spell(str1,len)?str1:str2;
}

string  determine(const string& w)
{
    string  ret;
    int     length = w.length();

    for(int i=1;i<=2*length-2;i++)
    {
        char    attr = is_prefix(w,in[i],in[i].length())?'P':'S';

        if( visited[in[i].length()] == attr )
        {
            attr = (attr=='P')?'S':'P';
        }
        else
        {
            visited[in[i].length()] = attr;
        }

        ret.push_back(attr);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     length = input();
    string  word = simulate(length);

    cout<<word<<'\n';
    cout<<determine(word)<<'\n';

    return  0;
}