#include    <iostream>
#include    <string>
#include    <queue>
#include    <set>
#include    <map>

using namespace std;

#define MAX_DAYS        100
#define INIT_PRODUCE    7

typedef pair<int,pair<string,string>>   Record;

static priority_queue<Record>   pq;

static set<string>      displayed;
static map<string,int>  produced;

#define init_cow_info(n) \
    {produced[(n)]=INIT_PRODUCE;displayed.insert((n));}

int input(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int     d;
        string  c,q;

        cin>>d>>c>>q;
        pq.push({-d,{c,q}});
    }

    init_cow_info("Bessie");
    init_cow_info("Elsie");
    init_cow_info("Mildred");

    return  0;
}

int find_cows_to_be_displayed(set<string>& updated)
{   
    int max_quantity = 0;
    map<string,int>::iterator   it;

    for(it=produced.begin();it!=produced.end();it++)
    {
        if( max_quantity <= it->second )
        {
            if( max_quantity < it->second )
            {
                updated.clear();
            }

            max_quantity = it->second;
            updated.insert(it->first);
        }
    }

    return  0;
}

int simulate(void)
{
    int ret;

    for(ret=0;!pq.empty();pq.pop())
    {
        set<string> updated;

        string  cow = pq.top().second.first;
        string  milk = pq.top().second.second;
        int     quantity = stoi(milk);
        
        produced[cow] += quantity;
        find_cows_to_be_displayed(updated);

        if( displayed != updated )
        {
            ret++;
            displayed = updated;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}