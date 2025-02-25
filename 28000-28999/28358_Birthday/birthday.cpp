#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int num_of_days[12+1] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

void get_all_dates(vector<string>& dates) {
    for (int month = 1; month <= 12; month++) {
        for (int day = 1; day <= num_of_days[month]; day++) {
            dates.push_back(to_string(month) + to_string(day));
        }
    }
}

bool is_possible(const string& cur, const string& used) {
    for (int i = 0; i < cur.length(); i++) {
        if (used.find(cur[i]) == string::npos) {
            return false;
        }
    }

    return true;
}

int count_dates(const vector<string>& dates, const string& used) {
    int ret = 0;

    for (int i = 0; i < dates.size(); i++) {
        const string& cur_date = dates[i];
        ret += (is_possible(cur_date, used))?1:0;
    }

    return ret;
}

void get_used_numbers(string& used) {
    for (char c = '0'; c <= '9'; c++) {
        int num;
        cin>>num;
        if (num == 0) {
            used.push_back(c);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int T;
    vector<string> all;

    cin>>T;
    get_all_dates(all);

    for (int t = 1; t <= T; t++) {
        string used;

        get_used_numbers(used);
        cout<<count_dates(all, used)<<'\n';
    }

    return 0;
}