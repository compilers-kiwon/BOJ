#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_num_of_diffs(const string& s1, const string& s2) {
    int ret = 0;

    for (int i = 0; i < s1.length(); i++) {
        ret += (s1[i]!=s2[i])?1:0;
    }

    return ret;
}

int get_score(const vector<string>& male,
                const vector<string>& female) {
    int ret = 0;

    for (int i = 0; i < male.size(); i++) {
        ret += get_num_of_diffs(male[i], female[i]);
    }

    return ret;
}

void input(vector<string>& male, vector<string>& female) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        string mbti;
        cin >> mbti;
        male.push_back(mbti);
    }

    for (int i = 1; i <= N; i++) {
        string mbti;
        cin >> mbti;
        female.push_back(mbti);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> male_mbti, female_mbti;

    input(male_mbti, female_mbti);
    sort(female_mbti.begin(), female_mbti.end());

    int max_score = 0;

    do {
        max_score = max(max_score,
                        get_score(male_mbti, female_mbti));
    } while (next_permutation(female_mbti.begin(), female_mbti.end()));

    cout << max_score << '\n';
    return 0;
}