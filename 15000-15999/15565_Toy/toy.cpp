#include <iostream>

using namespace std;

#define LION (1)
#define OTHER (2)
#define MAX_SIZE (1000000+1)

int N, K, toy[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> toy[i];
    }

    int min_size = 0x7FFFFFFF;
    int num_of_lions = (toy[1]==LION)?1:0;

    for (int h = 1, t = 2;;) {
        if (num_of_lions >= K) {
            min_size = min(min_size, t - h);

            if (h < t) {
                num_of_lions -= (toy[h++]==LION)?1:0;
            }
        } else {
            if (t <= N) {
                num_of_lions += (toy[t++]==LION)?1:0;
            } else {
                break;
            }
        }
    }

    cout << ((min_size==0x7FFFFFFF)?-1:min_size) << '\n';
    return 0;
}