#include    <iostream>
#include    <string>

using namespace std;

int simulate(const string& num)
{
    int     ret;
    string  prev_x = num;

    for (int i=1;;i++) {
        string  cur_x = to_string(prev_x.length());
        if (cur_x == prev_x) { ret=i;break; }
        prev_x = cur_x;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string  x0;

        cin>>x0;
        if (x0 == "END") break;
        cout<<simulate(x0)<<'\n';
    }

    return  0;
}