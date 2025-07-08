#include <iostream>
#include <string>

using namespace std;

int get_overtime_hours(int total_hours, int holiday_hours) {
    int ret = total_hours - holiday_hours - 140;

    return ((ret>0)?ret:0);
}

string follow_format(int payment) {
    string ret;

    for (; payment > 0; payment /= 1000) {
        string cur = to_string(payment%1000);

        for (; cur.length() < 3;) {
            cur.insert(cur.begin(), '0');
        }

        cur.insert(cur.begin(), ',');
        ret = cur + ret;
    }

    for (; ret.front() == ',' || ret.front() == '0';) {
        ret.erase(0, 1);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for (int i = 1; i <= n; i++) {
        int x, k, h, o, p;

        cin>>x>>k>>h;
        
        o = get_overtime_hours(k, h);
        p = (h * 2 * x) + (((x + (x / 2))) * o) + ((k - o - h) * x);

        cout<<follow_format(p)<<'\n';
    }

    return 0;
}