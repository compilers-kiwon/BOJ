#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

typedef pair<int,int>   Rope;   // first:-A,second:B;

void    input(priority_queue<Rope>& rq)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int A,B;

        cin>>A>>B;
        rq.push(make_pair(-A,B));
    }
}

int     find_num_of_bigger_pos(const vector<int>& prev_ropes,int current_rope)
{
    int ret = 0;

    for(int i=0;i<prev_ropes.size();i++)
    {
        if( prev_ropes[i] > current_rope )
        {
            ret++;
        }
    }

    return  ret;
}

int     get_num_of_intersections(priority_queue<Rope>& rq)
{
    int         ret = 0;
    vector<int> pos;

    for(;!rq.empty();rq.pop())
    {
        int B = rq.top().second;

        ret += find_num_of_bigger_pos(pos,B);
        pos.push_back(B);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        priority_queue<Rope>    rope_q;

        input(rope_q);
        cout<<"Case #"<<t<<": "<<get_num_of_intersections(rope_q)<<'\n';
    }

    return  0;
}