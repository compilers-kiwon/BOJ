#include    <iostream>
#include    <vector>
#include    <string>
#include    <cmath>

using namespace std;

const static int    NUM_OF_BUFFERS = 2;
const static int    MAX_SIZE = 20;
const static int    MAX_NUM_OF_ITERATIONS = 1000;

static inline int   get_next(int cur,int size)
{
    return  (cur+1)%size;
}

int simulate(int size,int cur[],int next[])
{
    for (int i=0;i<size;i++) {
        next[i] = abs(cur[i]-cur[get_next(i,size)]);
    }

    return  0;
}

bool    same_entry(int num[],int size)
{
    for (int i=0;i<size;i++) {
        if (num[i] != num[get_next(i,size)]) return false;
    }

    return  true;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int t=1;;t++) {
        int n,num[NUM_OF_BUFFERS][MAX_SIZE],cur_ptr,it;

        cin>>n;
        if (n == 0) break;

        cur_ptr = 0;
        for (int i=0;i<n;i++) cin>>num[cur_ptr][i];

        for (it=0;it<=MAX_NUM_OF_ITERATIONS;it++) {
            if (same_entry(num[cur_ptr],n)) {
                break;
            }

            simulate(n,num[cur_ptr],
                    num[get_next(cur_ptr,NUM_OF_BUFFERS)]);
            cur_ptr = get_next(cur_ptr,NUM_OF_BUFFERS);
        }

        cout<<"Case "<<t<<": "<<
            (it>MAX_NUM_OF_ITERATIONS?
                "not attained\n":to_string(it)+" iterations\n");
    }

    return  0;
}