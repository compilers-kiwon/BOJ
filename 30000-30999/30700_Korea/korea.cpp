#include <iostream>

using namespace std;

const string MY_STR = "KOREA";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    size_t pos, cnt;

    cin>>S;
    pos = cnt = 0;

    for (size_t i = 0; i < S.length(); i++) {
        if (MY_STR[pos] == S[i]) {
            cnt++;
            pos = (pos+1) % MY_STR.length();
        }
    }

    cout<<cnt<<'\n';
    return 0;
}