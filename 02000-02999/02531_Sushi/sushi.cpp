#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, d, k, c;
vector<int> sushi;
unordered_map<int,int> eatable;

void input(void) {
    cin>>N>>d>>k>>c;

    for (int i = 0; i < N; i++) {
        int s;
        cin>>s;
        sushi.push_back(s);
    }
}

void init(void) {
    for (int i = 0; i < k; i++) {
        const int cur_sushi = sushi[i];
        eatable[cur_sushi]++;
    }
}

int is_coupon_available(void) {
    return (eatable.find(c)==eatable.end()?1:0);
}

int get_num_of_sushi(void) {
    return (eatable.size() + is_coupon_available());
}

void remove_sushi(int s) {
    const int removed = sushi[s];
    eatable[removed]--;
    
    if (eatable[removed] == 0) {
        eatable.erase(removed);
    }
}

void add_sushi(int s) {
    const int added = sushi[s];
    eatable[added]++;
}

int eat_sushi(void) {
    int ret = 0;

    for (int head = 0, tail = k; head < N; head++, tail = (tail+1)%N) {
        ret = max(ret, get_num_of_sushi());
        
        if (sushi[head] != sushi[tail]) {
            remove_sushi(head);
            add_sushi(tail);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();init();

    cout<<eat_sushi()<<'\n';
    return 0;
}