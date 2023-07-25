#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int     n;
        string  w;

        cin>>w>>n;
        cout<<"Shifting "<<w<<" by "
            <<n<<" positions gives us: "
            <<w.substr(w.length()-n,n)
            <<w.substr(0,w.length()-n)<<'\n';
    }

    return  0;
}