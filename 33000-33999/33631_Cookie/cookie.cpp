#include <iostream>

using namespace std;

#define MAX_SIZE (5)
#define NUM_OF_COOKIES (1)
#define INGREDIENT_POS (2)

bool possible_to_make(int num, int cur[], int required[]) {
    int tmp[MAX_SIZE + 1] = {0, };

    for (int i = INGREDIENT_POS; i <= MAX_SIZE; i++) {
        tmp[i] = required[i] * num;
        
        if (cur[i] < tmp[i]) {
            return false;
        }
    }

    for (int i = INGREDIENT_POS; i <= MAX_SIZE; i++) {
        cur[i] -= tmp[i];
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cur[MAX_SIZE + 1] = {0, };
    int required[MAX_SIZE + 1] = {0, };
    int Q;

    for (int i = INGREDIENT_POS; i <= MAX_SIZE; i++) {
        cin>>cur[i];
    }

    for (int i = INGREDIENT_POS; i <= MAX_SIZE; i++) {
        cin>>required[i];
    }

    cin>>Q;

    for (int q = 1; q <= Q; q++) {
        int n, i;

        cin>>n>>i;

        if (n == 1) {
            if (possible_to_make(i, cur, required) == true) {
                cur[NUM_OF_COOKIES] += i;
                cout<<cur[NUM_OF_COOKIES]<<'\n';
            } else {
                cout<<"Hello, siumii\n";
            }
        } else {
            cur[n] += i;
            cout<<cur[n]<<'\n';
        }
    }

    return 0;
}