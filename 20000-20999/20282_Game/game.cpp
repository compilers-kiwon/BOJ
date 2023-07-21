#include    <iostream>

using namespace std;

#define DEFAULT_MONEY 100

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int C,cur_award,max_award;

    cin>>C;
    cur_award = max_award = DEFAULT_MONEY;

    for(int i=1;i<=C;i++)
    {
        int V;

        cin>>V;

        cur_award += V;
        max_award = max(max_award,cur_award);
    }

    cout<<max_award<<'\n';
    return  0;
}