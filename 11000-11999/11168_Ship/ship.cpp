#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum {
    CATEGORY_1 = 0,
    CATEGORY_2 = 1,
    CATEGORY_3 = 2,
    NUM_OF_SYSTEM_TYPE = 3
};

#define TOTAL_NUM_OF_POWER_UINT (100)
#define EXTRA_NUM_OF_POWER_UNIT (20)
#define DAMAGE_NUM_OF_POWER_UNIT (10)
#define LOWER_BOUND_OF_POWER_UNIT (10)

typedef pair<int, int> System; // <type, cnt>

void read_system(unordered_map<string, System>& info,
                    int this_category, int num_of_systems) {
    for (int i = 1; i <= num_of_systems; ++i) {
        string s;
        getline(cin, s);
        info[s] = {this_category,
                    (this_category==CATEGORY_3)?TOTAL_NUM_OF_POWER_UINT:0};
    }
}

void parse(const string& s, vector<int>& n) {
    string cur;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            n.push_back(stoi(cur));
            cur.clear();
        } else {
            cur.push_back(s[i]);
        }
    }
}

void input(vector<string>& damaged_systems,
            unordered_map<string, System>& info) {
    string numbers;
    vector<int> num;

    getline(cin, numbers);
    numbers.push_back(' ');
    parse(numbers, num);
    
    int A = num[0];
    int B = num[1];
    int C = num[2];
    int D = num[3];

    read_system(info, CATEGORY_1, A);
    read_system(info, CATEGORY_2, B);
    read_system(info, CATEGORY_3, C);

    for (int i = 1; i <= D; ++i) {
        string s;
        getline(cin, s);
        damaged_systems.push_back(s);
    }
}

void simulate(unordered_map<string, System>& info,
                const vector<string>& damaged_systems) {
    bool available = true;
    int extra = EXTRA_NUM_OF_POWER_UNIT;
    
    for (int i = 0; available && i < damaged_systems.size(); ++i) {
        const string& s = damaged_systems[i];
        int category = info[s].first;
        int& cnt = info[s].second;
        
        switch (category) {
            case CATEGORY_1:
                cout << "recalibrate " << s << '\n';
                break;
            case CATEGORY_2:
                cout << ((++cnt%2)==1?"invert ":"re-invert ") << s << '\n';
                break;
            case CATEGORY_3:
                if (extra >= DAMAGE_NUM_OF_POWER_UNIT) {
                    extra -= DAMAGE_NUM_OF_POWER_UNIT;
                } else {
                    cnt -= DAMAGE_NUM_OF_POWER_UNIT;
                }

                if (cnt > LOWER_BOUND_OF_POWER_UNIT) {
                    cout << "divert all power to " << s << '\n';
                } else {
                    cout << "ABANDON SHIP. REPEAT. ALL HANDS ABANDON SHIP.\n";
                    available = false;
                }
                break;
            default:
                // do nothing
                break;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string T;
    getline(cin, T);

    for (int t = stoi(T); t > 0; --t) {
        vector<string> damaged;
        unordered_map<string, System> system;

        input(damaged, system);
        simulate(system, damaged);
    }

    return 0;
}