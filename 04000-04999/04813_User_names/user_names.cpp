#include    <iostream>
#include    <vector>
#include    <string>
#include    <set>

using namespace std;

#define is_special_character(c) ((c)=='-'||(c)=='\'')
#define is_upper_character(c)   ((c)>='A'&&(c)<='Z')
#define get_lower_character(c)  (is_upper_character((c))?(c)+32:(c))

void    get_each_word(const string& str,vector<string>& result)
{
    string  current;

    for(int i=0;i<str.length();i++)
    {
        char    c = str[i];

        if( c == ' ' )
        {
            result.push_back(current);
            current.clear();
        }
        else
        {
            if( is_special_character(c) == false )
            {
                current.push_back(get_lower_character(c));
            }
        }
    }
}

void    add_serial_number_to_user_name(string& user_name,set<string>& data_base,int max_length)
{
    string  sub;

    sub = user_name.substr(0,min((int)user_name.length(),max_length-1));

    for(char c='1';c<='9';c++)
    {
        string  tmp = sub;

        tmp.push_back(c);

        if( data_base.find(tmp) == data_base.end() )
        {
            user_name = tmp;
            return;
        }
    }

    sub = user_name.substr(0,min((int)user_name.length(),max_length-2));

    for(char c1='1';c1<='9';c1++)
    {
        for(char c2='0';c2<='9';c2++)
        {
            string  tmp = sub;

            tmp.push_back(c1);
            tmp.push_back(c2);

            if( data_base.find(tmp) == data_base.end() )
            {
                user_name = tmp;
                return;
            }
        }
    }
}

void    create_user_name(string& name,set<string>& data_base,
                                   string& result,int max_length)
{
    vector<string>  w;

    name.push_back(' ');
    get_each_word(name,w);

    string& first_name = w.front();
    string& last_name = w.back();

    result.push_back(first_name.front());

    for(int i=0;i<last_name.length()&&result.length()<max_length;i++)
    {
        result.push_back(last_name[i]);
    } 

    if( data_base.find(result) != data_base.end() )
    {
        add_serial_number_to_user_name(result,data_base,max_length);
    }
}

int     main(void)
{
    for(int c=1;;c++)
    {
        int     N,MAXLEN;
        string  head;

        getline(cin,head);
        sscanf(head.c_str(),"%d %d",&N,&MAXLEN);

        if( N==0 && MAXLEN==0 )
        {
            break;
        }

        cout<<"Case "<<c<<'\n';

        set<string> data_base;

        for(int i=1;i<=N;i++)
        {
            string  str,user_name;

            getline(cin,str);
            create_user_name(str,data_base,user_name,MAXLEN);

            cout<<user_name<<'\n';
            data_base.insert(user_name);
        }
    }

    return  0;
}