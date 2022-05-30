#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

int find_head_tree(const vector<int>& t,int tree)
{
    int ret = 0;

    for(int i=0;i<t.size();i++)
    {
        if( t[i] == tree )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int find_tail_tree(const vector<int>& t,int tree)
{
    int ret = 0;

    for(int i=t.size()-1;i>=0;i--)
    {
        if( t[i] == tree )
        {
            ret = i;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         n,max_distance,h,t;
    vector<int> tree;

    cin>>n;
    max_distance = 0;

    for(int i=1;i<=n;i++)
    {
        int a;

        cin>>a;
        tree.push_back(a);
    }

    h = find_head_tree(tree,0);
    t = find_tail_tree(tree,0);

    for(int i=0;i<n;i++)
    {
        if( tree[i] == 1 )
        {
            max_distance = max(max_distance,max(abs(h-i),abs(t-i)));
        }
    }

    cout<<max_distance<<'\n';

    return  0;
}