#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt, cur;

    cin >> N;

    for (cnt = 0, cur = N;
         to_string(N).length() == to_string(cur *= 2).length();
         cnt++);
    
    cout << cnt << '\n';
    return 0;
}