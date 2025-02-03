#include <iostream>

using namespace std;

#define MAX_NUM (1000000+1)

int num_of_2s[MAX_NUM], num_of_5s[MAX_NUM];

void init(void) {
    for (int i = 1; i <= MAX_NUM; i++) {
        if ((i % 2) == 0) {
            num_of_2s[i] = num_of_2s[i/2] + 1;
        }

        if ((i % 5) == 0) {
            num_of_5s[i] = num_of_5s[i/5] + 1;
        }
    }

    for (int i = 1; i <= MAX_NUM; i++) {
        num_of_2s[i] += num_of_2s[i-1];
        num_of_5s[i] += num_of_5s[i-1];
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();

    for (int x = 1; ; x++) {
        int N;

        cin>>N;

        if (N == 0) {
            break;
        }

        cout<<"Case #"<<x<<": "<<
            min(num_of_2s[N], num_of_5s[N])<<'\n';
    }

    return 0;
}