#include <iostream>
#include <queue>

using namespace std;

void input(int& H, int& A, priority_queue<int>& hero) {
    int n;

    for (cin >> n >> H >> A; n > 0; --n) {
        int h, a;
        cin >> h >> a;
        hero.push(((h / A) + ((h%A==0)?0:1)) * a);
    }
}

int simulate(int H, priority_queue<int>& hero) {
    int cnt;

    for (cnt = 0; !hero.empty(); hero.pop(), ++cnt) {
        if ((H -= hero.top()) <= 0) {
            break;
        }        
    }

    return (hero.empty()?-1:cnt);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; --t) {
        int H, A;
        priority_queue<int> hero;

        input(H, A, hero);
        cout << simulate(H, hero) << '\n';
    }

    return 0;
}