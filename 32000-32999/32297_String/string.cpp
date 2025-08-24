#include <iostream>
#include <string>

using namespace std;

const string dst = "gori";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string S;

    cin >> N >> S;
    cout << ((S.find(dst)!=string::npos)?"YES":"NO") << '\n';

    return 0;
}