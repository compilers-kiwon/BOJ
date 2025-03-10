#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void input(queue<int>& dolls) {
    int N;
    vector<int> height;

    cin>>N;

    for (int i = 0; i < N; i++) {
        int a;
        cin>>a;
        height.push_back(a);
    }

    sort(height.begin(), height.end());

    for (int i = 0; i < N; i++) {
        dolls.push(height[i]);
    }
}

void simulate(queue<int>& dolls) {
    vector<int> cur = {0, };

    for (int i = 1, size = dolls.size(); i <= size; i++, dolls.pop()) {
        if (dolls.front() > cur.back()) {
            cur.push_back(dolls.front());
        } else {
            dolls.push(dolls.front());
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    queue<int> dolls;
    int min_num_of_dolls;
    
    input(dolls);

    for (min_num_of_dolls = 0; !dolls.empty(); min_num_of_dolls++) {
        simulate(dolls);
    }

    cout<<min_num_of_dolls<<'\n';
    return 0;
}