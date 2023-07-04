#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

static int  R,C;
static int  cw[MAX_SIZE][MAX_SIZE];
static int  ph[MAX_SIZE][MAX_SIZE];

#define EQUAL   0

int compare_with_rotation(void)
{
    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            int cw_row = C-col+1;
            int cw_col = row;

            if( cw[cw_row][cw_col] != ph[row][col] )
            {
                return  !EQUAL;
            }
        }
    }

    return  EQUAL;
}

int input(void)
{
    cin>>R>>C;

    for(int row=1;row<=C;row++)
    {
        for(int col=1;col<=R;col++)
        {
            cin>>cw[row][col];
        }
    }

    for(int row=1;row<=R;row++)
    {
        for(int col=1;col<=C;col++)
        {
            cin>>ph[row][col];
        }
    }

    return  0;
}

int print_suprised_cat(void)
{
    cout<<"|>___/|     /}\n";
    cout<<"| O O |    / }\n";
    cout<<"( =0= )\"\"\"\"  \\\n";
    cout<<"| ^  ____    |\n";
    cout<<"|_|_/    ||__|\n";

    return  0;    
}

int print_happy_cat(void)
{
    cout<<"|>___/|        /}\n";
    cout<<"| O < |       / }\n";
    cout<<"(==0==)------/ }\n";
    cout<<"| ^  _____    |\n";
    cout<<"|_|_/     ||__|\n";

    return  0;    
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    (compare_with_rotation()==EQUAL)?
        print_happy_cat():print_suprised_cat();

    return  0;
}