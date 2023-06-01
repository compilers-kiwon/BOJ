#include    <iostream>
#include    <vector>

using namespace std;

int get_num_of_peaks(const vector<int>& v)
{
    int ret = 0;

    for(int i=1;i<v.size()-1;i++)
    {
        int before = v[i-1];
        int current = v[i];
        int next = v[i+1];

        ret += (current>before&&current>next)?1:0;
    }

    return  ret;
}

bool    input(vector<int>& data)
{
    int n;

    cin>>n;
    if (n==0) return false;

    for(int i=1;i<=n;i++)
    {
        int v;

        cin>>v;
        data.push_back(v);
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        vector<int> v = {0};

        if (input(v)==false) break;
        cout<<get_num_of_peaks(v)<<'\n';
    }

    return  0;
}