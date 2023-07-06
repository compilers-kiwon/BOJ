#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_SIZE    (20+1)
#define char2int(c) ((int)((c)-'0'))
#define gen_zero(n) (string((n),'0'))
#define is_carry(n) ((n)>9)

static int      N,max_len;
static int      size_of_largest_group;
static string   weight[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>weight[i];
        max_len = max((int)weight[i].length(),max_len);
    }

    for(int i=1;i<=N;i++)
    {
        int num_of_leading_zero = max_len-weight[i].length();
        weight[i] = gen_zero(num_of_leading_zero)+weight[i];
    }

    return  0;
}

bool    find_carry(const vector<string>& w)
{
    for(int i=0;i<max_len;i++)
    {
        int sum = 0;

        for(int j=0;j<w.size();j++)
        {
            sum += char2int(w[j][i]);
        }
        
        if( is_carry(sum) )
        {
            return  true;
        }
    }

    return  false;
}

int dfs(int idx,vector<string>& group)
{
    if( idx > N )
    {
        size_of_largest_group = 
            max(size_of_largest_group,
                find_carry(group)?0:(int)group.size());
        
        return  0;
    }

    group.push_back(weight[idx]);
    dfs(idx+1,group);

    group.pop_back();
    dfs(idx+1,group);

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>   group;

    input();
    dfs(1,group);

    cout<<size_of_largest_group<<'\n';
    return  0;
}