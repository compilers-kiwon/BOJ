#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>
#include    <set>

using namespace std;

typedef vector<string>      NextItem;
typedef pair<int,NextItem>  State;      // first:num_of_prepurchased_items, second:dependent items on me

map<string,State>   items[0x100];
vector<string>      out_buf;

int     input(set<string>& purchasable)
{
    int N,ret;

    cin>>N;
    ret = 0;

    for(int i=1;i<=N;i++)
    {
        string  item1,item2;

        cin>>item1>>item2;

        items[item1[0]][item1].second.push_back(item2);
        items[item2[0]][item2].first++;
    }

    for(char c='a';c<='z';c++)
    {
        for(map<string,State>::iterator it=items[c].begin();it!=items[c].end();it++)
        {
            if( it->second.first == 0 )
            {
                purchasable.insert(it->first);
            }
        }

        ret += items[c].size();
    }

    return  ret;
}

void    simulate(set<string>& purchasable)
{
    for(;!purchasable.empty();)
    {
        vector<string>  tmp;

        for(set<string>::iterator it=purchasable.begin();it!=purchasable.end();it++)
        {
            vector<string>& next = items[(*it)[0]][*it].second;

            for(int i=0;i<next.size();i++)
            {
                if( --items[next[i][0]][next[i]].first == 0 )
                {
                    tmp.push_back(next[i]);
                }
            }

            items[(*it)[0]].erase(*it);
            out_buf.push_back(*it);
        }

        purchasable.clear();

        for(int i=0;i<tmp.size();i++)
        {
            purchasable.insert(tmp[i]);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         num_of_items;
    set<string> p;

    num_of_items = input(p);
    simulate(p);

    if( out_buf.size() == num_of_items )
    {
        for(int i=0;i<out_buf.size();i++)
        {
            cout<<out_buf[i]<<'\n';
        }
    }
    else
    {
        cout<<"-1\n";
    }

    return  0;
}