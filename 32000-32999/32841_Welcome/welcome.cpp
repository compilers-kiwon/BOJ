#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    size_t r, c, cnt;

    cin>>r>>c;
    cnt = 1;

    for (size_t i = 1; i <= r; i++) {
        string w;
        size_t left, right, num_of_blanks;

        cin>>w;
        num_of_blanks = c - w.length();

        if ((num_of_blanks % 2) == 0) {
            left = num_of_blanks/2;
            right = left;
        } else {
            if ((cnt++ % 2) == 1) {
                left = num_of_blanks/2;
                right = num_of_blanks - left;
            } else {
                right = num_of_blanks/2;
                left = num_of_blanks - right;
            }
        }

        cout<<string(left, '.')<<w<<string(right, '.')<<'\n';
    }

    return 0;
}