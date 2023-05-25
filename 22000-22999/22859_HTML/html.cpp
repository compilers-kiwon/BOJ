#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

typedef pair<int,int>   Pos;

const static string tag_str[] = {
    "<div title=\"","</div>","<p>","</p>"
};

#define DIV_HEAD        0
#define DIV_TAIL        1
#define PARAGRAPH_HEAD  2
#define PARAGRAPH_TAIL  3

#define is_opened(t)    ((t)!=0)

int get_title(int pos,const string& html)
{
    string  title;

    for(pos+=tag_str[DIV_HEAD].length();html[pos]!='\"';pos++)
    {
        title.push_back(html[pos]);
    }

    cout<<"title : "<<title<<'\n';

    return  pos+1;
}

string  get_paragraph(int start,int end,const string& html)
{
    string  ret;
    int     tag = 0;

    for(int i=start+tag_str[PARAGRAPH_HEAD].length();i<end;i++)
    {
        char c = html[i];

        switch(c)
        {
            case '<':tag++;break;
            case '>':tag--;break;
            default:
                if(is_opened(tag)) break;
                if(c==' '&&(ret.empty()||ret.back()==' ')) break;
                ret.push_back(c);
                break;
        }
    }

    if(ret.back()==' ') ret.pop_back();
    return  ret;
}

int parse_division(int start,int end,const string& html)
{
    int cur = get_title(start,html);
    vector<Pos> paragraphs;

    for(size_t pos=cur;
        (pos=html.find(tag_str[PARAGRAPH_HEAD],pos))!=string::npos;
        pos+=tag_str[PARAGRAPH_TAIL].length())
    {
        if(pos>=end) break;

        Pos p;

        p.first = pos;
        p.second = (pos=html.find(tag_str[PARAGRAPH_TAIL],pos));

        cout<<get_paragraph(p.first,p.second,html)<<'\n';
    }

    return  0;
}

int parse_main(const string& html)
{
    vector<Pos> divisions;

    for(size_t cur=0;
        (cur=html.find(tag_str[DIV_HEAD],cur))!=string::npos;
        cur+=tag_str[DIV_TAIL].length())
    {
        Pos p;

        p.first = cur;
        p.second = (cur=html.find(tag_str[DIV_TAIL],cur));
        
        divisions.push_back(p);
    }

    for(int i=0;i<divisions.size();i++)
    {
        parse_division(divisions[i].first,divisions[i].second,html);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string  html;

    getline(cin,html);
    parse_main(html);

    return  0;
}