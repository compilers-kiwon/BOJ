#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt;

    for (cin >> N, cnt = 0; N > 0; N--) {
        string S;
        cin >> S;
        cnt += ((S.find("01")!=string::npos)||
                (S.find("OI")!=string::npos))?1:0;
    }

    cout << cnt << '\n';
    return 0;
}