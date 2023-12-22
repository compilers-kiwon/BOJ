#include    <iostream>
#include    <queue>

using namespace std;

static inline int get_min_num(priority_queue<int>& pq) {
    int ret = -pq.top();
    pq.pop();
    return  ret;
}

bool get_digits(int num,priority_queue<int>& digits)
{
    if (num == 1) {
        if (digits.empty()) digits.push(-1);
        return  true;
    }

    for (int i=9;i>=2;i--) {
        if (num%i == 0) {
            digits.push(-i);
            return  get_digits(num/i,digits);
        }
    }

    return  false;
}

int reduce_digits(priority_queue<int>& digits) {
    for (;digits.size()>=2;) {
        int d1 = get_min_num(digits);
        int d2 = get_min_num(digits);

        if (d1*d2 < 10) {
            digits.push(-(d1*d2));
        } else {
            digits.push(-d1);digits.push(-d2);
            break;
        }
    }

    return  digits.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        int N;
        priority_queue<int> d;

        cin>>N;
        
        if (!get_digits(N,d)) {
            cout<<"-1\n";
            continue;
        }

        cout<<reduce_digits(d)<<'\n'; 
    }

    return  0;
}