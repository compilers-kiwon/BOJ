#include    <iostream>
#include    <set>

using namespace std;

#define OFFSET_TABLE_SIZE   5
#define SEQ_LEN             5

const int offset_table[OFFSET_TABLE_SIZE][SEQ_LEN] = {
    {-4,-3,-2,-1,0},{-3,-2,-1,0,1},{-2,-1,0,1,2},{-1,0,1,2,3},{0,1,2,3,4}
};

int     get_min_num_of_required_numbers(int n,const set<int>& s)
{
    int ret = SEQ_LEN;

    for(int i=0;i<OFFSET_TABLE_SIZE;i++)
    {
        int cnt_of_missed_numbers = 0;

        for(int j=0;j<SEQ_LEN;j++)
        {
            if( s.find(n+offset_table[i][j]) == s.end() )
            {
                cnt_of_missed_numbers++;
            }
        }

        ret = min(ret,cnt_of_missed_numbers);
    }

    return  ret;
}

void    input(set<int>& s)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int n;

        cin>>n;
        s.insert(n);
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         answer;
    set<int>    s;

    input(s);
    answer = SEQ_LEN;

    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        answer = min(answer,get_min_num_of_required_numbers(*it,s));
    }

    cout<<answer<<'\n';

    return  0;
}