#include    <iostream>
#include    <algorithm>
#include    <vector>

using namespace std;

#define MIN_NUM             1
#define MAX_NUM             1000
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int         n;
vector<int> S;

void    input(void)
{
    int L;

    cin>>L;

    for(int i=1;i<=L;i++)
    {
        int num;

        cin>>num;
        S.push_back(num);
    }

    cin>>n;
    sort(S.begin(),S.end());
}

int     get_cnt_of_good_interval(void)
{
    int ret = 0;

    for(int A=MIN_NUM;A<=MAX_NUM;A++)
    {
        for(int B=A+1;B<=MAX_NUM;B++)
        {
            if( !IN_RANGE(A,n,B) )
            {
                continue;
            }

            if( lower_bound(S.begin(),S.end(),A) != upper_bound(S.begin(),S.end(),B) )
            {
                continue;
            }

            ret++;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_cnt_of_good_interval()<<'\n';

    return  0;
}