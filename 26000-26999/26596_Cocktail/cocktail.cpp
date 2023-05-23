#include    <iostream>
#include    <string>
#include    <map>
#include    <set>

using namespace std;

#define get_golden_ratio(n) ((n)*1618/1000)

int input(map<string,int>& material)
{
    int M;

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        string  s;
        int     q;

        cin>>s>>q;
        material[s] += q;
    }

    return  0;
}

int get_material_quantity(set<int>& q,
            map<string,int>& m,map<int,int>& cnt)
{
    map<string,int>::iterator   it;

    for(it=m.begin();it!=m.end();it++)
    {
        q.insert(it->second);
        cnt[it->second]++;
    }

    return  0;
}

int is_delicious(const set<int>& q,map<int,int>& cnt)
{
    set<int>::iterator  it;

    for(it=q.begin();it!=q.end();it++)
    {
        int golden_ratio = get_golden_ratio(*it);

        if( q.find(golden_ratio)!=q.end() &&
                ((*it)!=golden_ratio || cnt[golden_ratio]>=2) )
        {
            return  true;
        }
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<int> quantities;
    map<string,int> materials;
    map<int,int> q_count;

    input(materials);
    get_material_quantity(quantities,materials,q_count);

    cout<<(is_delicious(quantities,q_count)?
            "Delicious!":"Not Delicious...")<<'\n';

    return  0;
}