#include    <iostream>
#include    <cmath>

using namespace std;

const static int MAX_TIME = 10000;
const static int PREFERRED_TIME = 2023;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        int n;

        cin>>n;
        if (n == 0) break;

        int team,min_diff;
        
        min_diff = MAX_TIME;

        for (int i=1;i<=n;i++) {
            int time;

            cin>>time;

            if (abs(PREFERRED_TIME-time) < min_diff) {
                team = i;
                min_diff = abs(PREFERRED_TIME-time);
            }
        }

        cout<<team<<'\n';
    }

    return  0;
}