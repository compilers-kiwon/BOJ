#include    <iostream>

using namespace std;

#define MAX_SIZE    3
#define MAX_NUM     2

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt[MAX_NUM+1],max_cnt,answer;

    fill(&cnt[1],&cnt[MAX_NUM+1],0);

    for(int i=1;i<=MAX_SIZE;i++)
    {
        int n;

        cin>>n;
        cnt[n]++;
    }

    max_cnt = answer = 0;

    for(int i=1;i<=MAX_NUM;i++)
    {
        if( cnt[i] > max_cnt )
        {
            answer = i;
            max_cnt = cnt[i];
        }
    }

    cout<<answer<<'\n';

    return  0;
}