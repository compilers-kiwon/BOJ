#include    <iostream>

using namespace std;

#define NUM_OF_USED_CHARS   2
#define TARGET_LENGTH       7
#define TARGET_COMMAND      "AABBABB"
#define CURRENT_CHAR(c,s)   ((c)==(s)[0]?'A':'B')

string  build_command(const string& str,
                        const string& command)
{
    string  ret;

    for(int i=0;i<command.length();i++)
    {
        ret.push_back(CURRENT_CHAR(command[i],str));
    }

    return  ret;
}

string  analysis_command(const string& command)
{
    bool    found[0x100] = {false,};
    string  ret;

    for(int i=0;i<command.length();i++)
    {
        if( found[command[i]] == false )
        {
            found[command[i]] = true;
            ret.push_back(command[i]);
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int i=1;i<=T;i++)
    {
        string  command,used;

        cin>>command;

        if( command.length() != TARGET_LENGTH )
        {
            cout<<"0\n";
            continue;
        }

        used = analysis_command(command);

        if( used.length()!=NUM_OF_USED_CHARS ||
                build_command(used,command)!=TARGET_COMMAND )
        {
            cout<<"0\n";
            continue;
        }

        cout<<"1\n";
    }

    return  0;
}