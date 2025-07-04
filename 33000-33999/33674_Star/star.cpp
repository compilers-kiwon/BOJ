#include <iostream>
#include <vector>

using namespace std;

int simulate(int upper, int num_of_points, 
                int num_of_days, const vector<int>& stars) {
    int ret = 0;
    vector<int> cur(num_of_points, 0);
    

    for (int d = 1; d <= num_of_days; d++) {
        bool required_to_clean = false;

        for (int i = 0; i < num_of_points; i++) {
            cur[i] += stars[i];

            if (cur[i] > upper) {
                required_to_clean = true;
            }
        }

        if (required_to_clean == true) {
            for (int i = 0; i < num_of_points; i++) {
                cur[i] = stars[i];
            }
            
            ret++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, D, K;
    vector<int> stars;

    cin>>N>>D>>K;

    for (int i = 1; i <= N; i++) {
        int s;

        cin>>s;
        stars.push_back(s);
    }

    cout<<simulate(K, N, D, stars)<<'\n';

    return 0;
}