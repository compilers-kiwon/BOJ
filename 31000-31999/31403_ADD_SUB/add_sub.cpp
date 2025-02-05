#include <iostream>
#include <string>

using namespace std;

int func_number(int a, int b, int c) {
    return (a + b - c);
}

int func_string(int a, int b, int c) {
    return (stoi(to_string(a) + to_string(b)) - c);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int A, B, C;

    cin>>A>>B>>C;

    cout<<func_number(A, B, C)<<'\n';
    cout<<func_string(A, B, C)<<'\n';

    return 0;
}