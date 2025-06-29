#include <iostream>
#include <vector>
#include <string>

int main(void) {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);

    int N;
    std::vector<std::string> w;

    std::cin>>N;

    for (int i = 1; i <= N; i++) {
        std::string s;
        std::cin>>s;
        w.push_back(s);
    }

    for (std::vector<std::string>::iterator it = w.begin(); it < (w.end() - 1); it++) {
        if ((*it).front() != (*(it+1)).front()) {
            std::cout<<"0\n";
            return 0;
        }
    }

    std::cout<<"1\n";
    return 0;
}