#include    <iostream>
#include    <algorithm>
#include    <cstring>

using namespace std;

const static int num_of_rectangles = 3;

static inline bool is_sqaure(int rec[][2])
{
    int h0 = rec[0][0];
    int l0 = rec[0][1];
    int h1 = rec[1][0];
    int l1 = rec[1][1];
    int h2 = rec[2][0];
    int l2 = rec[2][1];

    return  (((h1==h2)&&(l1+l2==l0)&&(l0==h0+h1))
                ||((h0==h1)&&(h1==h2)&&(h0==l0+l1+l2)));
}

bool    build_square(int rec[][2],int rec_idx)
{
    if (rec_idx == num_of_rectangles) {
        return  is_sqaure(rec);
    }

    if (build_square(rec,rec_idx+1)) {
        return  true;
    }

    swap(rec[rec_idx][0],rec[rec_idx][1]);

    if (build_square(rec,rec_idx+1)) {
        return  true;
    }

    swap(rec[rec_idx][0],rec[rec_idx][1]);
    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int rec[num_of_rectangles][2];
    int rec_order[num_of_rectangles] = {0,1,2};

    for (int i=0;i<num_of_rectangles;i++) {
        cin>>rec[i][0]>>rec[i][1];
    }

    do {
        int tmp[num_of_rectangles][2];

        for (int i=0;i<num_of_rectangles;i++) {
            int rec_ptr = rec_order[i];
            memcpy(tmp[i],rec[rec_ptr],sizeof(int)*2);
        }

        if (build_square(tmp,0)) {
            cout<<"YES\n";
            return  0;
        }
    } while(next_permutation(rec_order,
                    rec_order+num_of_rectangles));

    cout<<"NO\n";
    return  0;
}