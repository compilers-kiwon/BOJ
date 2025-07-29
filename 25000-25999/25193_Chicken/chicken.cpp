#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, chicken, others;
    string foods;

    cin >> N >> foods;
    chicken = others = 0;

    for (int i = 0; i < N; i++) {
        if (foods[i] == 'C') {
            ++chicken;
        } else {
            ++others;
        }
    }

    if (others == 0) {
        cout << chicken << '\n';
    } else {
        ++others;
        cout << chicken / others + 
                    ((chicken % others)?1:0)<< '\n';
    }

    return 0;
}