#include    <iostream>
#include    <string>

using namespace std;

#define MAX_DISTANCE    2
#define END_OF_INPUT    'E'

#define get_distance(x1,y1,x2,y2)   \
    (((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2)))

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     K;
    int64   X,Y,tx,ty;
    string  m;
    bool    found;

    cin>>X>>Y>>K>>m;
    tx = ty = 0;

    found = false;
    m.push_back(END_OF_INPUT);

    for (int i=0;;i++) {
        if (get_distance(X,Y,tx,ty) <= MAX_DISTANCE) {
            cout<<i<<'\n';
            found = true;
        }

        if (m[i] == END_OF_INPUT) break;
        
        switch (m[i]) {
            case 'I':++tx;break;
            case 'S':++ty;break;
            case 'Z':--tx;break;
            case 'J':--ty;break;
            default:/*do nothing*/;break;
        }
    }

    if (found == false) cout<<"-1\n";
    return  0;
}