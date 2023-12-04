#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

typedef pair<char,string> Code;

const static int MAX_CODE_LEN = 20;

static vector<Code> codes[MAX_CODE_LEN+1];

static inline bool is_end_of_str(int pos,const string& str) {
    return  (pos == str.length());
}

bool encode(const string& decoded,int pos,string& cur)
{
    if (is_end_of_str(pos,decoded)) {
        return  true;
    }

    int max_len = min(MAX_CODE_LEN,(int)decoded.length()-pos);

    for (int i=1;i<=max_len;i++) {
        string  s = decoded.substr(pos,i);
        const vector<Code>& c = codes[i];

        for (int j=0;j<c.size();j++) {
            if (c[j].second == s) {
                cur.push_back(c[j].first);
                if (encode(decoded,pos+i,cur)) return true;
                cur.pop_back();
            }
        }
    }

    return  false;
}

string input(void)
{
    int k;
    string binary;

    cin>>k;

    for (int i=1;i<=k;i++) {
        char c;
        string s;

        cin>>c>>s;
        codes[s.length()].push_back({c,s});
    }

    cin>>binary;
    return  binary;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string dec,enc;

    dec = input();
    encode(dec,0,enc);
    cout<<enc<<'\n';

    return  0;
}