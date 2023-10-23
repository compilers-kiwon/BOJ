#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

int input(void)
{
    string  s1,s2;
    int sign,num;

    cin>>s1>>s2;

    if (s1=="AD" || s1=="BC") {
        sign = ((s1=="AD")?1:-1);
        num = (stoi(s2)*sign)-(sign==1?1:0);
    } else {
        sign = ((s2=="AD")?1:-1);
        num = (stoi(s1)*sign)-(sign==1?1:0);
    }

    return  num;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int y1 = input();
    int y2 = input();

    cout<<abs(y1-y2)<<'\n';
    return  0;
}