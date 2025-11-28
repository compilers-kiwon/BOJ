#include <iostream>

using namespace std;

#define MAX_SIZE (1000000+1)
#define MIN_VOL (129)
#define MAX_VOL (138)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

int N, L, s[MAX_SIZE+1];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> L;

    for (int t = 1; t <= N; t++) {
        int a;
        
        cin >> a;
        
        s[t] += s[t-1] + a;
        s[min(t+L, MAX_SIZE)] -= a;
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        cnt += IN_RANGE(MIN_VOL, s[i], MAX_VOL)?1:0; 
    }

    cout << cnt << '\n';

    return 0;
}