#include    <iostream>
#include    <string>

using namespace std;

void    init(int* score_table)
{
    fill(score_table,score_table+0x100,0);

    score_table['A'] = 4;
    score_table['K'] = 3;
    score_table['Q'] = 2;
    score_table['J'] = 1;
}

int     get_score(const string& str,const int* score_table)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret += score_table[str[i]];
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,score_table[0x100],sum;

    cin>>N;
    init(score_table);

    sum = 0;

    for(int i=1;i<=N;i++)
    {
        string  K;

        cin>>K;
        sum += get_score(K,score_table);
    }

    cout<<sum<<'\n';

    return  0;
}