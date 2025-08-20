#include <iostream>

using namespace std;

#define MAX_POINTS (3)

int get_total_score(void) {
    int ret = 0;

    for (int p = 1; p <= MAX_POINTS; p++) {
        int num_of_shoots;
        cin >> num_of_shoots;
        ret += p * num_of_shoots;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t1_score = get_total_score();
    int t2_score = get_total_score();

    cout << ((t1_score==t2_score)?0:
                (t1_score>t2_score)?1:2) << '\n';
    
    return 0;
}