#include    <iostream>
#include    <string>

using namespace std;

#define ROW_SIZE    4
#define COL_SIZE    8

#define MAX_NUM_OF_DESTINATIONS (50+1)

string  atm[ROW_SIZE] = {"***ABCDE","FGHIJKLMN","NOPQRSTU","VWXYZ***"};
int     N;
string  dst[MAX_NUM_OF_DESTINATIONS],current_input,candidate;

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>dst[i];
    }

    cin>>current_input;
}

void    get_next_chr(int idx)
{
    string& d = dst[idx];

    if( d.length()<=current_input.length() || 
            d.substr(0,current_input.length())!=current_input )
    {
        return;
    }

    candidate.push_back(d[current_input.length()]);
}

void    print(void)
{
    for(int row=0;row<ROW_SIZE;row++)
    {
        for(int col=0;col<COL_SIZE;col++)
        {
            if( candidate.find(atm[row][col]) != string::npos )
            {
                cout<<atm[row][col];
            }
            else
            {
                cout<<'*';
            }
        }

        cout<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=1;i<=N;i++)
    {
        get_next_chr(i);
    }

    print();

    return  0;
}