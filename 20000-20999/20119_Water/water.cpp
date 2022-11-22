#include    <iostream>
#include    <set>
#include    <queue>
#include    <vector>

using namespace std;

#define MAX_SIZE    (200000+1)

int                 N,M,L,cnt;
bool                in_hands[MAX_SIZE];
vector<set<int>>    recipe[MAX_SIZE];
set<int>            used_for[MAX_SIZE];
queue<int>          current;

#define get_water(w) {in_hands[(w)]=true;cnt++;current.push((w));}

void    read_recipe(set<int>& src,int& result)
{
    int k;

    cin>>k;

    for(int i=1;i<=k;i++)
    {
        int x;

        cin>>x;
        src.insert(x);
    }

    cin>>result;
}

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=M;i++)
    {
        int         r;
        set<int>    src;

        read_recipe(src,r);
        recipe[r].push_back(src);

        for(set<int>::iterator it=src.begin();it!=src.end();it++)
        {
            used_for[*it].insert(r);            
        }
    }

    cin>>L;

    for(int i=1;i<=L;i++)
    {
        int y;

        cin>>y;
        get_water(y);
    }
}

bool    mix_water(vector<set<int>>& recipes,int src_water)
{
    for(int i=0;i<recipes.size();i++)
    {
        set<int>&   recipe_to_be_checked = recipes[i];

        recipe_to_be_checked.erase(src_water);

        if( recipe_to_be_checked.empty() )
        {
            return  true;
        }
    }

    return  false;
}

void    simulate(void)
{
    for(;!current.empty();)
    {
        for(int i=1,size=current.size();i<=size;i++,current.pop())
        {
            int         current_water = current.front();
            set<int>&   can_make = used_for[current_water];

            for(set<int>::iterator it=can_make.begin();it!=can_make.end();it++)
            {
                int target_water = *it;

                if( in_hands[target_water] == true )
                {
                    continue;
                }

                if( mix_water(recipe[target_water],current_water) == true )
                {
                    get_water(target_water);
                }
            }
        }
    }
}

void    print(void)
{
    cout<<cnt<<'\n';

    for(int i=1;i<=N;i++)
    {
        if( in_hands[i] == true )
        {
            cout<<i<<' ';
        }
    }

    cout<<'\n';
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return  0;
}