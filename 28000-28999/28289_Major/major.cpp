#include <iostream>

using namespace std;

#define MAX_SIZE (4+1)

int software, embedded, ai, none;
int* cnt[MAX_SIZE] = {NULL, &software, &software, &embedded, &ai};

void count(int grade_num, int class_num) {
    if (grade_num == 1) {
        none++;
        return;
    }

    (*cnt[class_num])++;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int P;

    for (cin >> P; P > 0; P--) {
        int G, C, N;
        cin >> G >> C >> N;
        count(G, C);
    }

    cout << software << '\n' << embedded << '\n'
            << ai << '\n' << none << '\n';
    return 0;
}