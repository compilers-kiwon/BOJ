#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

string  get_suffix(const string& str)
{
    string  ret;

    for (int i=str.length()-1;i>=0;i--) {
        if (ret.empty() || str[i]>ret.back()) ret.push_back(str[i]);
        else break;
    }

    reverse(ret.begin(),ret.end());
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin>>t;t>0;t--) {
        string  str;

        cin>>str;
        cout<<"The longest decreasing suffix of "
                <<str<<" is "<<get_suffix(str)<<'\n';
    }

    return  0;
}