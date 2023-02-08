#include    <iostream>
#include    <string>

using namespace std;

#define is_removed(c,p) ((p).find((c))!=string::npos)

string  bite_code(const string& code)
{
    string  ret;
    const string JAVA = "JVA";

    for(int i=0;i<code.length();i++)
    {
        if( !is_removed(code[i],JAVA) )
        {
            ret.push_back(code[i]);
        }
    }

    return  ((ret.empty())?"nojava":ret);
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    string  code;

    cin>>N>>code;
    cout<<bite_code(code)<<'\n';

    return  0;
}