#include    <iostream>

using namespace std;

#define NUM_OF_TARGETS  (16)

typedef struct{int r,g,b;}  RGB;

#define get_distance(t,r,g,b) \
    (((t).r-(r))*((t).r-(r))+((t).g-(g))*((t).g-(g))+((t).b-(b))*((t).b-(b)))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    RGB t[NUM_OF_TARGETS+1];

    for (int i=1;i<=NUM_OF_TARGETS;i++) {
        cin>>t[i].r>>t[i].g>>t[i].b;
    }

    for (;;) {
        int r,g,b;

        cin>>r>>g>>b;
        if (r==-1 && g==-1 && b==-1) break;

        int nearest_idx,nearest_value;

        nearest_value = 0x7FFFFFFF;

        for (int i=1;i<=NUM_OF_TARGETS;i++) {
            int d = get_distance(t[i],r,g,b);

            if (d < nearest_value) {
                nearest_idx = i;
                nearest_value = d;
            }
        }

        cout<<'('<<r<<','<<g<<','<<b<<") maps to ("<<
            t[nearest_idx].r<<','<<t[nearest_idx].g<<','<<t[nearest_idx].b<<")\n";
    }

    return  0;
}