#include    <iostream>
#include    <vector>
#include    <map>

using namespace std;

#define MAX_SIZE    (1000+1)
#define NONE        0

int         k;
vector<int> photo[MAX_SIZE];

void    input(void)
{
    cin>>k;

    for(int i=1;i<=k;i++)
    {
        int n;

        cin>>n;

        for(int j=1;j<=n;j++)
        {
            int t;

            cin>>t;
            photo[i].push_back(t);
        }
    }
}

void    delete_data(int n,map<int,int>& m)
{
    m[n]--;

    if( m[n] == 0 )
    {
        m.erase(n);
    }
}

int     find_taller(int n,map<int,int>& m)
{
    map<int,int>::iterator  it = m.upper_bound(n);

    if( it == m.end() )
    {
        return  NONE;
    }

    return  it->first;
}

bool    find_family(int idx)
{
    vector<int>&    p = photo[idx];
    map<int,int>    left,right;

    // init
    for(int i=0;i<p.size();i++)
    {
        right[p[i]]++;
    }

    // find
    for(int i=0;i<p.size();i++)
    {
        int left_t,mid_t,right_t;

        // 1. get mid and delete mid from right
        mid_t = p[i];
        delete_data(mid_t,right);
        
        // 2. find mid<left<right
        if( (left_t=find_taller(mid_t,left))!=NONE
            && (right_t=find_taller(left_t,right)!=NONE) )
        {
            return  true;
        }

        // 3. add mid to left
        left[mid_t]++;
    }

    return  false;
}

void    find_family_photo(vector<int>& p)
{
    for(int i=1;i<=k;i++)
    {
        if( find_family(i) == true )
        {
            p.push_back(i);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> family_photo;

    input();
    find_family_photo(family_photo);

    cout<<family_photo.size()<<'\n';

    for(int i=0;i<family_photo.size();i++)
    {
        cout<<family_photo[i]<<'\n';
    }

    return  0;
}