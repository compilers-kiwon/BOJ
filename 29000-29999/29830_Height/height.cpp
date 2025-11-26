#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string s;
    queue<int> H, D;

    cin >> N;
    
    for (int i = 1; i <= N + 1; i++) {
        int h;
        cin >> h;
        H.push(h);
    }

    for (int i = 1; i <= N; i++) {
        int d;
        cin >> d;
        D.push(d);
    }

    int cur_height = H.front();

    for (H.pop(); !D.empty(); D.pop(), H.pop()) {
        int h = H.front();
        cur_height += D.front();
        s.push_back((cur_height==h)?'M':(cur_height<h)?'T':'V');
    }

    cout << s << '\n';

    return 0;
}