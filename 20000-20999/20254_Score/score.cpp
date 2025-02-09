#include <iostream>

using namespace std;

#define NUM_OF_FACTORS (4)

const int f[NUM_OF_FACTORS] = {56, 24, 14, 6};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int site_score = 0;

    for (int i = 0; i < NUM_OF_FACTORS; i++) {
        int s;
        cin>>s;
        site_score += f[i] * s;
    }

    cout<<site_score<<'\n';

    return 0;
}