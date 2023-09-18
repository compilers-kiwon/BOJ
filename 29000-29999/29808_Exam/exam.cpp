#include    <iostream>
#include    <set>

using namespace std;

typedef long long int   int64;

#define SN_SCALER       (4763)
#define NUM_OF_DIFFS    (2)
#define NUM_OF_SCALERS  (2)

const static int64  scaler[NUM_OF_DIFFS][NUM_OF_SCALERS] 
    = {{508,108},{212,305}};

int simulate(set<pair<int64,int64>>& s,int64 sn)
{
    for (int64 d1=0;d1<=200;d1++) {
        for (int64 d2=0;d2<=200;d2++) {
            for (int i=0;i<NUM_OF_SCALERS;i++) {
                for (int j=0;j<NUM_OF_SCALERS;j++) {
                    if (d1*scaler[0][i]+d2*scaler[1][j] == sn ) {
                        s.insert({d1,d2});
                    }
                }
            }
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   S;
    set<pair<int64,int64>>  diffs;

    cin>>S;
    
    if (S%SN_SCALER != 0) {
        cout<<"0\n";
        return 0;
    }

    simulate(diffs,S/SN_SCALER);

    cout<<diffs.size()<<'\n';
    for (set<pair<int64,int64>>::iterator it=diffs.begin();
            it!=diffs.end();it++) {
        cout<<it->first<<' '<<it->second<<'\n';
    }

    return  0;
}