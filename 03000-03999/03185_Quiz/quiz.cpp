#include    <iostream>
#include    <string>

using namespace std;

const string    vowel = "aeiouAEIOU";

#define IN_RANGE(MIN,n,MAX)             ((MIN)<=(n)&&(n)<=(MAX))
#define is_letter(c)                    (IN_RANGE('a',(c),'z')||IN_RANGE('A',(c),'Z'))
#define get_length_of_revealation(l,f)  (((l)*10*(f)/3+5)/10)

#define EMPTY   '.'

bool    is_vowel(const char& c)
{
    for(int i=0;i<vowel.length();i++)
    {
        if( vowel[i] == c )
        {
            return  true;
        }
    }

    return  false;
}

int     count_num_of_letters(const string& str)
{
    int ret = 0;

    for(int i=0;i<str.length();i++)
    {
        if( is_letter(str[i]) == true )
        {
            ret++;
        }
    }

    return  ret;
}

void    generate_first_hint(const string& answer,string& hint)
{
    for(int i=0;i<answer.length();i++)
    {
        char    c = answer[i];

        if( is_letter(c) == true )
        {
            hint.push_back(EMPTY);
        }
        else
        {
            hint.push_back(c);
        }
    }
}

void    generate_second_hint(const string& answer,string& hint,int num_of_letters)
{
    int cnt = get_length_of_revealation(num_of_letters,1);
   
    for(int i=0;i<answer.length()&&cnt!=0;i++)
    {
        char    c = answer[i];

        if( is_letter(c) == false )
        {
            continue;
        }

        hint[i] = c;
        cnt--;
    }
}

void    generate_third_hint(const string& answer,string& hint,int num_of_letters)
{
    bool    generated = false;

    for(int i=0;i<answer.length();i++)
    {
        char    c = answer[i];

        if( is_letter(c)==false || is_vowel(c)==false )
        {
            continue;
        }

        if( hint[i] == EMPTY )
        {
            hint[i] = c;
            generated = true;
        }
    }

    if( generated == true )
    {
        return;
    }

    int cnt = get_length_of_revealation(num_of_letters,2);

    for(int i=0;i<answer.length()&&cnt!=0;i++)
    {
        char    c = answer[i];

        if( is_letter(c) == false )
        {
            continue;
        }

        hint[i] = c;
        cnt--;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     num_of_letters;
    string  answer,hint;

    getline(cin,answer);
    num_of_letters = count_num_of_letters(answer);

    generate_first_hint(answer,hint);
    cout<<hint<<'\n';

    generate_second_hint(answer,hint,num_of_letters);
    cout<<hint<<'\n';

    generate_third_hint(answer,hint,num_of_letters);
    cout<<hint<<'\n';

    return  0;
}