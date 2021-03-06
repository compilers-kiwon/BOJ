#include    <iostream>
#include    <string>
#include    <algorithm>
#include    <vector>

using namespace std;

#define MAX_NUMBERS 100000

bool    visited[MAX_NUMBERS];

int     str2int(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        ret = ret*10+(int)(str[i]-'0');
    }

    return  ret;
}

void    find_all_numbers(string& src,vector<int>& numbers)
{
   sort(src.begin(),src.end());

    do{
        int n;

        if( src[0]!='0' && visited[n=str2int(src)]==false )
        {
            visited[n] = true;;
            numbers.push_back(n);
        }
    }while(next_permutation(src.begin(),src.end()));
}

int     count_wornderful_fours(const vector<int>& numbers)
{
    int ret = 0;

    for(int i=0;i<numbers.size();i++)
    {
        for(int j=i+1;j<numbers.size();j++)
        {
            for(int k=j+1;k<numbers.size();k++)
            {
                for(int l=k+1;l<numbers.size();l++)
                {
                    int    s1 = numbers[i];
                    int    s2 = numbers[j];
                    int    s3 = numbers[k];
                    int    s4 = numbers[l];

                    if( s1+s2+s3 == s4 )
                    {
                        ret++;
                    }
                }
            }
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  K5;

    for(int i=1;i<=5;i++)
    {
        char    c;

        cin>>c;
        K5.push_back(c);
    }

    vector<int>     s_numbers;

    find_all_numbers(K5,s_numbers);
    cout<<count_wornderful_fours(s_numbers)<<'\n';

    return  0;
}