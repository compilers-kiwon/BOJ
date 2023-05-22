#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

typedef pair<int,int>   Cost;

static map<string,Cost> cost_table = {
  {"Paper",{57,99}},{"Printer",{120,50}},{"Planners",{31,25}},
  {"Binders",{22,50}},{"Calendar",{10,95}},{"Notebooks",{11,20}},
  {"Ink",{66,95}}
};

int main(void)
{
    Cost c = {0,0};

    for(;;)
    {
        string  item;

        cin>>item;
        if(item=="EOI") break;

        c.first += cost_table[item].first;
        c.second += cost_table[item].second;
    }

    printf("$%d.%02d\n",c.first+c.second/100,c.second%100);

    return  0;
}