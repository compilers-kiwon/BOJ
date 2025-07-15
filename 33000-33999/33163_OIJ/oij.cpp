#include <iostream>
#include <string>

using namespace std;

static inline char convert_ch(char ch) {
    return ((ch=='J')?'O':(ch=='O')?'I':'J');
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S, converted;

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        converted.push_back(convert_ch(S[i]));
    }

    cout << converted <<'\n';

    return 0;
}