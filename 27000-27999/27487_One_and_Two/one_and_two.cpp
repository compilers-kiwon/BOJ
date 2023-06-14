#include    <iostream>
#include    <vector>

using namespace std;

int get_pos(vector<int>& p)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a;

        cin>>a;

        if( a == 2 )
        {
            p.push_back(i);
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for(;t>0;t--)
    {
        vector<int> p;

        get_pos(p);
        cout<<((p.size()==0)?1:
            (p.size()%2==1)?-1:p[(p.size()-1)/2])<<'\n';
    }

    return  0;
}