#include    <iostream>
#include    <string>

using namespace std;

#define MAX_NUM 50

static string   table[MAX_NUM] = {
    "0	0	0",
    "0	0	1",
    "0	1	1",
    "1	1	1",
    "No solution",
    "No solution",
    "-1	-1	2",
    "0	-1	2",
    "0	0	2",
    "0	1	2",
    "1	1	2",
    "-2	-2	3",
    "7	10	-11",
    "No solution",
    "No solution",
    "-1	2	2",
    "-511	-1609	1626",
    "1	2	2",
    "-1	-2	3",
    "0	-2	3",
    "1	-2	3",
    "-11	-14	16",
    "No solution",
    "No solution",
    "-2901096694	-15550555555	15584139827",
    "-1	-1	3",
    "0	-1	3",
    "0	0	3",
    "0	1	3",
    "1	1	3",
    "-283059965	-2218888517	2220422932",
    "No solution",
    "No solution",
    "8866128975287528	-8778405442862239	-2736111468807040",
    "-1	2	3",
    "0	2	3",
    "1	2	3",
    "0	-3	4",
    "1	-3	4",
    "117367	134476	-159380",
    "No solution",
    "No solution",
    "-80538738812075974	80435758145817515	12602123297335631",
    "2	2	3",
    "-5	-7	8",
    "2	-3	4",
    "-2	3	3",
    "6	7	-8",
    "-23	-26	31",
    "No solution"
};

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    if (table[N] == "No solution") {
        cout<<"0\n";
    } else {
        int64   a,b,c;
        sscanf(table[N].c_str(),"%lld %lld %lld",&a,&b,&c);
        cout<<a<<' '<<b<<' '<<c<<'\n';
    }

    return  0;
}