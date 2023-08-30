#include    <iostream>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

#define LEFT    0
#define RIGHT   1
#define UNKNOWN 2

#define RETURN_WITH_DIR(d)  {return ((d)==LEFT)?'L':'R';}

int forward_number(int mid,int to,
                        int left_size,int right_size)
{
    int most_left = mid-left_size;
    int most_right = mid+right_size;

    if (!IN_RANGE(most_left,to,most_right)) return UNKNOWN;
    return  IN_RANGE(most_left,to,mid)?LEFT:RIGHT;
}

int backward_number(int mid,int to,
                        int left_size,int right_size)
{
    int most_left = mid+left_size;
    int most_right = mid-right_size;

    if (!IN_RANGE(most_right,to,most_left)) return UNKNOWN;
    return  IN_RANGE(most_right,to,mid)?RIGHT:LEFT;
}

int simulate(int l,int r,int n,int m)
{
    if (n == m) return 'G';

    int f = forward_number(n,m,l,r);
    int b = backward_number(n,m,l,r);

    if (f==b && f!=UNKNOWN) RETURN_WITH_DIR(f);
    if (f != b) {
        if (f == UNKNOWN) RETURN_WITH_DIR(b);
        if (b == UNKNOWN) RETURN_WITH_DIR(f); 
    }

    return 'E';
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        int l,r,n,m;

        cin>>l>>r>>n>>m;
        cout<<(char)simulate(l,r,n,m)<<'\n';
    }

    return  0;
}