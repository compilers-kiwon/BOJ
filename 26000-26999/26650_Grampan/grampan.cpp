#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100000)

typedef long long int   int64;

static string   str;
static vector<vector<int>>  pos[0x100];

#define clear_if_none_char(c) \
    {if(pos[(c)].size()==1&&pos[(c)].front().empty()) pos[(c)].clear();}

int input(void)
{
    cin>>str;
    
    pos['A'].push_back(vector<int>());
    pos['Z'].push_back(vector<int>());

    for (int i=0;i<str.length();i++) {
        char    c = str[i];

        if (c=='A' || c=='Z') {
            if (pos[c].back().empty() ||
                    pos[c].back().back()+1==i) {
                pos[c].back().push_back(i);
            } else {
                vector<int> v;

                v.push_back(i);
                pos[c].push_back(v);
            }
        }
    }

    clear_if_none_char('A');
    clear_if_none_char('Z');

    return  0;
}

bool    check_str(int from, int to)
{
    char    cur = 'A';
    
    for (int i=from;i<=to;i++) {
        if (str[i]!=cur && str[i]!=cur+1) {
            return  false;
        }

        if (str[i] == cur+1) cur++;
    }

    return  true;
}

int64   simulate(void)
{
    int64   ret = 0;
    vector<vector<int>>&    A = pos['A'];
    vector<vector<int>>&    Z = pos['Z'];

    for (int i=0;i<A.size();i++) {
        int A_pos = A[i].back();

        for (int j=0;j<Z.size();j++) {
            int Z_pos = Z[j].front();

            if (Z_pos-A_pos+1 < 26) continue;
            if (check_str(A_pos,Z_pos)) {
                ret+=(int64)(A[i].size()*Z[j].size());
            }
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}