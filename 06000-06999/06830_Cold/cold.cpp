#include    <iostream>
#include    <string>

using namespace std;

#define MAX_LEN 256
#define INF     0x7FFFFFFF

int main(void)
{
    string  name;
    int     low_temperature;

    for(low_temperature=INF;;)
    {
        string  in;

        getline(cin,in);
        if(in.empty()) break;

        char    city[MAX_LEN];
        int     temperature;

        sscanf(in.c_str(),"%s %d",
                &city[0],&temperature);

        if( low_temperature > temperature )
        {
            name = string(city);
            low_temperature = temperature;
        }
    }

    cout<<name<<'\n';
    return  0;
}