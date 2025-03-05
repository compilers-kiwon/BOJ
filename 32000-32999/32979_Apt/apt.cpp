#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input(queue<int>& hands, vector<int>& num) {
    int N, T;

    cin>>N>>T;

    for (int i = 1; i <= 2*N; i++) {
        int a;
        cin>>a;
        hands.push(a);
    }

    for (int i = 1; i <= T; i++) {
        int b;
        cin>>b;
        num.push_back(b);
    }
}

void play_game(queue<int>& hands,
        const vector<int>& num, vector<int>& result) {
    for (int i = 0; i < num.size(); i++) {
        
        for (int j = 1; j < num[i]; j++) {
            hands.push(hands.front());
            hands.pop();
        }

        result.push_back(hands.front());
    }
}

void print_result(const vector<int>& result) {
    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<' ';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int> hands;
    vector<int> num, result;

    input(hands, num);
    play_game(hands, num, result);
    print_result(result);

    return 0;
}