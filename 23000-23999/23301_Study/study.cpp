#include    <iostream>
#include    <vector>

using namespace std;

#define END_TIME    (1000)

typedef pair<int,int>   Time;

static int  N,T;
static vector<vector<Time>> available_time;

int input(void)
{
    cin>>N>>T;

    for (int i=1;i<=N;i++) {
        int K;
        vector<Time> time_info;

        cin>>K;

        for (int j=1;j<=K;j++) {
            int S,E;

            cin>>S>>E;
            time_info.push_back({S,E});
        }

        available_time.push_back(time_info);
    }

    return  0;
}

int get_satisfaction(int s_time,int e_time)
{
    int ret = 0;

    for (int i=0;i<N;i++) {
        vector<Time>&  t = available_time[i];

        for (int j=0;j<t.size();j++) {
            int&    S = t[j].first;
            int&    E = t[j].second;

            if (e_time <= S) break;
            ret += max(0,min(E,e_time)-max(S,s_time));
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_satisfication,best_time;

    input();
    max_satisfication = 0;

    for (int s=0;s+T<=END_TIME;s++) {
        int cur_satisfication = get_satisfaction(s,s+T);

        if (cur_satisfication > max_satisfication) {
            best_time = s;
            max_satisfication = cur_satisfication;
        }
    }

    cout<<best_time<<' '<<best_time+T<<'\n';
    return  0;
}