#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>

using namespace std;

#define get_suffix(w,l) ((w).substr((w).length()-l))

int get_num_of_pairs(map<string,int>& rhymes)
{
    int cnt = 0;
    map<string,int>::iterator   it;

    for (it=rhymes.begin();it!=rhymes.end();it++) {
        cnt += it->second>>1;
    }

    return  cnt;
}

int get_rhymes(const vector<string>& words,
                int len_of_suffix,map<string,int>& rhymes)
{
    for (int i=0;i<words.size();i++) {
        rhymes[get_suffix(words[i],len_of_suffix)]++;
    }

    return  0;
}

int input(vector<string>& words)
{
    int n,L,F;

    cin>>n>>L>>F;

    for (int i=1;i<=n;i++) {
        string  s;
        cin>>s;
        words.push_back(s);
    }

    return  F;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        int len_of_suffix;
        vector<string>  W;
        map<string,int> rhymes;

        len_of_suffix = input(W);
        get_rhymes(W,len_of_suffix,rhymes);
        cout<<get_num_of_pairs(rhymes)<<'\n';
    }

    return  0;
}