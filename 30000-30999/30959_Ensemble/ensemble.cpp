#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> State; // <num of 0, num of 1>

#define MAX_NUM_OF_MODELS (16+1)
#define MAX_NUM_OF_ITEMS (100+1)

vector<int> correct;
int N, M;
State model[MAX_NUM_OF_MODELS][MAX_NUM_OF_ITEMS];

void input(void) {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int n;
        cin >> n;
        correct.push_back(n);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int n;

            cin >> n;

            if (n == 0) {
                model[i][j].first++;
            } else {
                model[i][j].second++;
            }
        }
    }
}

void read_model(int model_idx, vector<int>& m) {
    for (int i = 1; i <= M; i++) {
        State s = model[model_idx][i];
        m.push_back((s.first>s.second)?0:1);
    }
}

int get_accuracy(const vector<int>& a, const vector<int>& b) {
    int ret = 0;

    for (int i = 0; i < M; i++) {
        ret += (a[i]==b[i])?1:0;
    }

    return ret;
}

int get_max_accuracy(void) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        vector<int> cur_model;

        read_model(i, cur_model);
        ret = max(ret, get_accuracy(correct, cur_model));
    }

    return ret;
}

void get_ensemble_model(const vector<int>& selected, vector<int>& result) {
    for (int i = 1; i <= M; i++) {
        State s = {0, 0};

        for (int m = 0; m <selected.size(); m++) {
            s.first += model[selected[m]][i].first;
            s.second += model[selected[m]][i].second;
        }

        result.push_back((s.first>s.second)?0:1);
    }
}

void simulate(int cur, vector<int>& selected, int& max_ensemble_accuracy) {
    if (cur > N) {
        if ((selected.size() % 2) == 1) {
            vector<int> ensemble;
            get_ensemble_model(selected, ensemble);
            max_ensemble_accuracy =
                max(max_ensemble_accuracy, get_accuracy(correct, ensemble));
        }

        return;
    }

    selected.push_back(cur);
    simulate(cur + 1, selected, max_ensemble_accuracy);
    selected.pop_back();

    simulate(cur + 1, selected, max_ensemble_accuracy);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> selected;
    int max_accuracy_of_single, max_accuracy_of_ensemble;

    input();
    max_accuracy_of_single = get_max_accuracy();
    max_accuracy_of_ensemble = 0;

    simulate(1, selected, max_accuracy_of_ensemble);

    cout << (max_accuracy_of_ensemble > max_accuracy_of_single)?1:0 <<'\n';
    return 0;
}