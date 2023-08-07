#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_ROOMS    10

#define EMPTY       '0'
#define OCCUPIED    '1'

#define char2int(c)         ((int)((c)-'0'))
#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define LEFT    -1
#define RIGHT   1

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    string  events,room;

    cin>>n>>events;
    room = string(NUM_OF_ROOMS,'0');

    for (int p=0;p<n;p++) {
        char&   c = events[p];

        if (isdigit(c)) {
            room[char2int(c)] = EMPTY;
        } else {
            for (int i=(c=='L')?0:NUM_OF_ROOMS-1;
                 IN_RANGE(0,i,NUM_OF_ROOMS-1);
                 i+=(c=='L')?RIGHT:LEFT) {
                if (room[i] == EMPTY) {
                    room[i] = OCCUPIED;
                    break;
                }
            }
        }
    }

    cout<<room<<'\n';
    return  0;
}