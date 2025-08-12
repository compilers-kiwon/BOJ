#include <iostream>

using namespace std;

#define MAX_SIZE (100+1)

int get_page_number(int pos, bool available[]) {
    int ret;

    for (int i = 1; ; i++) {
        if (available[i] == true && (--pos) == 0) {
            ret = i;
            break;
        }
    }

    return ret;
}

void remove_page(int pos, int num_of_pages, bool available[]) {
    available[pos] = available[num_of_pages-pos+1] = false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        int n, q;
        bool available[MAX_SIZE];

        cin >> n >> q;
        fill(&available[1], &available[n+1], true);

        for (int i = 1; i <= q; i++) {
            char c;
            int num;

            cin >> c >> num;

            if (c == '?') {
                cout << get_page_number(num, available) << '\n';
            } else {
                remove_page(num, n, available);
            }
        }
    }

    return 0;
}