#include <iostream>

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int N, cnt;

    cnt = 0;
    std::cin>>N;

    for (int i = 1; i <= N; i++) {
        std::string s;
        
        std::cin>>s;
        cnt += (s.front()=='C')?1:0;
    }

    std::cout<<cnt<<'\n';

    return 0;
}