#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<double, double>> table = {
    {'B', {80.0f, 90.0f}}, {'C', {70.0f, 80.0f}},
    {'D', {60.0f, 70.0f}}, {'F', {0.0f, 60.0f}}
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<(MAX))

const vector<double> weight = {0.25f, 0.25f, 0.50f};

double input(void) {
    double ret = 0.0f;

    for (int i = 0; i < weight.size(); i++) {
        double s;
        cin >> s;
        ret += s * weight[i];
    }

    return ret;
}

char get_grade(double score) {
    char ret = 'A';

    for (auto it = table.begin(); it != table.end(); it++) {
        double lower = it->second.first;
        double upper = it->second.second;

        if (IN_RANGE(lower, score, upper) == true) {
            ret = it->first;
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double weighted_score = input();
    cout << get_grade(weighted_score) << '\n';

    return 0;
}