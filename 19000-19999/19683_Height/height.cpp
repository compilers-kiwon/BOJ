#include    <iostream>
#include    <map>

using namespace std;

typedef map<int,int>::reverse_iterator  Iterator;

#define get_biggest(m)  ((m).rbegin())

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             N,H,T,num_of_total_hits;
    map<int,int>    giant;

    cin>>N>>H>>T;

    for(int i=1;i<=N;i++)
    {
        int h;

        cin>>h;
        giant[h]++;
    }

    for(num_of_total_hits=0;num_of_total_hits<T;)
    {
        Iterator    biggest = get_biggest(giant);
        int         num_of_hit_giants;

        if( biggest->first==1 || biggest->first<H )
        {
            break;
        }

        num_of_hit_giants =
                min(T-num_of_total_hits,biggest->second);

        giant[biggest->first/2] += num_of_hit_giants;
        num_of_total_hits += num_of_hit_giants;
        biggest->second -= num_of_hit_giants;

        if( biggest->second == 0 )
        {
            giant.erase(biggest->first);
        }
    }

    if( get_biggest(giant)->first < H )
    {
        cout<<"YES\n"<<num_of_total_hits<<'\n';
    }
    else
    {
        cout<<"NO\n"<<get_biggest(giant)->first<<'\n';
    }

    return  0;
}