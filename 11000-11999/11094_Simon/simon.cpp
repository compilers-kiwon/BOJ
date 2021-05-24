#include    <iostream>
#include    <string>

using namespace std;

#define EXPECTED_HEAD_STR   "Simon says"
#define EXPECTED_HEAD_LEN   10

int main(void)
{
    int N;

    cin>>N;getchar();

    for(int i=1;i<=N;i++)
    {
        string  str;

        getline(cin,str);

        if( str.length()>EXPECTED_HEAD_LEN
            && str.substr(0,EXPECTED_HEAD_LEN)==EXPECTED_HEAD_STR )
        {
            cout<<str.substr(EXPECTED_HEAD_LEN,str.length()-EXPECTED_HEAD_LEN)<<'\n';
        }
    }

    return  0;
}