#include    <iostream>
#include    <vector>
#include    <map>
#include    <set>
#include    <algorithm>

using namespace std;

typedef pair<int,int>   Pos;    // first: x, second: y
typedef map<int,vector<int>>    Mosquito;   

const static int    size_to_swat = 50;

void    get_mosquito_info(Mosquito& m)
{
    int n;

    cin>>n;

    for (int i=1;i<=n;i++) {
        int x,y;

        cin>>x>>y;
        m[x].push_back(y);
    }

    Mosquito::iterator  it;

    for (it=m.begin();it!=m.end();it++) {
        vector<int>&    y_pos = it->second;
        sort(y_pos.begin(),y_pos.end());
    }
}

int     simulate(Mosquito& mo)
{
    int         m;
    set<Pos>    hit;

    cin>>m;

    for (int i=1;i<=m;i++) {
        int x,y;

        cin>>x>>y;

        int min_x = x-size_to_swat;
        int max_x = x+size_to_swat;
        int min_y = y-size_to_swat;
        int max_y = y+size_to_swat;

        Mosquito::iterator  lower_x = mo.lower_bound(min_x);
        Mosquito::iterator  upper_x = mo.upper_bound(max_x);

        for (;lower_x!=upper_x;lower_x++) {
            vector<int>&    y_pos = lower_x->second;
            vector<int>::iterator   lower_y =
                lower_bound(y_pos.begin(),y_pos.end(),min_y);
            vector<int>::iterator   upper_y =
                upper_bound(y_pos.begin(),y_pos.end(),max_y);

            for (;lower_y!=upper_y;lower_y++) {
                hit.insert({lower_x->first,*lower_y});
            }
        }
    }

    return  hit.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin>>t;t>0;t--) {
        Mosquito    m;

        get_mosquito_info(m);
        cout<<simulate(m)<<'\n';
    }

    return  0;
}