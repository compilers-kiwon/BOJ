#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#define SHIFT_LEFT(i) (((i)+25)%26)

void print_and_shift(vector<int>& idx) {
    string s;

    for (int i = 0; i < idx.size(); i++) {
        s.push_back(alphabet[idx[i]]);
        idx[i] = SHIFT_LEFT(idx[i]);
    }

    cout<<s<<'\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    vector<int> idx;

    cin>>s;

    for (int i = 0; i <s.length(); i++) {
        idx.push_back(alphabet.find(s[i]));
    }

    for (int i = 1; i <= 26; i++) {
        print_and_shift(idx);
    }

    return 0;
}