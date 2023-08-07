#include    <iostream>
#include    <string>
#include    <vector>
#include    <set>
#include    <algorithm>

using namespace std;

#define MAX_SIZE    (20000+1)
#define MAX_LEN     (26+1)

static int  N,M;
static char grid[MAX_SIZE][MAX_LEN+1];
static set<string>  result;

#define already_listed(table,item)  ((table).find((item))!=(table).end())

bool    input(void)
{
    cin>>N>>M;

    for (int i=1;i<=M;i++) {
        string  s;
        
        cin>>&grid[i][1];
        s = string(&grid[i][1]);

        if (already_listed(result,s)) {
            return  false;
        }

        result.insert(s);
    }

    return  true;
}

bool    get_scale(vector<string>& sc)
{
    size_t  all_cnt = 1;
    bool    prev_used[0x100] = {false,};

    for (int col=1;col<=N;col++) {
        string  s;
        bool    cur_used[0x100] = {false,};

        for (int row=1;row<=M;row++) {
            char    c = grid[row][col];

            if (cur_used[c] == false) {
                s.push_back(c);
                cur_used[c] = true;
            }
        }

        for(char c='A';c<='Z';c++) {
            if (cur_used[c] == true) {
                if (prev_used[c] == true) {
                    return  false;
                }

                prev_used[c] = true;
            }
        }

        sc.push_back(s);
        all_cnt *= s.length();
    }

    return  (all_cnt==result.size());
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string>  scales;

    if (!input()) {
        cout<<"NO\n";
        return  0;
    }

    if (!get_scale(scales)) {
        cout<<"NO\n";
        return  0;
    }

    cout<<"YES\n";

    for (int i=0;i<scales.size();i++) {
        string& s = scales[i];

        sort(s.begin(),s.end());
        cout<<s<<'\n';
    }

    return  0;
}