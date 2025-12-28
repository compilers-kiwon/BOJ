#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <tuple>

using namespace std;

typedef tuple<string, int, int> Stream;

map<string, map<int, pair<int, int>>> youtube;

const int MIN_NUM_STREAMING_IN_WEEK = 5;
const int MIN_STREAMING_MINUTES_IN_WEEK = 60 * 60;

void get_data(Stream& s) {
    string name;
    int day, from, to;

    cin >> name >> day;

    int hh, mm;
    char c;

    cin >> hh >> c >> mm;
    from = (hh * 60) + mm;

    cin >> hh >> c >> mm;
    to = (hh * 60) + mm;

    s = {name, day, to - from};
}

int input(vector<Stream>& s) {
    int N, M;

    for (cin >> N >> M; N > 0; N--) {
        Stream a;
        get_data(a);
        s.push_back(a);
    }

    return (M / 7);
}

void parse_data(const vector<Stream>& s) {
    for (int i = 0; i < s.size(); i++) {
        auto [name, day, duration] = s[i];
        int week = (day - 1) / 7;
        
        youtube[name][week].first += 1;
        youtube[name][week].second += duration;
    }
}

void find_real_virtual(vector<string>& ret, int num_of_weeks) {
    for (auto it = youtube.begin(); it != youtube.end(); it++) {
        bool found = true;
        
        if (it->second.size() != num_of_weeks) {
            continue;
        }

        for (auto w = it->second.begin(); w != it->second.end(); w++) {
            if (w->second.first < MIN_NUM_STREAMING_IN_WEEK ||
                    w->second.second < MIN_STREAMING_MINUTES_IN_WEEK) {
                found = false;
                break;
            }
        }

        if (found == true) {
            ret.push_back(it->first);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_weeks;
    vector<Stream> streaming_data;
    vector<string> virtual_youtubers;

    num_of_weeks = input(streaming_data);
    parse_data(streaming_data);
    find_real_virtual(virtual_youtubers, num_of_weeks);

    if (virtual_youtubers.empty()) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < virtual_youtubers.size(); i++) {
            cout << virtual_youtubers[i] << '\n';
        }
    }

    return 0;
}