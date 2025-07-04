#include <iostream>
#include <string>

using namespace std;

int search(const string& target, const string& word) {
    int ret = 0;

    for (size_t i = 0; i < word.length() - target.length() + 1; i++) {
        ret += (target==word.substr(i, target.length()))?1:0;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M, num;
    string W;

    num = 0;
    cin>>W>>M;

    for (int i = 1; i <= M; i++) {
        string S;

        cin>>S;
        num += (W.length()>S.length())?0:search(W, S);
    }

    cout<<num<<'\n';

    return 0;
}