#include    <iostream>
#include    <string>
#include    <set>
#include    <cmath>

using namespace std;

typedef pair<int,int>   Pos;

#define NUM_OF_ROWS (3)

const static string keyboard[NUM_OF_ROWS] = {
    "qwertyuiop","asdfghjkl","zxcvbnm"
};

static Pos  p[0x100];

#define get_distance(a,b)   \
    (abs(p[(a)].first-p[(b)].first)+abs(p[(a)].second-p[(b)].second))

int init(void)
{
    for (int row=0;row<NUM_OF_ROWS;row++) {
        const string&   k = keyboard[row];
        for (int col=0;col<k.length();col++) {
            p[k[col]] = {row,col};
        }
    }

    return  0;
}

int check_words(set<pair<int,string>>& words,
                const string& str,int num_of_words)
{
    for (int i=0;i<num_of_words;i++) {
        string  w;
        int     d = 0;

        cin>>w;
        for (int j=0;j<str.length();j++) {
            d += get_distance(str[j],w[j]);
        }

        words.insert({d,w});
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (init(),cin>>t;t>0;t--) {
        int     l;
        string  s;
        
        set<pair<int,string>>   words;

        cin>>s>>l;
        check_words(words,s,l);

        set<pair<int,string>>::iterator it;

        for (it=words.begin();it!=words.end();it++) {
            cout<<it->second<<' '<<it->first<<'\n';
        }
    }

    return  0;
}