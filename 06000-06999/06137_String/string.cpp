#include    <iostream>
#include    <string>

using namespace std;

const static int FRONT = 1;
const static int BACK = 2;
const static int TIE = 3;
const static int MAX_LEN_OF_LINE = 80;

int determine_pos(const string& s,int h,int t)
{
    for (;h<t;h++,t--) {
        if (s[h] != s[t]) {
            return  (s[h]<s[t])?FRONT:BACK;
        }
    }

    return  TIE;
}

void simuate(const string& A,string& T)
{
    int h = 0;
    int t = A.length()-1;

    for (;h<=t;) {
        int p = determine_pos(A,h,t);

        if (p == FRONT) {
            T.push_back(A[h++]);
        } else {
            T.push_back(A[t--]);
        }
    }
}

void print(const string& str)
{
    for (int i=0;i<str.length();i++) {
        if (i!=0 && i%MAX_LEN_OF_LINE==0) cout<<'\n';
        cout<<str[i];
    }
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string  A,T;

    cin>>N;

    for (int i=1;i<=N;i++) {
        char    c;
        cin>>c;
        A.push_back(c);
    }

    simuate(A,T);
    print(T);cout<<'\n';
    
    return  0;
}