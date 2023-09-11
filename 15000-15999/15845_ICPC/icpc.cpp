#include    <iostream>
#include    <vector>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,win,max_score;
    vector<int> T;

    cin>>N>>M;
    max_score = -1;

    for (int i=0;i<M;i++) {
        int num_of_testcases;
        cin>>num_of_testcases;
        T.push_back(num_of_testcases);
    }

    for (int i=1;i<=N;i++) {
        int cur_score = 0;

        for (int j=0;j<M;j++) {
            int solved;
            cin>>solved;
            cur_score += (solved==T[j])?1:0;
        }

        if (cur_score > max_score) {
            win = i;
            max_score = cur_score;
        }
    }

    cout<<win<<'\n';
    return  0;
}