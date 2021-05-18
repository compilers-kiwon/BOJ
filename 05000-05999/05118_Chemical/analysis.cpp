#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define MAX_SIZE    (100+1)

int     n,m,min_num_of_selected;
string  element[MAX_SIZE],observed;

string  get_frequency(const vector<int>& selected)
{
    string  ret(n,'0');

    for(int i=0;i<selected.size();i++)
    {
        string& e = element[selected[i]];

        for(int j=0;j<n;j++)
        {
            if( ret[j]=='0' && e[j]=='1' )
            {
                ret[j] = '1';
            }
        }
    }

    return  ret;
}

void    produce_frequency(vector<int>& current,int idx)
{
    if( get_frequency(current) == observed )
    {
        min_num_of_selected = current.size();
        return;
    }

    if( current.size()==min_num_of_selected || idx>m )
    {
        return;
    }

    current.push_back(idx);
    produce_frequency(current,idx+1);

    current.pop_back();
    produce_frequency(current,idx+1);
}

void    input(void)
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>element[i];
    }

    cin>>observed;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int K;

    cin>>K;

    for(int k=1;k<=K;k++)
    {
        vector<int> e;

        input();
        min_num_of_selected = MAX_SIZE;

        produce_frequency(e,1);
        cout<<"Data Set "<<k<<":\n";

        if( min_num_of_selected == MAX_SIZE )
        {
            cout<<"Impossible\n";
        }
        else
        {
            cout<<min_num_of_selected<<'\n';
        }
        
        cout<<'\n';
    }

    return  0;
}