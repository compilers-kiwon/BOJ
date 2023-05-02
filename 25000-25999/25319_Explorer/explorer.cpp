#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_SIZE    (50+1)

static int  N,M,S;
static char grid[MAX_SIZE][MAX_SIZE+1];

typedef pair<int,int>   Pos;

static vector<Pos>  p[0x100];

#define move_to_exit(p,c,e) \
    {get_path((p),(c),(e));(p).pop_back();}

int input(string& id)
{
    cin>>N>>M>>S;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];

        for(int col=1;col<=M;col++)
        {
            p[grid[row][col]].push_back({row,col});
        }
    }

    cin>>id;
    return  0;
}

int get_max_num_of_reinforcements(const string& id)
{
    int cnt[0x100],ret;

    for(char c='a';c<='z';c++)
    {
        cnt[(int)c] = p[(int)c].size();
    }

    for(ret=0;;ret++)
    {
        bool    included = true;

        for(int i=0;i<id.length();i++)
        {
            if( cnt[(int)id[i]] == 0 )
            {
                included = false;
                break;
            }

            cnt[(int)id[i]]--;
        }

        if( !included )
        {
            break;
        }
    }

    return  ret;
}

int get_path(string& path,Pos from,Pos to)
{
    int d_row = to.first-from.first;
    int d_col = to.second-from.second;

    char    row_dir = (d_row<0)?'U':'D';
    char    col_dir = (d_col<0)?'L':'R';

    path += string(abs(d_row),row_dir);
    path += string(abs(d_col),col_dir);
    path.push_back('P');

    return  0;
}

int simulate(const string& id,string& path,
                const int num_of_inforcements)
{
    Pos current = {1,1};

    for(int i=1;i<=num_of_inforcements;i++)
    {
        for(int j=0;j<id.length();j++)
        {
            get_path(path,current,p[(int)id[j]].back());
            current = p[(int)id[j]].back();
            p[(int)id[j]].pop_back();
        }
    }

    move_to_exit(path,current,make_pair(N,M));
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  id,path;
    int     num_of_inforcements;

    input(id);
    num_of_inforcements = get_max_num_of_reinforcements(id);

    simulate(id,path,num_of_inforcements);
    cout<<num_of_inforcements<<' '<<path.length()<<'\n'<<path<<'\n';

    return  0;
}