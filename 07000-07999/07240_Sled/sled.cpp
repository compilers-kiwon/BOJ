#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,S,cur_speed;

    cin>>N>>S;
    cur_speed = 0;

    for (int i=1;i<=N;i++) {
        int a;

        cin>>a;
        cur_speed += a;
        cur_speed -= ((i!=N&&cur_speed>S)?1:0);
    }

    cout<<cur_speed<<'\n';
    return  0;
}