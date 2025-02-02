#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

using namespace std;

#define MAX_LEN (20+1)
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

inline bool is_upper(char c) {
    return IN_RANGE('A', c, 'Z');
}

inline int get_idx(char c) {
    return (int)(c-'a');
}

void input(int num_of_plates, unordered_map<int, vector<string>> attr[]) {
    for (int i = 0; i < num_of_plates; i++) {
        string str;
        int num_of_uppers, idx_of_used_chars;

        cin>>str;
        num_of_uppers = idx_of_used_chars = 0;

        for (int j = 0; j < str.length(); j++) {
            char& c = str[j];

            if (is_upper(c)) {
                num_of_uppers++;
                c = tolower(c);
            }

            idx_of_used_chars |= 1<<get_idx(c);
        }

        sort(str.begin(), str.end());
        attr[num_of_uppers][idx_of_used_chars].push_back(str);
    }
}

uint64_t compare(const vector<string>& plates){
    uint64_t ret = 0;
    unordered_map<string, uint64_t> table;

    for (int i = 0; i < plates.size(); i++) {
        table[plates[i]]++;
    }

    unordered_map<string, uint64_t>::iterator it;

    for (it = table.begin(); it != table.end(); it++) {
        uint64_t n = it->second;
        ret += (n*(n-1))/2;
    }

    return ret;
}

uint64_t get_num_of_similar_plates(int len_of_plate, unordered_map<int, vector<string>> attr[]) {
    int ret = 0;
    
    for (int i = 0; i <= len_of_plate; i++) {
        unordered_map<int, vector<string>>::iterator it;

        for (it = attr[i].begin(); it != attr[i].end(); it++) {
            ret += compare(it->second);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t = 1; t <= T; t++) {
        int n, k;
        unordered_map<int, vector<string>> attr[MAX_LEN];

        cin>>n>>k;
        input(n, attr);
        cout<<get_num_of_similar_plates(k, attr)<<'\n';
    }

    return 0;
}