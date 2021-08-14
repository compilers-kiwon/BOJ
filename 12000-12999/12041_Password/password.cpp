#include    <iostream>
#include    <ctime>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_SIZE        26
#define MAX_CNT         3000
#define int2upper(n)    ('A'+(char)(n))

void    get_randome_message(string& str)
{
    bool    used[MAX_SIZE];

    fill(&used[0],&used[MAX_SIZE],false);

    for(int cnt=0;cnt!=MAX_SIZE;)
    {
        int n = rand()%MAX_SIZE;

        if( used[n] == false )
        {
            cnt++;
            used[n] = true;

            str.push_back(int2upper(n));
        }
    }
}

void    input(vector<string>& prohibited)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  str;
        
        cin>>str;
        prohibited.push_back(str);
    }
}

bool    find_substr(const string& str,const vector<string>& sub)
{
    for(int i=0;i<sub.size();i++)
    {
        for(int j=0;j<MAX_SIZE-sub[i].length()+1;j++)
        {
            if( str[j]==sub[i].front() &&
                str.substr(j,sub[i].length())==sub[i] )
            {
                return  true;
            }
        }
    }

    return  false;
}

bool    is_safe(string& p,const vector<string>& prohibited)
{
    for(int cnt=0;cnt<MAX_CNT;cnt++)
    {
        string  str;

        get_randome_message(str);

        if( find_substr(str,prohibited) == false )
        {
            p = str;
            return  true;
        }
    }
    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;
    srand(time(NULL));

    for(int t=1;t<=T;t++)
    {
        string          m;
        vector<string>  s;

        input(s);
        cout<<"Case #"<<t<<": ";

        if( is_safe(m,s) == true )
        {
            cout<<m<<'\n';
        }
        else
        {
            cout<<"IMPOSSIBLE\n";
        }
    }

    return  0;
}