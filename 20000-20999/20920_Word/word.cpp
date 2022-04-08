#include    <iostream>
#include    <string>
#include    <vector>
#include    <algorithm>
#include    <map>

using namespace std;

int             N,M;
map<string,int> cnt;

typedef pair<pair<int,int>,string>    State;  // first:<first:count,second:length>,second:string

void    input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;

        if( str.length() < M )
        {
            continue;
        }

        cnt[str]++;
    }
}

void    build_word_list(vector<State>& word_list)
{
    map<string,int>::iterator   it;

    for(it=cnt.begin();it!=cnt.end();it++)
    {
        word_list.push_back(make_pair(make_pair(-(it->second),-(it->first.length())),it->first));
    }

    sort(word_list.begin(),word_list.end());
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    vector<State>   words;

    input();
    build_word_list(words);

    for(int i=0;i<words.size();i++)
    {
        cout<<words[i].second<<'\n';
    }

    return  0;
}