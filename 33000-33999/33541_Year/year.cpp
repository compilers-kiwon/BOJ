#include <iostream>

using namespace std;

int main(void) {
    int X;

    cin>>X;

    for (++X; X <= 9999; X++) {
        int n = (X / 100) + (X % 100);

        if ((n * n) == X) {
            cout<<X<<'\n';
            return 0;
        }
    }

    cout<<"-1\n";
    return 0;
}