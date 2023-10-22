#include    <iostream>
#include    <vector>

using namespace std;

const static int    MAX_NUM_OF_COWS = 145+1;

static vector<int>  working_time[MAX_NUM_OF_COWS];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,Nlines;

    cin>>N>>Nlines;

    for (int i=1;i<=Nlines;i++) {
        int C,HH,MM;
        string keyword;

        cin>>C>>keyword>>HH>>MM;

        if (keyword == "START") {
            working_time[C].push_back(-(HH*60+MM));
        } else {
            working_time[C].back() += (HH*60+MM);
        }
    }

    for (int i=1;i<=N;i++) {
        int total = 0;

        for (int j=0;j<working_time[i].size();j++) {
            total += working_time[i][j];
        }

        cout<<total/60<<' '<<total%60<<'\n';
    }

    return  0;
}