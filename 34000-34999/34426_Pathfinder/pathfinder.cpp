#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Path;

#define speed first
#define distance second

int find_fatest_path(const vector<Path>& p) {
    int fastest = 0;

    for (int i = 0; i < p.size(); i++) {
        const Path& fastest_path = p[fastest];
        const Path& cur_path = p[i];

        if ((fastest_path.distance * cur_path.speed)
                > (cur_path.distance * fastest_path.speed)){
            fastest = i;
        }
    }

    return (fastest + 1);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        int num_of_paths;
        vector<Path> paths;

        for (cin >> num_of_paths; num_of_paths > 0; num_of_paths--) {
            Path p;
            cin >> p.speed >> p.distance;
            paths.push_back(p);
        }

        cout << find_fatest_path(paths) << '\n';
    }

    return 0;
}