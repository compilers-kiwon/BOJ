#include    <iostream>

using namespace std;

static inline bool is_even_number(int num) {
    return  ((num%2)==0);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    switch (N) {
        case 1:
        case 2:
            cout<<"4\n";
            break;
        default:
            cout<<(is_even_number(N)?N:N+1)<<'\n';
            break;
    }

    return  0;
}