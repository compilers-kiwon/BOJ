#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,A,B;

    cin>>N;
    A = B = 0;

    for (int i=1;N>0;i++) {
        int s1,s2;

        s1 = N/2;
        s2 = N-s1;

        if (i%2 == 1) {
            B += max(s1,s2);
        } else {
            A += max(s1,s2);
        }

        N -= max(s1,s2);
    }

    cout<<A<<' '<<B<<'\n';
    return  0;
}