#include    <iostream>

using namespace std;

#define MINTUES_PER_DAY 1440

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int H1,M1,H2,M2,m1,m2;

        cin>>H1>>M1>>H2>>M2;
        m1 = H1*60+M1;
        m2 = H2*60+M2;

        if(m1==0 && m2==0) break;
        cout<<(m2-m1+MINTUES_PER_DAY)%MINTUES_PER_DAY<<'\n';
    }

    return  0;
}