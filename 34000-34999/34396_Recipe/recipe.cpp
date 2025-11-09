#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long int int64;
typedef pair<string, int64> Part;

unordered_map<string, vector<Part>> component;
unordered_map<string, int64> cost_table;

const string final_product = "Capstone";

void input(void) {
    int N;

    for (cin >> N; N > 0; N--) {
        int64 C;
        string raw_material;

        cin >> raw_material >> C;
        cost_table[raw_material] = C;
    }

    int M;

    for (cin >> M; M > 0; M--) {
        int P;
        string imm_component;

        cin >> imm_component >> P;

        for (int i = 1; i <= P; i++) {
            Part cur;
            cin >> cur.first >> cur.second;
            component[imm_component].push_back(cur);
        }
    }
}

int64 get_cost(const string& component_name) {
    int64& ret = cost_table[component_name];
    
    if (ret != 0) {
        return ret;
    }
    
    const vector<Part>& sub = component[component_name];

    for (int i = 0; i < sub.size(); i++) {
        ret += get_cost(sub[i].first) * sub[i].second;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << get_cost(final_product) << '\n';

    return 0;
}