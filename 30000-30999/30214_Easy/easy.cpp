#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int s1,s2;
    cin>>s1>>s2;
    cout<<(s1*2>=s2?'E':'H')<<'\n';

    return  0;
}