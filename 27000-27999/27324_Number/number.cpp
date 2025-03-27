#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string N;

    cin>>N;
    cout<<(N.front()==N.back())<<'\n';

    return 0;
}