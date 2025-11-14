#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int h1, m1, s1;
    int h2, m2, s2;
    int h_cnt, m_cnt, s_cnt;
    char c;

    cin >> h1 >> c >> m1 >> c >> s1;
    cin >> h2 >> c >> m2 >> c >> s2;
    h_cnt = m_cnt = s_cnt = 0;

    for (;;) {
        if (++s1 == 60) {
            s1 = 0, s_cnt++;

            if (++m1 == 60) {
                m1 = 0, m_cnt++;

                if (++h1 == 12) {
                    h_cnt++;
                }
            }
        }

        if ((h1 == h2) && (m1 == m2) && (s1 == s2)) {
            break;
        }
    }

    cout << h_cnt << ' ' << m_cnt << ' ' << s_cnt << '\n';
    return 0;
}