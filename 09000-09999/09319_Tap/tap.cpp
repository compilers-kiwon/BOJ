#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)

typedef pair<int,int> Pos;

static double   r[MAX_SIZE],sum,B;
static int      s[MAX_SIZE];
static Pos      P[MAX_SIZE],listen;

#define get_dist(p1,p2) \
    (((p1).first-(p2).first)*((p1).first-(p2).first) \
        +((p1).second-(p2).second)*((p1).second-(p2).second))

#define is_available(sum,cur,B) ((cur)>(6.0*((B)+((sum)-(cur)))))

int input(void)
{
    int n;

    cin>>n>>B>>listen.first>>listen.second;

    for (int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second>>s[i];
    }

    return  n;
}

double  get_strength(int idx)
{
    int     dist = get_dist(listen,P[idx]);
    double  strength =
        ((double)s[idx])/((double)dist);
    
    return  strength;
}

int find_avaiable_tap(int num_of_taps)
{
    int ret = 0;

    sum = 0.0;

    for (int i=1;i<=num_of_taps;i++) {
        r[i] = get_strength(i);
        sum += r[i];
    }

    for (int i=1;i<=num_of_taps;i++) {
        if (is_available(sum,r[i],B)) {
            ret = i;
            break;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    cin>>t;

    for (int i=1;i<=t;i++) {
        int n = input();
        int available = find_avaiable_tap(n);

        if (available == 0) cout<<"NOISE\n";
        else cout<<available<<'\n';
    }

    return  0;
}