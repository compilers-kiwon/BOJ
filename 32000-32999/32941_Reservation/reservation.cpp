#include <iostream>

using namespace std;

#define MAX_NUM_OF_STUDENTS (10+1)
#define MAX_RESERVED_TIME (1000+1)

int T, X, N;
bool available[MAX_NUM_OF_STUDENTS][MAX_RESERVED_TIME];

void input(void) {
    cin>>T>>X>>N;

    for (int i = 1; i <= N; i++) {
        int K;

        cin>>K;

        for (int k = 1; k <= K; k++) {
            int A;
            cin>>A;
            available[i][A] = true;
        }
    }
}

bool check_availablity(void) {
    for (int i = 1; i <= N; i++) {
        if (available[i][X] == false) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<(check_availablity()?"YES":"NO")<<'\n';

    return 0;
}