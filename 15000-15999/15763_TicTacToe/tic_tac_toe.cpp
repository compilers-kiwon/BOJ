#include    <iostream>
#include    <string>
#include    <set>

using namespace std;

#define SIZE            3
#define NUM_OF_LINES    8

typedef pair<int,int>   Pos;

struct{Pos s,offset;} line[NUM_OF_LINES] = {
    {{1,1},{0,1}},{{1,1},{1,0}},{{1,1},{1,1}},{{1,2},{1,0}},
    {{1,3},{1,0}},{{1,3},{1,-1}},{{2,1},{0,1}},{{3,1},{0,1}}
};

static char     grid[SIZE+1][SIZE+2];
static string   line_str[NUM_OF_LINES];

int get_line_str(int line_idx)
{
    string& s = line_str[line_idx];

    for(int row=line[line_idx].s.first,col=line[line_idx].s.second,len=0;
        len<SIZE;
        row+=line[line_idx].offset.first,col+=line[line_idx].offset.second,len++)
    {
        s.push_back(grid[row][col]);
    }
    
    return  0;
}

string  get_team_members(const string& s)
{
    string  ret;

    for(int i=0;i<s.length();i++)
    {
        if( ret.find(s[i]) == string::npos )
        {
            ret.push_back(s[i]);
        }
    }

    if( ret.front() > ret.back() )
    {
        swap(ret.front(),ret.back());
    }

    return  ret;
}

int get_num_of_winners(int num_of_players)
{
    set<string> winners;

    for(int i=0;i<NUM_OF_LINES;i++)
    {
        string  team = get_team_members(line_str[i]);

        if( team.length() == num_of_players )
        {
            winners.insert(team);
        }
    }

    return  winners.size();
}

int input(void)
{
    for(int row=1;row<=SIZE;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=0;i<NUM_OF_LINES;i++)
    {
        get_line_str(i);
    }

    cout<<get_num_of_winners(1)<<'\n'
            << get_num_of_winners(2)<<'\n';

    return  0;
}