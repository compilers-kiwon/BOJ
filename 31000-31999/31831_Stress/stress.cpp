#include <iostream>

#define MAX_SIZE (100000+1)

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int N, M, cnt, cur_stress;

    std::cin>>N>>M;
    cnt = cur_stress = 0;

    for (int i = 1; i <= N; i++) {
        int A;

        std::cin>>A;
        cur_stress = std::max(0, cur_stress + A);

        if (cur_stress >= M) {
            cnt++;
        }
    }

    std::cout<<cnt<<'\n';

    return 0;
}