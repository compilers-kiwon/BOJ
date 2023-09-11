#include    <iostream>
#include    <vector>

using namespace std;

#define get_min(a,b,c)  (min((a),min((b),(c))))
#define get_max(a,b,c)  (max((a),max((b),(c))))
#define get_mid(a,b,c)  \
    ((a)+(b)+(c)-get_max((a),(b),(c))-get_min((a),(b),(c)))

#define NUM_OF_RUNNERS  (3)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    vector<int> d[NUM_OF_RUNNERS];

    cin>>n;

    for (int r=0;r<NUM_OF_RUNNERS;r++) {
        for (int i=0;i<n;i++) {
            int k;
            cin>>k;
            d[r].push_back(k);
        }
    }

    for (int i=0;i<n;i++) {
        cout<<get_mid(d[0][i],
                d[1][i],d[2][i])<<(i==n-1?'\n':' ');
    }

    return  0;
}