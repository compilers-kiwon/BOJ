#include    <iostream>

using namespace std;

#define TITLE_MESSAGE   "Material Management "
#define DONE_MESSAGE    "Classification ---- End!\n"

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        cout<<TITLE_MESSAGE<<i<<'\n';
        cout<<DONE_MESSAGE;
    }

    return  0;
}