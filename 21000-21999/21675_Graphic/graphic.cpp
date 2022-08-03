#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    100
#define TABLE_SIZE  2

int w,h,image[2][MAX_SIZE][MAX_SIZE],table[TABLE_SIZE][TABLE_SIZE];

void    input(void)
{
    string  str;
    int     i;

    cin>>w>>h;

    for(i=0;i<2;i++)
    {
        for(int row=0;row<h;row++)
        {
            cin>>str;

            for(int col=0;col<w;col++)
            {
                image[i][row][col] = (int)(str[col]-'0');
            }
        }
    }

    cin>>str;
    i = 0;

    for(int row=0;row<TABLE_SIZE;row++)
    {        
        for(int col=0;col<TABLE_SIZE;col++,i++)
        {
            table[row][col] = (int)(str[i]-'0');
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int row=0;row<h;row++)
    {
        for(int col=0;col<w;col++)
        {
            int p1 = image[0][row][col];
            int p2 = image[1][row][col];

            cout<<table[p1][p2];
        }

        cout<<'\n';
    }

    return  0;
}