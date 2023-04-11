#include    <iostream>
#include    <string>

using namespace std;

#define NUM_OF_NUMBERS      (9+1)
#define HEIGHT_OF_NUMBER    9  
#define NUM_OF_LINES        4

#define NONE    -1
#define EMPTY   -2

const string line_str[NUM_OF_LINES] = {
    " * * *","*     *","      *","*"
};

const int number[NUM_OF_NUMBERS][HEIGHT_OF_NUMBER] = {
    {0,1,1,1,EMPTY,1,1,1,0},{EMPTY,2,2,2,EMPTY,2,2,2,NONE},
    {0,2,2,2,0,3,3,3,0},{0,2,2,2,0,2,2,2,0},
    {EMPTY,1,1,1,0,2,2,2,NONE},{0,3,3,3,0,2,2,2,0},
    {0,3,3,3,0,1,1,1,0},{0,2,2,2,EMPTY,2,2,2,NONE},
    {0,1,1,1,0,1,1,1,0},{0,1,1,1,0,2,2,2,0},
};

int print(int n)
{
    for(int h=0;h<HEIGHT_OF_NUMBER;h++)
    {
        int d = number[n][h];

        switch(d)
        {
            case EMPTY:cout<<'\n';
            case NONE:break;
            default:cout<<line_str[d]<<'\n';break;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;
    print(n);

    return  0;
}