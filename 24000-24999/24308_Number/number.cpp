#include <iostream>
#include <string>

using namespace std;

#define chr2int(c) ((int)((c)-'0'))

bool is_multiple_of_2(const string& num) {
    return (chr2int(num.back()) % 2 == 0);
}

bool is_multiple_of_3(int base, int d1, int d2) {
    return ((base + d1 + d2) % 3 == 0);
}

int get_sum_of_digits(const string& num) {
    int ret = 0;

    for (int i = 0; i < num.length(); ++i) {
        ret += chr2int(num[i]);
    }

    return ret;
}

bool is_bigger(const string& big, const string& small) {
    for (int i = 0; i < big.length(); ++i) {
        if (big[i] > small[i]) {
            return true;
        }

        if (big[i] < small[i]) {
            return false;
        }
    }

    return true;
}

void get_candidate(string& s, char from, char to, char exception) {
    for (char c = from; c <= to; ++c) {
        if (c == exception) {
            continue;
        }

        s.push_back(c);
    }
}

void simulate(const string& num, int p1, int p2,
                    string& max_num, bool negative, int sum) {
    string base = num;
    int sum_of_digits = sum - chr2int(num[p1]) - chr2int(num[p2]);

    string candidate_1, candidate_2;

    get_candidate(candidate_1, (p1==0)?'1':'0', '9', num[p1]);
    get_candidate(candidate_2, '0', '9', num[p2]);

    for (int i = 0; i < candidate_1.length(); ++i) {
        base[p1] = candidate_1[i];

        for (int j = 0; j < candidate_2.length(); ++j) {
            base[p2] = candidate_2[j];

            if (is_multiple_of_2(base) == false ||
                    is_multiple_of_3(sum_of_digits, chr2int(base[p1]), chr2int(base[p2])) == false) {
                continue;
            }

            if (max_num.empty() == true || is_bigger(max_num, base) == negative) {
                    max_num = base; 
            }
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum_of_digits;
    string num, max_num;
    bool negative = false;

    cin >> num;

    if (num.front() == '-') {
        negative = true;
    }

    if (!isdigit(num.front())) {
        num.erase(0, 1);
    }

    sum_of_digits = get_sum_of_digits(num);
    
    for (int i = 0; i < num.length() - 1; ++i) {
        for (int j = i + 1; j < num.length(); ++j) {
            simulate(num, i, j, max_num, negative, sum_of_digits);
        }
    }

    cout << (negative?"-":"") << max_num << '\n';

    return 0;
}