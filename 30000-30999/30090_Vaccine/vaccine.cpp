#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (10*10)

void input(vector<string>& materials) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        materials.push_back(s);
    }

    sort(materials.begin(), materials.end());
}

void get_vaccine(string& cur, const string& m) {
    int size_of_common = min(cur.length(), m.length());

    for (; size_of_common > 0; --size_of_common) {
        string h = cur.substr(cur.length() - size_of_common, size_of_common);
        string t = m.substr(0, size_of_common);

        if (h == t) {
            break;
        }
    }

    cur += m.substr(size_of_common);
}

int simulate(const vector<string>& materials) {
    string merged;

    for (int i = 0; i < materials.size(); ++i) {
        get_vaccine(merged, materials[i]);
    }

    return merged.length();
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_length;
    vector<string> materials;

    input(materials), min_length = INF;

    do {
        min_length = min(min_length, simulate(materials));
    } while (next_permutation(materials.begin(), materials.end()));

    cout << min_length << '\n';

    return 0;
}