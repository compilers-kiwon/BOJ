#include    <iostream>
#include    <set>
#include    <map>

using namespace std;

#define LEFT    0
#define RIGHT   1
#define OFFSET  500

#define TRUE    1
#define FALSE   0

#define NUM_OF_WHEELS   4

#define add_record(s,m,n,d) ((s).insert((n)),(m)[(n)]=(d))

int input(set<int>& a,map<int,int>& r)
{
    int n;

    cin>>n;

    for(int d=LEFT;d<=RIGHT;d++)
    {
        for(int i=1;i<=n;i++)
        {
            int m;

            cin>>m;
            add_record(a,r,m,d);
        }
    }

    return  0;
}

int build_time_info(int t[],int base)
{
    for(int i=0;i<NUM_OF_WHEELS;i++)
    {
        t[i] = base+OFFSET*i;
    }

    return  0;
}

int check_integrity(map<int,int>& table,int t[])
{
    for(int i=0;i<NUM_OF_WHEELS;i++)
    {
        int d = (i&(RIGHT<<1))?RIGHT:LEFT;

        if( table[t[i]] != d )
        {
            return  FALSE;
        }
    }

    return  TRUE;
}

int remove_data(map<int,int>& table,int t[])
{
    for(int i=0;i<NUM_OF_WHEELS;i++)
    {
        table.erase(t[i]);
    }

    return  0;
}

int simulate(set<int>& a,map<int,int>& r)
{
    int ret = 0;

    for(set<int>::iterator it=a.begin();it!=a.end();it++)
    {
        int t[NUM_OF_WHEELS];

        build_time_info(t,*it);
        
        if( check_integrity(r,t) == FALSE )
        {
            continue;
        }

        ret++;
        remove_data(r,t);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        set<int> all;
        map<int,int> rec;

        input(all,rec);
        cout<<simulate(all,rec)<<'\n';
    }

    return  0;
}