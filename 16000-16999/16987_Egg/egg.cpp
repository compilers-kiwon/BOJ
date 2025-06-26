#include <iostream>

#define MAX_SIZE (8+1)

typedef std::pair<int, int> Egg; // <strength, weight>

int N;
Egg e[MAX_SIZE];

void input(void) {
    std::cin>>N;

    for (int n = 1; n <= N; n++) {
        int& S = e[n].first;
        int& W = e[n].second;

        std::cin>>S>>W;
    }
}

int count(int excluded) {
    int ret = 0;

    for (int n = 1; n <= N; n++) {
        if (n == excluded) {
            continue;
        }

        int& S = e[n].first;

        if (S <= 0) {
            ret++;
        }
    }

    return ret;
}

void simulate(int in_hand, int& num_of_crash) {
    if (in_hand > N) {
        num_of_crash = std::max(num_of_crash, count(0));
        return;
    }

    if (e[in_hand].first <= 0 || count(in_hand) == (N-1)) {
        simulate(in_hand + 1, num_of_crash);
        return;
    }
    
    for (int n = 1; n <= N; n++) {
        if (n == in_hand || e[n].first <= 0) {
            continue;
        }

        e[n].first -= e[in_hand].second;
        e[in_hand].first -= e[n].second;

        simulate(in_hand + 1, num_of_crash);

        e[n].first += e[in_hand].second;
        e[in_hand].first += e[n].second;
    }
}

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int max_num_of_crash = 0;

    input();
    simulate(1, max_num_of_crash);

    std::cout<<max_num_of_crash<<'\n';

    return 0;
}