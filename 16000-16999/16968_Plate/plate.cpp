#include <iostream>
#include <string>

using namespace std;

bool check_plate(const string& plate) {
    for (int i = 0; i < plate.size() - 1; i++) {
        if(plate[i] == plate[i+1]) {
            return false;
        }
    }

    return true;
}

void dfs(const string& format, string& gen, int& cnt) {
    if (format.length() == gen.length()) {
        cnt += check_plate(gen)?1:0;
        return;
    }

    char from, to;

    if (format[gen.length()] == 'c') {
        from = 'a', to = 'z';
    } else {
        from = '0', to = '9';
    }

    for (char cur = from; cur <= to; cur++) {
        gen.push_back(cur);
        dfs(format, gen, cnt);
        gen.pop_back();
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt;
    string format, plate;

    cin >> format, cnt = 0;
    dfs(format, plate, cnt);
    cout << cnt << '\n';

    return 0;
}