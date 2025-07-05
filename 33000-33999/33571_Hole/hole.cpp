#include <iostream>
#include <string>

using namespace std;

int num_of_holes[0x100];

int get_num_of_holes(const string& s) {
    int ret = 0;

    for (int i = 0; i < s.length(); i++) {
        ret += num_of_holes[s[i]];
    }

    return ret;
}

void init(void) {
    num_of_holes['A'] = 1;
    num_of_holes['a'] = 1;
    num_of_holes['B'] = 2;
    num_of_holes['b'] = 1;
    num_of_holes['D'] = 1;
    num_of_holes['d'] = 1;
    num_of_holes['e'] = 1;
    num_of_holes['g'] = 1;
    num_of_holes['O'] = 1;
    num_of_holes['o'] = 1;
    num_of_holes['P'] = 1;
    num_of_holes['p'] = 1;
    num_of_holes['Q'] = 1;
    num_of_holes['q'] = 1;
    num_of_holes['R'] = 1;
    num_of_holes['@'] = 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int ans = 0;

    init();
    
    for (;;) {
        string s;

        cin>>s;

        if (s.empty()) {
            break;
        }

        ans += get_num_of_holes(s);
    }

    cout<<ans<<'\n';

    return 0;
}