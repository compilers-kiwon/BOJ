#include <iostream>
#include <string>

using namespace std;

#define MINUTES_PER_DAY (1440)

int convert_minutes(const string& time, const string& indicator) {
    int delimeter_pos = time.find(':');
    string h_str = time.substr(0, delimeter_pos);
    string m_str = time.substr(delimeter_pos + 1);

    int hh = stoi(h_str);
    int mm = stoi(m_str);

    if (hh == 12) {
        hh = 0;
    }

    if (indicator == "PM") {
        hh += 12;
    }

    return (hh * 60) + mm;
}

int get_arrival_minutes(const string& time, const string& indicator) {
    return convert_minutes(time, indicator) + MINUTES_PER_DAY;
}

string get_formatted_str(int minutes) {
    minutes %= MINUTES_PER_DAY;

    int hh = minutes / 60;
    int mm = minutes % 60;
    string ind;
    
    if (hh < 12) {
        ind = "AM";
    } else {
        ind = "PM";
    }

    if ((hh %= 12) == 0) {
        hh = 12;
    }

    string h = to_string(hh);
    string m = to_string(mm);

    if (m.length() == 1) {
        m.insert(m.begin(), '0');
    }

    return h + ":" + m + " " + ind;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string h_m, d;
    int t, minutes;

    cin >> h_m >> d >> t;
    minutes = convert_minutes(h_m, d) + MINUTES_PER_DAY - t;
    cout << get_formatted_str(minutes) << '\n';

    return 0;
}