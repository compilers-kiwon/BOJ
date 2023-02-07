#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)

#define TRUE    1
#define FALSE   0

#define is_empty(c) ((c)==' ')

int analysis_sentence(queue<string>& words,
                        const string& sentence)
{
    string  s;

    for(int i=0;i<sentence.length();i++)
    {
        if( is_empty(sentence[i]) )
        {
            words.push(s);s.clear();
        }
        else
        {
            s.push_back(sentence[i]);
        }
    }

    return  words.size();
}

int simulate(int num_of_parrots,
                queue<string>& dictation,
                queue<string> sentences[])
{
    int ret = TRUE;

    for(;!dictation.empty();dictation.pop())
    {
        bool    found = false;

        for(int i=1;i<=num_of_parrots;i++)
        {
            if( sentences[i].empty()==false && 
                    dictation.front()==sentences[i].front() )
            {
                found = true;
                sentences[i].pop();

                break;
            }
        }

        if( found == false )
        {
            ret = FALSE;
            break;
        }
    }

    return  ret;
}

int input(int& num_of_parrots,
            queue<string>& dictation,
            queue<string> sentences[])
{
    int     num_of_words_1,num_of_words_2;
    string  str;

    cin>>num_of_parrots;getchar();
    num_of_words_1 = num_of_words_2 = 0;

    for(int i=1;i<=num_of_parrots;i++)
    {
        getline(cin,str);
        str.push_back(' ');
        num_of_words_1 +=
            analysis_sentence(sentences[i],str);
    }

    getline(cin,str);
    str.push_back(' ');

    num_of_words_2 = analysis_sentence(dictation,str);

    return  (num_of_words_1==num_of_words_2)?TRUE:FALSE;
}

int main(void)
{
    int             N;
    queue<string>   dictation,parrot[MAX_SIZE];

    if( input(N,dictation,parrot) == FALSE )
    {
        cout<<"Impossible\n";
        return  0;
    }

    cout<<(simulate(N,dictation,parrot)?
                "Possible":"Impossible")<<'\n';

    return  0; 
}