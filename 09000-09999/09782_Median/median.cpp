#include <iostream>

using namespace std;

#define MAX_SIZE (100+1)

int get_median(int size, int arr[]) {
    int ret;

    if (size % 2 == 0) {
        ret = (arr[size/2] + arr[size/2+1])*10 / 2;
    } else {
        ret = arr[(size+1)/2] * 10;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int c = 1;;++c) {
        int n, m, num[MAX_SIZE];

        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }

        m = get_median(n, num);
        
        cout << "Case " << c << ": "
                << m / 10 << '.' << m % 10 << '\n';
    }

    return 0;
}