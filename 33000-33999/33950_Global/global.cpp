#include <iostream>
#include <string>

using namespace std;

string edit(const string& origin) {
    string ret;

    for (size_t i = 0; i < origin.length(); i++) {
        if (!ret.empty() && ret.back() == 'P' && origin[i] == 'O') {
            ret.push_back('H');
        }

        ret.push_back(origin[i]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t = 1; t <= T; t++) {
        string S;

        cin>>S;
        cout<<edit(S)<<'\n';
    }

    return 0;
}