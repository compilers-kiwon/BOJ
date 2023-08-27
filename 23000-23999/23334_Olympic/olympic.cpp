#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define NUM_OF_MEDALS       (3)
#define MAX_NUM_OF_NATIONS  (300)

typedef struct {
    string  name;
    vector<int> medals;
} Nation;

int parse(const string& s,Nation& n)
{
    int     pos;
    string  cur;

    for (pos=0;n.medals.size()<NUM_OF_MEDALS;pos++) {
        if (s[pos] == ' ') {
            n.medals.push_back(stoi(cur));
            cur.clear();
        } else {
            cur.push_back(s[pos]);
        }
    }
    
    n.name = s.substr(pos);
    return  0;
}

int input(vector<Nation>& nations)
{
    int     n;
    string  buf;

    getline(cin,buf);
    n = stoi(buf);

    for (int i=1;i<=n;i++) {
        Nation  a;

        getline(cin,buf);
        parse(buf,a);
        nations.push_back(a);
    }

    return  0;
}

int is_better(const Nation& a,const Nation& b)
{
    for (int i=0;i<NUM_OF_MEDALS;i++) {
        if (a.medals[i] != b.medals[i]) {
            return  (a.medals[i]>b.medals[i]);
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int winner;
    vector<Nation>  nations;

    input(nations);
    winner = 0;

    for (int i=1;i<nations.size();i++) {
        if (is_better(nations[i],nations[winner])) {
            winner = i;
        }
    }

    cout<<nations[winner].name<<'\n';
    return  0;
}