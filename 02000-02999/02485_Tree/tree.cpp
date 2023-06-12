#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

int input(vector<int>& pos)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int p;

        cin>>p;
        pos.push_back(p);
    }

    return  0;
}

int get_gcd(int n1,int n2)
{
    int big = max(n1,n2);
    int small = min(n1,n2);
    
    for(int mod=big%small;mod!=0;mod=big%small)
    {
        big = small;
        small = mod;
    }

    return  small;
}

int get_num_of_new_trees(const vector<int>& pos)
{
    int prev_gcd = pos[1]-pos[0];

    for(int i=2;i<pos.size();i++)
    {
        prev_gcd = get_gcd(prev_gcd,pos[i]-pos[i-1]);
    }

    int ret = 0;

    for(int i=1;i<pos.size();i++)
    {
        ret += (pos[i]-pos[i-1])/prev_gcd-1;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> pos;

    input(pos);
    sort(pos.begin(),pos.end());

    cout<<get_num_of_new_trees(pos)<<'\n';

    return  0;
}