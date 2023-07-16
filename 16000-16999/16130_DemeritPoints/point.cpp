#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

int get_points(const string& str,vector<int>& p)
{
    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];

        if( isdigit(c) )
        {
            p.push_back((int)(c-'0'));
        }
        else
        {
            p.push_back((int)(c-'A'+10));
        }
    }

    return  0;
}

int simulate(const vector<int>& p,string& str)
{
    int ret,current;
    
    ret = current = 0;

    for(int i=0;i<p.size();i++)
    {
        int     next = current+p[i];
        int     cur_week = current/10;
        int     next_week = next/10;

        if( cur_week != next_week )
        {
            if( next_week >= 4)
            {
                if (next_week==4) str="(weapon)";
                else str="(09)";
                break;
            }
            else
            {
                ret += next_week;
            }
        }

        current = next;
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
        string      str;
        vector<int> p;
        int         period;

        cin>>str;
        get_points(str,p);

        str.clear();
        period = simulate(p,str);

        cout<<period<<str<<'\n';
    }

    return  0;
}