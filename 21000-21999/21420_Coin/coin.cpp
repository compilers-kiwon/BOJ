#include    <iostream>

using namespace std;

#define FRONT   0
#define BACK    1

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,cnt_of_front,cnt_of_back;

    cin>>n;
    cnt_of_front = cnt_of_back = 0;

    for(int i=1;i<=n;i++)
    {
        int c;

        cin>>c;
        ((c==FRONT)?cnt_of_front++:cnt_of_back++);
    }

    cout<<min(cnt_of_front,cnt_of_back)<<'\n';

    return  0;
}