#include <iostream>

using namespace std;

#define MAX_SIZE (11)

typedef pair<int, int> Record;

const Record r[MAX_SIZE+1] = {
    {0, 0}, {12, 1600}, {11, 894}, {11, 1327}, {10, 1311}, {9, 1004},
    {9, 1178}, {9, 1357}, {8, 837}, {7, 1055}, {6, 556}, {6, 773}
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    cout << r[N].first << ' ' << r[N].second << '\n';

    return 0;
}