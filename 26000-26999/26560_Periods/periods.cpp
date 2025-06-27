#include <iostream>
#include <string>

int main(void) {
    int n;

    std::cin>>n;
    getchar();

    for (int i = 1; i <= n; i++) {
        std::string str;

        getline(std::cin, str);
        std::cout<<str<<((str.back()=='.')?"\n":".\n");
    }

    return 0;
}