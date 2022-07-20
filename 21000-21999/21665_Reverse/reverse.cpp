#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

void    read_picture(int row_size,
                     vector<string>& input,
                     vector<string>& output)
{
    for(int row=1;row<=row_size;row++)
    {
        string  str;

        getline(cin,str);
        input.push_back(str);
    }

    getchar();

    for(int row=1;row<=row_size;row++)
    {
        string  str;

        getline(cin,str);
        output.push_back(str);
    }
}

int     compare_picture(vector<string>& input,vector<string>& output)
{
    int ret = 0;

    for(int row=0;row<input.size();row++)
    {
        for(int col=0;col<input.front().length();col++)
        {
            if( input[row][col] == output[row][col] )
            {
                ret++;
            }
        }
    }

    return  ret;
}

int     main(void)
{
    int n,m;
    vector<string>  in,out;

    cin>>n>>m;getchar();
    
    read_picture(n,in,out);
    cout<<compare_picture(in,out)<<'\n';

    return  0;
}