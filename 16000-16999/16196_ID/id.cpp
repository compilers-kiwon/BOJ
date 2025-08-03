#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

typedef long long int int64;

unordered_set<string> predefined_local_codes;

#define MALE (1)
#define FEMALE (0)

#define chr2int64(c) ((int64)((c)-'0'))
#define is_lunar_year(y) ((((y)%4==0)&&((y)%100!=0))||((y)%400==0))

bool check_local_code(const string& id) {
    string local_code = id.substr(0, 6);
    return (predefined_local_codes.find(local_code) != predefined_local_codes.end());
}

bool check_birth_date(const string& id) {
    int num_of_days[12+1] = 
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int yyyy = stoi(id.substr(6, 4));
    int mm = stoi(id.substr(10, 2));
    int dd = stoi(id.substr(12, 2));

    if (yyyy < 1900 || yyyy > 2011) {
        return false;
    }

    if (!(1 <= mm && mm <= 12)) {
        return false;
    }

    if (is_lunar_year(yyyy) == true) {
        num_of_days[2]++;
    }

    if (!(1 <= dd && dd <= num_of_days[mm])) {
        return false;
    }

    return true;
}

bool check_sex(const string& id, int& s) {
    int sex_code = stoi(id.substr(14, 3));

    if (sex_code == 0) {
        return false;
    }

    s = sex_code % 2;
    return true;
}

bool check_sum(const string& id) {
    int64 sum = 0;
    int64 code = (1LL<<17);

    for (size_t i = 0; i < 17; i++) {
        sum += chr2int64(id[i]) * code;
        code >>= 1;
    }

    int64 x;

    for (x = 0; x < 10; x++) {
        if ((sum + x) % 11 == 1) {
            break;
        }
    }

    return (((x == 10) && (id.back() == 'X'))
                || (chr2int64(id.back()) == x));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, s;
    string id;

    cin >> id >> N;

    for (int i = 1; i <= N; i++) {
        string code;
        cin >> code;
        predefined_local_codes.insert(code);
    }

    if (check_local_code(id) && check_birth_date(id)
            && check_sex(id, s) && check_sum(id)) {
        cout << ((s==MALE)?'M':'F') << '\n';
    } else {
        cout << "I\n";
    }

    return 0;
}