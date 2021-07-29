#include    <iostream>
#include    <string>

using namespace std;

#define OFFSET          ('a'-'A')
#define lower2upper(c)  ((c)-OFFSET)
#define upper2lower(c)  ((c)+OFFSET)

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    capslock_on_numlock_off(string& input,string& output)
{
    for(int i=0;i<input.length();i++)
    {
        char&   c = input[i];

        if( IN_RANGE('0',c,'9') == true )
        {
            output.push_back(c);
            continue;
        }

        if( IN_RANGE('a',c,'z') == true )
        {
            output.push_back(lower2upper(c));
        }
        else
        {
            output.push_back(upper2lower(c));
        }
    }
}

void    capslock_off_numlock_on(string& input,string& output)
{
    for(int i=0;i<input.length();i++)
    {
        char&   c = input[i];

        if( IN_RANGE('0',c,'9') == true )
        {
            continue;
        }

        output.push_back(c);
    }
}

void    capslock_on_numlock_on(string& input,string& output)
{
    for(int i=0;i<input.length();i++)
    {
        char&   c = input[i];

        if( IN_RANGE('0',c,'9') == true )
        {
            continue;
        }

        if( IN_RANGE('a',c,'z') == true )
        {
            output.push_back(lower2upper(c));
        }
        else
        {
            output.push_back(upper2lower(c));
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        string  pw,entered,tmp;

        cin>>pw>>entered;
        cout<<"Case "<<i<<": ";

        if( pw == entered )
        {
            cout<<"Login successful.\n";
            continue;
        }

        tmp.clear();
        capslock_on_numlock_off(pw,tmp);

        if( entered == tmp )
        {
            cout<<"Wrong password. Please, check your caps lock key.\n";
            continue;
        }

        tmp.clear();
        capslock_off_numlock_on(pw,tmp);

        if( entered == tmp )
        {
            cout<<"Wrong password. Please, check your num lock key.\n";
            continue;
        }

        tmp.clear();
        capslock_on_numlock_on(pw,tmp);

        if( entered == tmp )
        {
            cout<<"Wrong password. Please, check your caps lock and num lock keys.\n";
            continue;
        }

        cout<<"Wrong password.\n";
    }

    return  0;
}