#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int64_t simulate(size_t num_of_fans) {
    int64_t ret = 0;
    queue<int64_t> speed;
    vector<int64_t> available;

    for (size_t i = 1; i <= num_of_fans; i++) {
        int64_t S;

        cin>>S;
        speed.push(S);
    }

    available.push_back(0);

    for (size_t i = 1; i <= num_of_fans; i++) {
        char C;
        int64_t cur_speed = speed.front();

        cin>>C;
        
        if (C == 'T') {
            available.back() += cur_speed;
        } else {
            if (available.back() >= 0) {
                available.push_back(-cur_speed);
            } else {
                available.back() -= cur_speed;
            }
        }
        speed.pop(); 
    }

    for (size_t i = 0; i < available.size(); i++) {
        ret += (available[i]>0)?available[i]:0;
    }
    
    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    size_t T;

    cin>>T;

    for (size_t i = 1; i <= T; i++) {
        size_t N;

        cin>>N;
        cout<<simulate(N)<<'\n';
    }

    return 0;
}