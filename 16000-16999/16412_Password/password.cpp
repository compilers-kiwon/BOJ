#include <iostream>
#include <string>

using namespace std;

int check_password(int num) {
    bool visited[9 + 1] = {false, };

    for (int i = num; i > 0; i /= 10) {
        if (visited[i%10] == true || num%(i%10) != 0) {
            return 0;
        }

        visited[i%10] = true;
    }

    return 1;
}

bool find_zero(int num) {
    string s = to_string(num);
    return (s.find('0') != string::npos);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L, H, cnt;

    cin>>L>>H;
    cnt = 0;

    for (int i = L; i <= H; i++) {
        if (find_zero(i) == true) {
            continue;
        }

        cnt += check_password(i);
    }

    cout<<cnt<<'\n';

    return 0;
}