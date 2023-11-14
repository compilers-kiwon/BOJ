#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

void init(map<string,string>& table)
{
    table["NLCS"] = "North London Collegiate School";
    table["BHA"] = "Branksome Hall Asia";
    table["KIS"] = "Korea International School";
    table["SJA"] = "St. Johnsbury Academy";
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  str;
    map<string,string>  table;

    cin>>str;
    init(table);
    cout<<table[str]<<'\n';

    return  0;
}