#include    <iostream>
#include    <string>
#include    <queue>
#include    <map>

using namespace std;

typedef struct{string str[3];int step;} State;

State   init;
map<string,map<string,map<string,int>>> dp;

void    input(void)
{
    for(int i=0;i<3;i++)
    {
        int n;

        cin>>n;

        if( n == 0 )
        {
            continue;
        }

        cin>>init.str[i];
    }

    init.step = 1;
}

bool    check_str(string& str,char c)
{
    for(int i=0;i<str.length();i++)
    {
        if( str[i] != c )
        {
            return  false;
        }
    }

    return  true;
}

bool    is_final_state(string& A,string& B,string& C)
{
    return  (check_str(A,'A')&&check_str(B,'B')&&check_str(C,'C'));
}

void    build_new_state(string str[],int src,int dst,int n,queue<State>& q)
{
    char    c;
    
    if( str[src].empty() )
    {
        return;
    }

    c = str[src].back();

    str[src].pop_back();
    str[dst].push_back(c);
    
    if( dp[str[0]][str[1]][str[2]]==0 || n<dp[str[0]][str[1]][str[2]] )
    {
        State   s;

        s.step = n;
        s.str[0] = str[0];
        s.str[1] = str[1];
        s.str[2] = str[2];

        q.push(s);
        dp[str[0]][str[1]][str[2]] = n;
    }

    str[dst].pop_back();
    str[src].push_back(c);
}

int     simulate(void)
{
    int             ret;
    queue<State>    q;

    q.push(init);
    dp[init.str[0]][init.str[1]][init.str[2]] = 1;
    
    for(;!q.empty();q.pop())
    {
        int     current_step = q.front().step;
        string  current_str[3];
        
        current_str[0] = q.front().str[0];
        current_str[1] = q.front().str[1];
        current_str[2] = q.front().str[2];
        
        if( current_step > dp[current_str[0]][current_str[1]][current_str[2]] )
        {
            continue;
        }

        if( is_final_state(current_str[0],current_str[1],current_str[2]) == true )
        {
            ret = current_step;
            break;
        }
        
        build_new_state(current_str,0,1,current_step+1,q);
        build_new_state(current_str,0,2,current_step+1,q);
        build_new_state(current_str,1,0,current_step+1,q);
        build_new_state(current_str,1,2,current_step+1,q);
        build_new_state(current_str,2,0,current_step+1,q);
        build_new_state(current_str,2,1,current_step+1,q);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()-1<<'\n';

    return  0;
}