#include    <iostream>
#include    <string>
#include    <vector>
#include    <algorithm>

using namespace std;

bool    is_bigger(const string& s1,
                    const string& s2)
{
    return  ((s1+s2)>(s2+s1));
}

int     input(vector<string>& v)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  s;

        cin>>s;
        v.push_back(s);
    }

    return  0;
}

int     print(const vector<string>& v)
{
    if( v.front().front() == '0' )
    {
        cout<<"0\n";
        return  0;
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }

    cout<<'\n';
    return  0;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>  number;

    input(number);
    sort(number.begin(),number.end(),is_bigger);
    print(number);
    
    return  0;
}