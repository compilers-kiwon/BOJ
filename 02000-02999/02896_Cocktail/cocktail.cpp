#include <iostream>

using namespace std;

#define MAX_SIZE (3)
#define MAX_RATIO (500.0 + 1.0)
#define NUM_OF_PRECISION (4)

int main(void) {
    double quantity[MAX_SIZE], required[MAX_SIZE];
    
    for (int i = 0; i < MAX_SIZE; i++) {
        cin>>quantity[i];
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        cin>>required[i];
    }

    int min_idx;
    double min_ratio = MAX_RATIO;

    for (int i = 0; i < MAX_SIZE; i++) {
        double ratio = quantity[i] / required[i];

        if (ratio < min_ratio) {
            min_idx = i;
            min_ratio = ratio;
        }
    }

    cout << fixed;
    cout.precision(NUM_OF_PRECISION);

    for (int i = 0; i < MAX_SIZE; i++) {
        if (min_idx == i) {
            cout<<0.0;
        } else {
            cout<<quantity[i] - (required[i] * min_ratio);
        }

        cout<<((i==(MAX_SIZE-1))?'\n':' ');
    }

    return 0;
}