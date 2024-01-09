#include    <iostream>
#include    <vector>
#include    <string>
#include    <cmath>

using namespace std;

const static int MAX_SIZE = 10;
const static int MIN_PRIME_NUM = 11;
const static int MAX_PRIME_NUM = 97;
const static char EMPTY = '0';

static int A,B,N;
static string number;
static vector<int> prime_numbers[MAX_SIZE];

static inline int chr2int(char c) {
    return  (int)(c-'0');
}

static inline int get_last_digit(int n) {
    return  n%10;
}

static inline string construct_number(int head,int tail,int length) {
    return  to_string(head)+string(length-4,EMPTY)+to_string(tail);
}

bool is_prime_num(int n)
{
    for (int i=2;i<=(int)sqrt(n);i++) {
        if (n%i == 0) return false;
    }

    return  true;
}

void get_prime_numbers(void)
{
    for (int i=MIN_PRIME_NUM;i<=MAX_PRIME_NUM;i++) {
        if (is_prime_num(i)) {
            prime_numbers[get_last_digit(i)].push_back(i);
        }
    }
}

void init(void)
{
    cin>>A>>B>>N;
    number = construct_number(A,B,N);
    get_prime_numbers();
}

bool dfs(int pos)
{
    const vector<int>& candidates = prime_numbers[chr2int(number[pos])];

    for (int i=0;i<candidates.size();i++) {
        char c = to_string(candidates[i]).front();

        if (number[pos-1] != EMPTY) {
            if (number[pos-1] == c) return true;
            else continue;
        }

        number[pos-1] = c;
        if (dfs(pos-1)) return true;
        number[pos-1] = EMPTY;
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    cout<<(dfs(N-2)?number:"-1")<<'\n';

    return  0;
}