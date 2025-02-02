#include <iostream>

using namespace std;

#define NUM_OF_COINS (10)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    const int my_money = (1 << NUM_OF_COINS) -1;
    int S, M;

    cin>>S>>M;

    if (S <= my_money) {
        cout<<"No thanks\n";
        return 0;
    }

    S -= my_money;

    for (int i = 0; i <= NUM_OF_COINS + 1; i++) {
        int c = 1 << i;

        if ((S & c) != 0 && (M & c) == 0) {
            cout<<"Impossible\n";
            return 0;
        }
    }

    cout<<"Thanks\n";
    return 0;
}