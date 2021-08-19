#include    <iostream>
#include    <vector>

using namespace std;

#define SIZE_OF_WAIT    13
#define MAX_NUM         9
#define HEAD_LEN        2
#define BODY_LEN        3

int cnt[MAX_NUM+1];

int     get_num_of_heads(void)
{
    int ret = 0;

    for(int i=1;i<=MAX_NUM;i++)
    {
        if( cnt[i] == HEAD_LEN )
        {
            ret++;
        }
    }

    return  ret;
}

void    dfs(int n,int current_body,int& max_body)
{
    if( n == MAX_NUM+1 )
    {
        max_body = max(max_body,current_body);
        return;
    }

    if( cnt[n] == 0 )
    {
        dfs(n+1,current_body,max_body);
    }
    else
    {
        if( cnt[n] >= BODY_LEN )
        {
            cnt[n] -= BODY_LEN;
            dfs(n,current_body+1,max_body);
            cnt[n] += BODY_LEN;
        }

        if( n+2<=MAX_NUM && cnt[n]!=0 && cnt[n+1]!=0 && cnt[n+2]!=0 )
        {
            cnt[n]--;cnt[n+1]--;cnt[n+2]--;
            dfs(n,current_body+1,max_body);
            cnt[n]++;cnt[n+1]++;cnt[n+2]++;
        }
    }
}

int     get_num_of_body(void)
{
    int ret = 0;

    dfs(1,0,ret);

    return  ret;
}

bool    can_be_completed(void)
{
    if( get_num_of_heads() == 7 )
    {
        return  true;
    }

    for(int i=1;i<=MAX_NUM;i++)
    {
        if( cnt[i] >= HEAD_LEN )
        {
            int num_of_body;

            cnt[i] -= HEAD_LEN;
            num_of_body = get_num_of_body();
            cnt[i] += HEAD_LEN;

            if( num_of_body == 4 )
            {
                return  true;
            }
        }
    }

    return  false;
}

void    get_candidate_num(vector<int>& c)
{
    for(int i=1;i<=MAX_NUM;i++)
    {
        int num_of_head,num_of_body;

        if( cnt[i] >= 4 )
        {
            continue;
        }

        cnt[i]++;

        if( can_be_completed() == true )
        {
            c.push_back(i);
        }

        cnt[i]--;
    }
}

void    print(const vector<int>& v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }

    cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;i<=SIZE_OF_WAIT;i++)
    {
        int n;

        cin>>n;
        cnt[n]++;
    }

    vector<int> c;

    get_candidate_num(c);
    
    if( c.empty() ) c.push_back(-1);
    print(c);

    return  0;
}

