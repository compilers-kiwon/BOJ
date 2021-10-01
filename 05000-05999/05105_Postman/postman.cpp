#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_SIZE            20
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define char2int(c)         ((int)((c)-'0'))

int     get_num(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret = ret*10+char2int(str[i]);
    }

    return  ret;
}

bool    input(int& s,vector<string>& move)
{
    int     ptr;
    string  str,tmp;

    getline(cin,str);

    if( str == "#" )
    {
        return  false;
    }

    s = 0;
    
    if( str.back() != ' ' )
    {
        str.push_back(' ');
    }

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == ' ' )
        {
            if( s == 0 )
            {
                s = get_num(tmp);
            }
            else
            {
                move.push_back(tmp);
            }

            tmp.clear();
        }
        else
        {
            tmp.push_back(str[i]);
        }
    }
    return  true;
}

int     get_offset(const string& str)
{
    int sign,num;

    sign = ((str[0]=='U')?1:-1);
    num = char2int(str[1]);

    return  sign*num;
}

bool    simulate(int current,const vector<string>& move,vector<int>& unvisited)
{
    bool    visited[MAX_SIZE+1];

    fill(&visited[1],&visited[MAX_SIZE+1],false);
    visited[current] = true;
    
    for(int i=0;i<move.size();i++)
    {
        current += get_offset(move[i]);

        if( !IN_RANGE(1,current,MAX_SIZE) || visited[current]==true )
        {
            return  false;
        }

        visited[current] = true;
    }

    for(int i=1;i<=MAX_SIZE;i++)
    {
        if( visited[i] == false )
        {
            unvisited.push_back(i);
        }
    }

    return  true;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int             start_pos;
        vector<int>     unvisited;
        vector<string>  move;

        if( input(start_pos,move) == false )
        {
            break;
        }

        if( simulate(start_pos,move,unvisited) == false )
        {
            cout<<"illegal\n";
        }
        else
        {
            if( unvisited.empty() )
            {
                cout<<"none";
            }
            else
            {
                for(int i=0;i<unvisited.size();i++)
                {
                    cout<<unvisited[i]<<' ';
                }
            }

            cout<<'\n';
        }
    }

    return  0;
}