#include    <iostream>
#include    <cmath>

using namespace std;

const static int MIN_NUM = -1000000;
const static int MAX_NUM = 1000000;

const static int NEGATIVE = -1;
const static int ZERO = 0;
const static int POSITIVE = 1;

typedef pair<int,int>   State;

static State f_positive[MAX_NUM+1],f_negative[MAX_NUM+1];

static inline int get_sign(int n) {
    return ((n>0)?POSITIVE:(n<0)?NEGATIVE:ZERO);
}

static inline int mod(int n) {
    return n%1000000000;
}

static inline int get_fibo_num(int num) {
    return  ((num>=0)?
                f_positive[num].first*f_positive[num].second:
                f_negative[-num].first*f_negative[-num].second);
}

static inline void print_fibo_num(int num) {
    int f = get_fibo_num(num);
    cout<<get_sign(f)<<'\n'<<abs(f)<<'\n';
}

void init(void)
{
    f_positive[0] = {ZERO,0};
    f_positive[1] = {POSITIVE,1};
}

void get_fibo_nums(void)
{
    for (int i=2;i<=MAX_NUM;i++) {
        int n1 = get_fibo_num(i-1);
        int n2 = get_fibo_num(i-2);
        f_positive[i] = {get_sign(n1+n2),mod(abs(n1+n2))};
    }

    for (int i=-1;i>=MIN_NUM;i--) {
        int n1 = get_fibo_num(i+1);
        int n2 = get_fibo_num(i+2);
        f_negative[abs(i)] = {get_sign(n2-n1),mod(abs(n2-n1))};
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    get_fibo_nums();

    int n;

    cin>>n;
    print_fibo_num(n);

    return  0;
}