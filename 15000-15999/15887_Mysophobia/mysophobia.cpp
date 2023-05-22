#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (1000+1)

#define update_pos(p_arr,n_arr,p1,p2) \
    ((p_arr)[(n_arr)[(p1)]]=(p1),(p_arr)[(n_arr)[(p2)]]=(p2))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<pair<int,int>> r;
    int N,arr[MAX_SIZE],pos[MAX_SIZE];
    
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
        pos[arr[i]] = i;
    }

    for(int i=1;i<=N;i++)
    {
        if( pos[i] == i )
        {
            continue;
        }

        int L = i;
        int R = pos[i];

        for(int h=L,t=R;h<t;h++,t--)
        {
            swap(arr[h],arr[t]);
            update_pos(pos,arr,h,t);
        }

        r.push_back({L,R});
    }

    cout<<r.size()<<'\n';

    for(int i=0;i<r.size();i++)
    {
        cout<<r[i].first<<' '<<r[i].second<<'\n';
    }

    return  0;
}