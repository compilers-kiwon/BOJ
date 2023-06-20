#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    6

static string   x[MAX_SIZE+1];

int remove_tailing_space(string& s)
{
    for(;s.back()==' ';s.pop_back());
    return  0;
}

int input(void)
{
    for(int i=1;i<=MAX_SIZE;i++)
    {
        getline(cin,x[i]);
        remove_tailing_space(x[i]);
    }

    return  0;
}

int output(void)
{
    cout<<"Latitude "<<x[1].length()<<':'
        <<x[2].length()<<':'<<x[3].length()<<'\n';
    cout<<"Longitude "<<x[4].length()<<':'
        <<x[5].length()<<':'<<x[6].length()<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    output();

    return  0;
}