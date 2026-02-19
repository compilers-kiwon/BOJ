#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define F1 (1)
#define F2 (1)

#define get_pos(p,m) (((p)-1ULL)%(m))

void get_fibo_num(vector<int>& num, int mod) {
    int n1 = num.front();
    int n2 = num.back();

    do {
        int n3 = (n1 + n2) % mod;

        num.push_back(n3);
        n1 = n2;
        n2 = n3;
    } while (!(n1 == F1 && n2 == F2));

    num.pop_back();
    num.pop_back();
}

void get_music(const vector<int>& src, string& dst) {
    for (int i = 0; i < src.size(); ++i) {
        dst += to_string(src[i]);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Q, M;
    string fibo_music;
    vector<int> fibo_num = {F1, F2};

    cin >> Q >> M;
    get_fibo_num(fibo_num, M);
    get_music(fibo_num, fibo_music);

    for (int i = 1; i <= Q; ++i) {
        size_t N, pos;
        
        cin >> N;
        pos = get_pos(N, fibo_music.length());
        cout << fibo_music[pos] << '\n';
    }

    return 0;
}