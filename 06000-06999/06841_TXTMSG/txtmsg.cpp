#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

static map<string,string> translation_table = {
    {"CU","see you"},
    {":-)","I’m happy"},
    {":-(","I’m unhappy"},
    {";-)","wink"},
    {":-P","stick out my tongue"},
    {"(~.~)","sleepy"},
    {"TA","totally awesome"},
    {"CCC","Canadian Computing Competition"},
    {"CUZ","because"},
    {"TY","thank-you"},
    {"YW","you’re welcome"},
    {"TTYL","talk to you later"}
};

#define is_included(table,str)  ((table).find((str))!=(table).end())

#define TRUE    1
#define FALSE   0
#define END_STR "TTYL"

int translate_message(const string& msg)
{
    cout<<(is_included(translation_table,msg)?
                    translation_table[msg]:msg)<<'\n';
    
    return  ((msg!=END_STR)?TRUE:FALSE);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int result=TRUE;result!=FALSE;)
    {
        string  str;

        cin>>str;
        result = translate_message(str);
    }

    return  0;
}