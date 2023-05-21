#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

static vector<string>   dat;

typedef long long int   int64;

#define ASON_HEAD   "["
#define ASON_TAIL   "]"

#define SIZE_OF_ASON_FORMAT     8
#define SIZE_OF_NUMBER_DATA(d)  8
#define SIZE_OF_STRING_DATA(d)  ((d).length()+12)

int input(void)
{
    for(;;)
    {
        string  str;

        cin>>str;
        if(str.empty()) break;
        dat.push_back(str);
    }

    return  0;
}

bool    is_number(const string& s)
{
    for(int i=0;i<s.length();i++)
    {
        if( !isdigit(s[i]) )
        {
            return  false;
        }
    }

    return  true;
}

int64   get_size_of_data(void)
{
    vector<int64>   st;

    st.push_back(0);

    for(int i=0;i<dat.size();i++)
    {
        string& d = dat[i];

        if( d == "[" )
        {
            st.push_back(0);
            continue;
        }

        if( d == "]" )
        {
            int64   current = st.back()+SIZE_OF_ASON_FORMAT;

            st.pop_back();
            st.back() += current;
            continue;
        }

        if( is_number(d) )
        {
            st.back() += SIZE_OF_NUMBER_DATA(d);
        }
        else
        {
            st.back() += SIZE_OF_STRING_DATA(d);
        }
    }

    return  st.back();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_size_of_data()<<'\n';

    return  0;
}