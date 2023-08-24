#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  w;

    for (;cin>>w;);
    cout<<(w=="eh?"?
        "Canadian":"Imposter")<<"!\n";

    return  0;
}