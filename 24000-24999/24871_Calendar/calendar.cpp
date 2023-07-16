#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   d,m,w;
    int64   i,j,k,num_of_days;

    cin>>d>>m>>w>>i>>j>>k;
    num_of_days = (k-1)*(m*d)+(j-1)*(d)+i-1;    // shift "1~w" to "0~w-1"

    cout<<(char)('a'+(char)(num_of_days%w))<<'\n';
    return  0;
}