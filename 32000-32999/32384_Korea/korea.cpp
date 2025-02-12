#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    size_t N;

    cin>>N;

    for (size_t i = 1; i <= N; i++) {
        cout<<"LoveisKoreaUniversity"<<((i==N)?'\n':' ');
    }

    return 0;
}