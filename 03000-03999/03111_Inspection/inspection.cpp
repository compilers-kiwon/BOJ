#include    <iostream>
#include    <string>
#include    <deque>

using namespace std;

static string       target;
static deque<char>  src,front,back;

void    init(void)
{
    string  str;

    cin>>target>>str;

    for(int i=0;i<str.length();i++)
    {
        src.push_back(str[i]);
    }
}

bool    get_front_char(char& c)
{
    if( !src.empty() )
    {
        c = src.front();
        src.pop_front();

        return  true;
    }

    if( !back.empty() )
    {
        c = back.front();
        back.pop_front();

        return  true;
    }

    return  false;
}

bool    remove_target_from_front(void)
{
    deque<char> buf;
    bool    ret = true;

    for(int i=target.length()-1;i>=0;i--)
    {
        if( target[i] != front.back() )
        {
            ret = false;
            break;
        }

        buf.push_front(front.back());
        front.pop_back();
    }

    if( ret == false )
    {
        for(;!buf.empty();buf.pop_front())
        {
            front.push_back(buf.front());
        }
    }

    return  ret;
}

bool    inspect_front(void)
{
    for(;;)
    {
        char    c;

        if( get_front_char(c) == false )
        {
            return  false;
        }
        
        front.push_back(c);

        if( front.size()<target.length() || c!=target.back() )
        {
            continue;
        }

        if( remove_target_from_front() == true )
        {
            break;
        }
    }

    return  true;
}

bool    get_back_char(char& c)
{
    if( !src.empty() )
    {
        c = src.back();
        src.pop_back();

        return  true;
    }

    if( !front.empty() )
    {
        c = front.back();
        front.pop_back();

        return  true;
    }

    return  false;
}

bool    remove_target_from_back(void)
{
    deque<char> buf;
    bool    ret = true;

    for(int i=0;i<target.length();i++)
    {
        if( target[i] != back.front() )
        {
            ret = false;
            break;
        }

        buf.push_back(back.front());
        back.pop_front();
    }

    if( ret == false )
    {
        for(;!buf.empty();buf.pop_back())
        {
            back.push_front(buf.back());
        }
    }

    return  ret;
}

bool    inspect_back(void)
{
    for(;;)
    {
        char    c;

        if( get_back_char(c) == false )
        {
            return  false;
        }
        
        back.push_front(c);
        
        if( back.size()<target.length() || c!=target.front() )
        {
            continue;
        }

        if( remove_target_from_back() == true )
        {
            break;
        }
    }

    return  true;    
}


void    print(deque<char>& dq)
{
    for(;!dq.empty();dq.pop_front())
    {
        cout<<dq.front();
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    for(;inspect_front();) inspect_back();

    print(front);
    cout<<'\n';

    return  0;
}