#include    <iostream>
#include    <string>
#include    <queue>
#include    <set>

using namespace std;

#define MAX_LEN 1000
#define NONE    -1

string  phone_number;
string  dp_num[MAX_LEN];
int     dp_score[MAX_LEN];

typedef pair<int,int>  State;

#define GROUP_LEN_2 2
#define GROUP_LEN_3 3

void    init(void)
{
    cin>>phone_number;
    fill(&dp_score[0],&dp_score[MAX_LEN],NONE);
}

int     get_score(const string& str)
{
    set<char>   buf;

    for(int i=0;i<str.length();i++)
    {
        buf.insert(str[i]);
    }

    return  ((buf.size()==str.length())?0
                        :(buf.size()==1)?2:1);
}

void    group_numbers(queue<State>& q,int score,int pos,int len)
{
    if( pos+len > phone_number.length() )
    {
        return;
    }

    string  new_group = phone_number.substr(pos,len);
    string  next_number = ((pos==0)?"":dp_num[pos-1]+"-")+new_group;
    int     next_score = score+get_score(new_group);
    int     next_pos = pos+len-1;

    if( dp_score[next_pos]==NONE || next_score>dp_score[next_pos]
        || (next_score==dp_score[next_pos]&&next_number<dp_num[next_pos]) )
    {
        dp_score[next_pos] = next_score;
        dp_num[next_pos] = next_number;
        q.push(make_pair(next_score,next_pos+1));
    }
}

void    build_groups(void)
{
    queue<State>    q;

    for(q.push(make_pair(0,0));!q.empty();q.pop())
    {
        int current_score = q.front().first;
        int current_pos = q.front().second;

        if( current_pos == phone_number.length() )
        {
            continue;
        }

        // Length 2
        group_numbers(q,current_score,current_pos,GROUP_LEN_2);

        // Length 3
        group_numbers(q,current_score,current_pos,GROUP_LEN_3);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    build_groups();

    cout<<dp_num[phone_number.length()-1]<<'\n';

    return  0;
}