#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<pair<string, int>> grade = {
    {"A+", 450}, {"A0", 400}, {"B+", 350}, {"B0", 300},
    {"C+", 250}, {"C0", 200}, {"D+", 150}, {"D0", 100},
    {"F", 0}
};

int convert_grade_to_score(const string& g) {
    int ret;

    for (int i = 0; i < grade.size(); i++) {
        if (grade[i].first == g) {
            ret = grade[i].second;
            break;
        }    
    }

    return ret;
}

string input(int& num_of_credits, int& avaiable_credit, int& sum) {
    int N;
    string X;

    sum = num_of_credits = 0;

    for (cin >> N >> X; N > 0; N--) {
        int c;
        string g;

        cin >> c;
        num_of_credits += c;

        if (N == 1) {
            avaiable_credit = c;
        } else {
            cin >> g;
            sum += c * convert_grade_to_score(g);
        }
    }

    return X;
}

int round_up_decimal_numers(const string& decimal_num) {
    int integer_part = stoi(
        decimal_num.substr(0, decimal_num.find('.'))
    );

    int decimal_part = stoi(
        decimal_num.substr(decimal_num.find('.') + 1)
    );

    return (integer_part * 100) + decimal_part;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string lower_avg_score;
    int total_credits, available_credit;
    int lower_total_score, cur_score;

    lower_avg_score = input(total_credits, available_credit, cur_score);
    lower_total_score = round_up_decimal_numers(lower_avg_score);

    for (auto it = grade.rbegin(); it != grade.rend(); it++) {
        int course_score = it->second * available_credit;
        int new_score = (cur_score + course_score) / total_credits;
        
        if (lower_total_score < new_score) {
            cout << it->first << '\n';
            return 0;
        }
    }

    cout << "impossible\n";

    return 0;
}