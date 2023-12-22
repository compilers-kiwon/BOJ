#include    <iostream>
#include    <string>
#include    <algorithm>

using namespace std;

const static int NUM_OF_DIGITS = 4;
const static string END_OF_INPUT = "-1";

static bool is_final_number(int n) {
    return  (n==6174 | n==0);
}

static inline int chr2int(char c) {
    return  (int)(c-'0');
}

static inline string remove_leading_zero(const string& num) {
    return  to_string(stoi(num));
}

static inline bool is_valid_number(const string& num) {
    int cnt[0x100] = {0,};

    if (num.length() != NUM_OF_DIGITS) return false;
    
    for (int i=0;i<NUM_OF_DIGITS;i++) {
        if (++cnt[num[i]] == NUM_OF_DIGITS) return false;
    }
    
    return  true;
}

int get_min_num(const string& num) {
    int ret = 0;
    for (int i=0;i<num.length();i++) ret=ret*10+chr2int(num[i]);
    return  ret;
}

int get_max_num(const string& num) {
    int ret = 0;
    for (int i=num.length()-1;i>=0;i--) ret=ret*10+chr2int(num[i]);
    return  ret;
}

int simulate(string& num) {
    if (!is_valid_number(num)) return 0;

    int num_of_operations;

    for (num_of_operations=1;;num_of_operations++) {
        sort(num.begin(),num.end());

        int max_num = get_max_num(num);
        int min_num = get_min_num(num);
        int result = max_num-min_num;

        cout<<max_num<<'-'<<min_num<<'='<<result<<'\n';
        if (is_final_number(result)) break;

        num = to_string(result);
    }

    return  num_of_operations;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;) {
        string  N;
        int num_of_operations;

        cin>>N;
        if (N == END_OF_INPUT) break;
        
        N = remove_leading_zero(N);
        cout<<"N="<<N<<":\n";

        if ((num_of_operations=simulate(N)) == 0) {
            cout<<"No!!\n";
        } else {
            cout<<"Ok!! "<<num_of_operations<<" times\n";
        }
    }

    return  0;
}