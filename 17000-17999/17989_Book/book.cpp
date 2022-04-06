#include    <iostream>
#include    <string>
#include    <map>
#include    <vector>

using namespace std;

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

typedef long long int       int64;
typedef pair<string,int64>  Present;    // first:title,second:num_of_pages

int                 n,m,k;
map<string,int64>   pile;

map< int64,vector<Present> >  new_book;   //new_book[time] = vector<title,num_of_pages>

void    get_pile_information(string& in,string& title,int64& num_of_pages)
{
    int head,tail;

    head = in.find('\"',0);
    tail = in.find('\"',head+1);

    title = in.substr(head+1,tail-head-1);
    num_of_pages = 0;

    for(int i=tail+2;i<in.length();i++)
    {
        num_of_pages = num_of_pages*10+(int)(in[i]-'0');
    }
}

void    get_new_book_information(string& in,int64& time,string& title,int64& num_of_pages)
{
    time = num_of_pages = 0;

    for(int i=0;in[i]!=' ';i++)
    {
        time = time*10+(int)(in[i]-'0');
    }

    int head,tail;

    head = in.find('\"',0);
    tail = in.find('\"',head+1);

    title = in.substr(head+1,tail-head-1);
    num_of_pages = 0;

    for(int i=tail+2;i<in.length();i++)
    {
        num_of_pages = num_of_pages*10+(int)(in[i]-'0');
    }
}

void    input(void)
{
    cin>>n>>m>>k;
    getchar();

    for(int i=1;i<=n;i++)
    {
        int64   num_of_pages;
        string  str,title;

        getline(cin,str);
        get_pile_information(str,title,num_of_pages);

        pile[title] = num_of_pages;
    }

    for(int i=1;i<=m;i++)
    {
        int64   time,num_of_pages;
        string  str,title;

        getline(cin,str);
        get_new_book_information(str,time,title,num_of_pages);

        new_book[time].push_back(make_pair(title,num_of_pages));
    }
}

int     main(void)
{
    input();
    pile["Jane Eyre"] = (int64)k;

    int64   current_time = 0;
    map< int64,vector<Present> >::iterator    it = new_book.begin();

    for(;;)
    {
        for(;it!=new_book.end();it++)
        {
            if( it->first > current_time )
            {
                break;
            }

            vector<Present>&    books = it->second;

            for(int i=0;i<books.size();i++)
            {
                pile[books[i].first] = books[i].second;
            }
        }

        current_time += pile.begin()->second;

        if( pile.begin()->first == "Jane Eyre" )
        {
            break;
        }

        pile.erase(pile.begin());
    }

    cout<<current_time<<'\n';

    return  0;
}