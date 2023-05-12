#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

typedef pair<int,int>   Result; // first:time,second:score

static int  n;
static Result   r[MAX_SIZE];

int input(void)
{
    int max_score = 0;
    int min_time = 0x7FFFFFFF;
    int ret;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int&    t = r[i].first;
        int&    s = r[i].second;

        cin>>t>>s;

        if( s>max_score || (s==max_score && t<min_time) )
        {
            min_time = t;
            max_score = s;
            ret = i;
        }
    }

    return  ret;
}

int get_penalty(int idx)
{
    int&    t = r[idx].first;
    int&    s = r[idx].second;

    return  (s==0)?0:t+(idx-1)*20;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int f;

    f = input();
    cout<<get_penalty(f)<<'\n';

    return  0;
}