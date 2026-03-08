#include <iostream>
#include <string>

using namespace std;

#define FAVORITE_STRING ("SciComLove")
#define NUM_OF_UPPERS (3)
#define NUM_OF_LOWERS (7)

int init(string& str, int& cnt_of_lowers, int& cnt_of_uppers) {
    int N, Q;

    cin >> N >> Q;
    cnt_of_lowers = cnt_of_uppers = 0;

    while (str.length() < N) {
        str += FAVORITE_STRING;
        cnt_of_lowers += NUM_OF_LOWERS;
        cnt_of_uppers += NUM_OF_UPPERS;
    }

    while (str.length() > N) {
        if (islower(str.back())) {
            --cnt_of_lowers;
        } else {
            --cnt_of_uppers;
        }

        str.pop_back();
    }

    return Q;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string str;
    int Q, cnt_of_lowers, cnt_of_uppers;
    
    Q = init(str, cnt_of_lowers, cnt_of_uppers);
    str.insert(str.begin(), ' ');

    for (int q= 1; q <= Q; ++q) {
        int X;
        cin >> X;

        char& c = str[X];

        if (islower(c)) {
            c = toupper(c);
            ++cnt_of_uppers, --cnt_of_lowers;
        } else {
            c = tolower(c);
            --cnt_of_uppers, ++cnt_of_lowers;
        }

        cout << cnt_of_uppers << '\n';
    }

    return 0;
}