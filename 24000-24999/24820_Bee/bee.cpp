#include    <iostream>
#include    <string>

using namespace std;

bool    check_spelling(bool table[],char center,string& w)
{
    bool    visit_bee,visit_center;

    visit_bee = true;
    visit_center = false;

    for(int i=0;i<w.length();i++)
    {
        visit_bee &= table[w[i]];
        visit_center |= (center==w[i]);
    }
    
    return  (visit_bee&visit_center);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     n;
    string  bee,word;
    bool    table[0x100];

    cin>>bee>>n;
    fill(&table['a'],&table['z'+1],false);

    for(int i=0;i<bee.length();i++)
    {
        table[bee[i]] = true;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>word;

        if( word.length()>=4 && check_spelling(table,bee.front(),word)==true )
        {
            cout<<word<<'\n';
        }
    }
    
    return  0;
}