#include    <iostream>
#include    <string>

using namespace std;

#define HEIGHT  9

const static string heart[HEIGHT+1] = {
    "",
    " @@@   @@@ ",
    "@   @ @   @",
    "@    @    @",
    "@         @",
    " @       @ ",
    "  @     @  ",
    "   @   @   ",
    "    @ @    ",
    "     @     "
};

int print(int width)
{
    for(int h=1;h<=HEIGHT;h++)
    {
        for(int w=1;w<=width;w++)
        {
            cout<<heart[h]<<((w==width)?'\n':' ');
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int W;

    cin>>W;
    print(W);

    return  0;
}