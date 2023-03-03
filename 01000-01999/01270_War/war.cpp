#include    <iostream>
#include    <map>

using namespace std;

typedef long long int   int64;

#define NONE        (1LL<<32)
#define NONE_STR    "SYJKGW"

#define EXCEED_HALF(current,total)  ((current)*2>(total))

int64 find_conqueror(int total_soldiers,
            map<int64,int>& num_of_soldiers)
{
    int64 ret = NONE;
    map<int64,int>::iterator it;
    
    for(it=num_of_soldiers.begin();it!=num_of_soldiers.end();it++)
    {
        if( EXCEED_HALF(it->second,total_soldiers) )
        {
            ret = it->first;
            break;
        }
    }

    return  ret;
}

int64 simulate(void)
{
    int T;
    map<int64,int>  num_of_soldiers;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        int64   N;

        cin>>N;
        num_of_soldiers[N]++;
    }

    return  find_conqueror(T,num_of_soldiers);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int64   conqueror;

        if( (conqueror=simulate()) == NONE )
        {
            cout<<NONE_STR<<"\n";
        }
        else
        {
            cout<<conqueror<<'\n';
        }
    }

    return  0;
}