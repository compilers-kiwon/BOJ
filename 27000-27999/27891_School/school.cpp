#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static map<string,string> encrypted = {
    {"csboltpnfi","BHA"},{"noejcinwpm","SJA"},
    {"koreainter","KIS"},{"northlondo","NLCS"}
};


string  get_school_name(const string& s)
{
    map<string,string>::iterator    it;

    for(it=encrypted.begin();it!=encrypted.end();it++)
    {
        string  t = it->first;

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<t.length();j++)
            {
                t[j]++;
                t[j] = (t[j]>'z')?'a':t[j];
            }

            if( s == t )
            {
                return  it->second;
            }
        }
    }

    return  "";
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string  str;

    cin>>str;
    cout<<get_school_name(str)<<'\n';

    return  0;
}