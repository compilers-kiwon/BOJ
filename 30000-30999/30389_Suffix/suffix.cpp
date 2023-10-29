#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>

using namespace std;

static inline bool is_member_of_different_set(set<string>& s,string& e) {
    return  (s.find(e) == s.end());
}

void do_xor(set<string>& a,
                vector<string>& b)
{
    for (int i=0;i<b.size();i++) {
        if (is_member_of_different_set(a,b[i])) {
            a.insert(b[i]);
        } else {
            a.erase(b[i]);
        }
    }
}

void get_suffix_set(const string& str,
                        vector<string>& s)
{
    for (int i=0;i<str.length();i++) {
        s.push_back(str.substr(i));
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    set<string> s;
    
    cin>>N;

    for (int i=1;i<=N;i++) {
        string  str;
        vector<string> suffix;

        cin>>str;
        get_suffix_set(str,suffix);
        do_xor(s,suffix);
    }

    cout<<s.size()<<'\n';
    return  0;
}