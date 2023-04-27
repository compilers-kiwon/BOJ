#include    <iostream>
#include    <string>

using namespace std;

#define HEIGHT  5
#define WIDTH   4

const static string big[HEIGHT] = {
    "0000    1 2222 3333 4  4 5555 6666 7777 8888 9999",
    "0  0    1    2    3 4  4 5    6       7 8  8 9  9",
    "0  0    1 2222 3333 4444 5555 6666    7 8888 9999",
    "0  0    1 2       3    4    5 6  6    7 8  8    9",
    "0000    1 2222 3333    4 5555 6666    7 8888    9 " 
};

#define char2int(c)         ((int)((c)-'0'))
#define remove_empty(str)   {for(;(str).back()==' ';(str).pop_back());}

int print(int num)
{
    int col = num*(WIDTH+1);

    for(int row=0;row<HEIGHT;row++)
    {
        string  tmp = big[row].substr(col,WIDTH);

        remove_empty(tmp);
        cout<<tmp<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  num;

    cin>>num;

    for(int i=0;i<num.length();i++)
    {
        print(char2int(num[i]));
        if(i!=num.length()-1) cout<<'\n'; 
    }

    return  0;
}