#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef pair<size_t,string> Subject;

const string BOJ_HEADER = "boj.kr/";

bool is_number(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) {
            return false;
        }
    }

    return true;
}

bool is_boj_problem(const string& s) {
    if (s.length() <= BOJ_HEADER.length()) {
        return false;
    }

    return (s.substr(0,BOJ_HEADER.length()) == BOJ_HEADER
                && is_number(s.substr(BOJ_HEADER.length())));
}

int get_boj_idx(const string& s) {
    return stoi(s.substr(BOJ_HEADER.length()));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int N;
    multiset<Subject> non_boj;
    multiset<int> boj_idx;

    cin>>N;getchar();

    for (int i = 1; i <= N; i++) {
        string str;

        getline(cin, str);

        if (is_boj_problem(str)) {
            boj_idx.insert(get_boj_idx(str));
        } else {
            non_boj.insert({str.length(), str});
        }
    }

    multiset<Subject>::iterator it1;

    for (it1 = non_boj.begin(); it1 != non_boj.end(); it1++) {
        cout<<it1->second<<'\n';
    }

    multiset<int>::iterator it2;

    for (it2 = boj_idx.begin(); it2 != boj_idx.end(); it2++) {
        cout<<BOJ_HEADER<<(*it2)<<'\n';
    }

    return 0;
}