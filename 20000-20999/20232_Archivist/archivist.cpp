#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

void    init(map<int,string>& t)
{
    t[1995] = "ITMO";
    t[1996] = "SPbSU";
    t[1997] = "SPbSU";
    t[1998] = "ITMO";
    t[1999] = "ITMO";
    t[2000] = "SPbSU";
    t[2001] = "ITMO";
    t[2002] = "ITMO";
    t[2003] = "ITMO";
    t[2004] = "ITMO";
    t[2005] = "ITMO";
    t[2006] = "PetrSU, ITMO";
    t[2007] = "SPbSU";
    t[2008] = "SPbSU";
    t[2009] = "ITMO";
    t[2010] = "ITMO";
    t[2011] = "ITMO";
    t[2012] = "ITMO";
    t[2013] = "SPbSU";
    t[2014] = "ITMO";
    t[2015] = "ITMO";
    t[2016] = "ITMO";
    t[2017] = "ITMO";
    t[2018] = "SPbSU";
    t[2019] = "ITMO";
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int y;
    map<int,string> list_of_winners;

    init(list_of_winners);

    cin>>y;
    cout<<list_of_winners[y]<<'\n';

    return  0;
}