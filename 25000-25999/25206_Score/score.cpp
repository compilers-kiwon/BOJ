#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define SIZE_OF_INPUTS  20

static map<string,double> table = {
    {"A+",4.5},{"A0",4.0},{"B+",3.5},{"B0",3.0},
    {"C+",2.5},{"C0",2.0},{"D+",1.5},{"D0",1.0},
    {"F",0.0}
};

int input(double& credits,double& grade)
{
    for(int i=1;i<=SIZE_OF_INPUTS;i++)
    {
        string  s,g;
        double  c;

        cin>>s>>c>>g;

        if( g == "P" )
        {
            continue;
        }

        credits += c;
        grade += table[g]*c;
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double  c,g;

    c = g = 0.0;
    input(c,g);

    cout<<fixed;cout.precision(5);
    cout<<g/c<<'\n';

    return  0; 
}