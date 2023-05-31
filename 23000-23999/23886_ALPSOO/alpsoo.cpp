#include    <iostream>
#include    <string>
#include    <vector>
#include    <cmath>

using namespace std;

#define FLAT    0
#define get_sign(n) ((n)/abs((n)))

int get_inclination(const string& num,
                        vector<int>& inc)
{
    for(int i=1;i<num.length();i++)
    {
        inc.push_back(num[i]-num[i-1]);
    }

    return  0;
}

bool    is_alpsoo(const vector<int>& inc)
{
    if( !(inc.front()>0 && inc.back()<0) )
    {
        return  false;
    }

    for(int i=1;i<inc.size();i++)
    {
        if( inc[i] == FLAT )
        {
            return  false;
        }

        if( inc[i-1]!=inc[i] &&
                get_sign(inc[i-1])==get_sign(inc[i]) )
        {
            return  false;
        }
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  X;
    vector<int> inc;

    cin>>X;
    get_inclination(X,inc);

    cout<<(is_alpsoo(inc)?
        "ALPSOO":"NON ALPSOO")<<'\n';

    return  0;
}