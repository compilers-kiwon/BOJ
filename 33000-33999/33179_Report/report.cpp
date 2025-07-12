#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, required;

    cin>>n;
    required = 0;

    for (int i = 1; i <= n; i++) {
        int num_of_pages;

        cin>>num_of_pages;
        required += (num_of_pages / 2) + (num_of_pages % 2);
    }

    cout<<required<<'\n';

    return 0;
}