#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_VOTERS   9

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt_of_tiger,cnt_of_lion;

    cnt_of_tiger = cnt_of_lion = 0;

    for(int i=1;i<=NUM_OF_VOTERS;i++)
    {
        string  v;

        cin>>v;

        cnt_of_tiger += (v=="Tiger")?1:0;
        cnt_of_lion += (v=="Lion")?1:0;
    }

    cout<<((cnt_of_tiger>cnt_of_lion)?"Tiger":"Lion")<<'\n';

    return  0;
}