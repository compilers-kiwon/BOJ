#include    <iostream>
#include    <string>

using namespace std;

#define MAX_NUM_OF_STARS    100
#define exceed(k)           ((k)*(k)>MAX_NUM_OF_STARS)

#define get_stars(k) \
        (string(min(MAX_NUM_OF_STARS,(k)*(k)),'*'))

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int k=1;k<=n;k++)
    {
        cout<<get_stars(k)<<
            (exceed(k)?"...":"")<<'\n';
    }

    return  0;
}