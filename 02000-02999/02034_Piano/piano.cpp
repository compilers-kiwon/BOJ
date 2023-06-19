#include    <iostream>
#include    <vector>
#include    <set>

using namespace std;

#define MAX_SIZE    (12)
#define SHARP       '#'

const static string str = "A#BC#D#EF#G#";

#define get_next(cur,offset)    (((cur)+MAX_SIZE+(offset))%MAX_SIZE)

int simulate(int s,const vector<int>& offset)
{
    char    c = str[s];

    for(int i=0;i<offset.size();i++,c=str[s])
    {
        if(c==SHARP) break;
        s = get_next(s,offset[i]);
    }

    return  c;
}

int input(vector<int>& offset)
{
    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int o;

        cin>>o;
        offset.push_back(o);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    set<pair<char,char>>    answers;
    vector<int> offset;

    input(offset);

    for(int i=0;i<MAX_SIZE;i++)
    {
        char    c;

        if( (c=simulate(i,offset)) != SHARP )
        {
            answers.insert({str[i],c});
        }
    }

    set<pair<char,char>>::iterator  it;

    for(it=answers.begin();it!=answers.end();it++)
    {
        cout<<it->first<<' '<<it->second<<'\n';
    }

    return  0;
}