#include    <iostream>
#include    <string>
#include    <set>
#include    <map>

using namespace std;

#define SIZE_OF_TABLE   9

#define ROW_OF_FINAL_GOAL   (SIZE_OF_TABLE/2)
#define COL_OF_FINAL_GOAL   (SIZE_OF_TABLE/2)

#define erase_str(str,flag) ((str)=(flag)?"":(str))
#define get_final_goal(arr) ((arr)[ROW_OF_FINAL_GOAL][COL_OF_FINAL_GOAL])

static string   mandala[SIZE_OF_TABLE][SIZE_OF_TABLE];

int get_pos_of_goal(const string& goal,int& row,int& col)
{
    for(row=0;row<SIZE_OF_TABLE;row++)
    {
        for(col=0;col<SIZE_OF_TABLE;col++)
        {
            if( goal == mandala[row][col] )
            {
                return  0;
            }
        }
    }

    return  0;
}

int get_sub_goals(const string parent,
            set<string>& sub,bool erase_flag)
{
    int     row,col;

    get_pos_of_goal(parent,row,col);

    for(int d_row=-1;d_row<=1;d_row++)
    {
        for(int d_col=-1;d_col<=1;d_col++)
        {                        
            sub.insert(mandala[row+d_row][col+d_col]);
            erase_str(mandala[row+d_row][col+d_col],erase_flag);
        }
    }
    
    sub.erase(parent);
    return  0;
}

int input(void)
{
    for(int row=0;row<SIZE_OF_TABLE;row++)
    {
        for(int col=0;col<SIZE_OF_TABLE;col++)
        {
            cin>>mandala[row][col];
        }
    }

    return  0;
}

int get_subs_of_final_goal(set<string>& subs)
{
    get_sub_goals(get_final_goal(mandala),subs,true);
    return  0;
}

int print_sub_goals(string goal,int idx)
{
    set<string> s;

    get_sub_goals(goal,s,false);
    cout<<"#"<<idx<<". "<<goal<<'\n';

    set<string>::iterator it = s.begin();

    for(int i=1;it!=s.end();it++,i++)
    {
        cout<<"#"<<idx<<"-"<<i<<". "<<(*it)<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<string> subs;

    input();
    get_subs_of_final_goal(subs);

    set<string>::iterator   it = subs.begin();

    for(int i=1;it!=subs.end();it++,i++)
    {
        print_sub_goals((*it),i);
    }

    return  0;
}