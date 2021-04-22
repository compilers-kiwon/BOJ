#include    <iostream>
#include    <algorithm>
#include    <vector>

using namespace std;

#define NUM_OF_PALLETS  6

#define width   first
#define height  second

typedef pair<int,int>   Pallet; // first:width, second:height

Pallet  p[NUM_OF_PALLETS+1];

void    input(vector<int>& n)
{
    for(int i=1;i<=NUM_OF_PALLETS;i++)
    {
        n.push_back(i);
        cin>>p[i].first>>p[i].second;
    }
}

bool    can_make_box(const vector<int>& n)
{
    if( p[n[0]].width!=p[n[1]].width || p[n[1]].width!=p[n[2]].width || p[n[2]].width!=p[n[3]].width )
    {
        return  false;
    }

    if( p[n[4]].width!=p[n[0]].height || p[n[4]].width!=p[n[2]].height )
    {
        return  false;
    }

    if( p[n[5]].width!=p[n[0]].height || p[n[5]].width!=p[n[2]].height )
    {
        return  false;
    }

    if( p[n[4]].height!=p[n[3]].height || p[n[4]].height!=p[n[1]].height )
    {
        return  false;
    }

    if( p[n[5]].height!=p[n[3]].height || p[n[5]].height!=p[n[1]].height )
    {
        return  false;
    }

    return  true;
}

bool    build_box(int idx,const vector<int>& n)
{
    if( idx == NUM_OF_PALLETS )
    {
        return  can_make_box(n);
    }

    swap(p[n[idx]].width,p[n[idx]].height);

    if( build_box(idx+1,n) == true )
    {
        return  true;
    }

    swap(p[n[idx]].height,p[n[idx]].width);

    return  build_box(idx+1,n);
}

bool    simulate(vector<int>& n)
{
    do{
        if( build_box(0,n) == true )
        {
            return  true;
        }
    }while(next_permutation(n.begin(),n.end()));

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> n;

    input(n);

    if( simulate(n) == true )
    {
        cout<<"POSSIBLE\n";
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }

    return  0;
}