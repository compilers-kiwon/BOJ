#include    <iostream>
#include    <string>

using namespace std;

typedef struct{int w,n,d;}  Number;

#define NONE(n) ((n)==0)

int parse(const string& str,Number& num)
{
    if (str.find(',')!=string::npos
            && str.find('/')!=string::npos) {
        sscanf(str.c_str(),"%d,%d/%d",&num.w,&num.n,&num.d);
    } else if (str.find(',')==string::npos
                && str.find('/')==string::npos) {
        num.w = stoi(str);
        num.n = 0;
        num.d = 1;
    } else {
        num.w = 0;
        sscanf(str.c_str(),"%d/%d",&num.n,&num.d);
    }

    return  0;
}

int get_gcd(int small,int big)
{
    int mod = big%small;

    for(;mod!=0;mod=big%small) {
        big = small;
        small = mod;
    }

    return  small;
}

Number  add(const Number& n1,const Number& n2)
{
    Number  ret;

    ret.n = n1.n*n2.d+n2.n*n1.d;
    ret.d = n1.d*n2.d;
    
    ret.w = n1.w+n2.w+ret.n/ret.d;
    ret.n %= ret.d;

    if (!NONE(ret.n)) {
        int gcd = get_gcd(ret.n,ret.d);

        ret.n /= gcd;
        ret.d /= gcd;
    }
    
    return  ret;
}

int simulate(int num_of_numbers,Number& n)
{
    n = {0,0,1};

    for (int i=1;i<=num_of_numbers;i++) {
        string  num;
        Number  cur;

        cin>>num;
        parse(num,cur);
        n = add(n,cur);
    }

    return  0;
}

int print_number(const Number& n,int idx)
{
    cout<<"Test "<<idx<<": ";

    if (NONE(n.w) && NONE(n.n)) {
        cout<<"0\n";
    } else if (NONE(n.w)) {
        cout<<n.n<<'/'<<n.d<<'\n';
    } else if (NONE(n.n)) {
        cout<<n.w<<'\n';
    } else {
        cout<<n.w<<','<<n.n<<'/'<<n.d<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int i=1;;i++) {
        int     n;
        Number  sum;

        cin>>n;
        if (NONE(n)) break;

        simulate(n,sum);
        print_number(sum,i);
    }

    return  0;
}