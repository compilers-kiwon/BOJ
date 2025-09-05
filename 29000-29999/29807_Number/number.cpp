#include <iostream>
#include <cmath>

using namespace std;

enum {
    KOREAN = 1,
    MATH = 2,
    ENGLISH = 3,
    ELECTIVE = 4,
    SECOND = 5,
    MAX_SUBJECT = 6
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T, score[MAX_SUBJECT];

    cin >> T;
    
    for (int i = 1; i < MAX_SUBJECT; i++) {
        if (i <= T) {
            cin >> score[i];
        } else {
            score[i] = 0;
        }
    }

    int s1, s2, s3;

    s1 = abs(score[KOREAN]-score[ENGLISH]) * ((score[KOREAN]>score[ENGLISH])?508:108);
    s2 = abs(score[MATH]-score[ELECTIVE]) * ((score[MATH]>score[ELECTIVE])?212:305);
    s3 = score[SECOND] * 707;

    cout << (s1 + s2 + s3) * 4763 << '\n';
    return 0;
}