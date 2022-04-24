#include    <iostream>
#include    <cmath>
#include    <string>

using namespace std;

int main(void)
{
    for(;;)
    {
        string  str;
        double  R,S,V;
        
        getline(cin,str);

        if( str.empty() )
        {
            break;
        }

        for(int pos=0;;pos++)
        {
            if( str[pos] == '.' )
            {
                str.insert(pos,1,'0');
                break;
            }
        }

        sscanf(str.c_str(),"%lf %lf",&R,&S);
        V = sqrt((R*(S+0.16))/0.067);
        
        cout<<round(V)<<'\n';
    }

    return  0;
}