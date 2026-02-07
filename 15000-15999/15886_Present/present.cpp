#include <iostream>
#include <string>

using namespace std;

#define is_found(str,pos,target) (((pos)=(str).find((target),(pos)))!=string::npos)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt;
    string str;

    cin >> N >> str, cnt = 0;
    for (size_t pos = 0; is_found(str, pos, "EW"); ++cnt, ++pos) {}
    cout << cnt << '\n';

    return 0;
}