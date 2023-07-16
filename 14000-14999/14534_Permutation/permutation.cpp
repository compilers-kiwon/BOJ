#include    <iostream>
#include    <string>
#include    <vector>
#include    <algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        string      L;
        vector<int> idx;

        cin>>L;
        cout<<"Case # "<<t<<":\n";

        for(int i=0;i<L.length();i++) idx.push_back(i);

        do{
            string  tmp;
            for(int i=0;i<idx.size();i++) tmp.push_back(L[idx[i]]);
            cout<<tmp<<'\n';
        } while(next_permutation(idx.begin(),idx.end()));
    }

    return  0;
}