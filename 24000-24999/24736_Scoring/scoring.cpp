#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const int score_table[] = {6, 3, 2, 1, 2};

    for (int i = 0; i < 2; i++) {
        int sum = 0;

        for (int j = 0; j < 5; j++) {
            int num;

            cin>>num;
            sum += num * score_table[j];
        }

        cout<<sum<<' ';
    }

    return 0;
}