#include    <iostream>
#include    <string>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int G,S,C,buying_power;

    cin>>G>>S>>C;
    buying_power = G*3+S*2+C*1;

    string  v,t;

    if (buying_power>=8) v="Province";
    else if (buying_power>=5) v="Duchy";
    else if (buying_power>=2) v="Estate";

    if (buying_power>=6) t="Gold";
    else if (buying_power>=3) t="Silver";
    else t="Copper";

    cout<<v<<(v.empty()?"":" or ")<<t<<'\n';
    return  0;
}