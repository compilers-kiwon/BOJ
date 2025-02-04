#include <iostream>
#include <string>

using namespace std;

string consecutive[0x100];

int merge_identical_letters(const string& s, int num_of_removals) {
    int ret, cnt_of_char, cnt_of_removal;

    ret = cnt_of_char = cnt_of_removal = 0;

    for (int front = 0, end = 0; end < s.length(); end++) {
        if (s[end] == ' ') {
            cnt_of_removal++;
            for (; cnt_of_removal > num_of_removals; front++) {
                if (s[front] == ' ') {
                    cnt_of_removal--;
                } else {
                    cnt_of_char--;
                }
            }            
        } else {
            cnt_of_char++;
        }

        ret = max(ret, cnt_of_char);
    }

    return ret;
}

void init(const string& s) {
    for (char c = 'a'; c <= 'z'; c++) {
        consecutive[c] = string(s.length(), ' ');
    }

    for (size_t i = 0; i < s.length(); i++) {
        consecutive[s[i]][i] = s[i];
    }

    for (char c = 'a'; c <= 'z'; c++) {
        size_t pos = consecutive[c].find(c, 0);

        if (pos == string::npos) {
            continue;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    string str;
    int m, max_length;

    cin>>str>>m;
    
    init(str);
    max_length = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        if (consecutive[c].empty()) {
            continue;
        }

        max_length = max(max_length, 
                            merge_identical_letters(consecutive[c], m));
    }

    cout<<max_length<<'\n';
    return 0;
}