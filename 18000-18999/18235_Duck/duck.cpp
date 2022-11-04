#include    <iostream>
#include    <queue>
#include    <set>

using namespace std;

#define NONE                -1
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int simulate(int max_len,int d1,int d2)
{
    int         ret = NONE;
    queue<int>  q1,q2;

    q1.push(d1);q2.push(d2);

    for(int offset=1,day=1;ret==NONE&&!q1.empty()&&!q2.empty();offset<<=1,day++)
    {
        set<int>    pos;

        for(int i=1,size=q1.size();i<=size;i++,q1.pop())
        {
            int current_pos = q1.front();
            int left_pos = current_pos-offset;
            int right_pos = current_pos+offset;

            if( IN_RANGE(1,left_pos,max_len) )
            {
                q1.push(left_pos);
                pos.insert(left_pos);
            }

            if( IN_RANGE(1,right_pos,max_len) )
            {
                q1.push(right_pos);
                pos.insert(right_pos);
            }
        }

        for(int i=1,size=q2.size();i<=size;i++,q2.pop())
        {
            int current_pos = q2.front();
            int left_pos = current_pos-offset;
            int right_pos = current_pos+offset;

            if( IN_RANGE(1,left_pos,max_len) )
            {
                q2.push(left_pos);

                if( pos.find(left_pos) != pos.end() )
                {
                    ret = day;
                    break;
                }
            }

            if( IN_RANGE(1,right_pos,max_len) )
            {
                q2.push(right_pos);

                if( pos.find(right_pos) != pos.end() )
                {
                    ret = day;
                    break;
                }
            }
        }
    }

    return  ret;
}


int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A,B;

    cin>>N>>A>>B;
    cout<<simulate(N,A,B)<<'\n';

    return  0;
}