#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>
#include    <set>

using namespace std;

#define FILE    0
#define FOLDER  1

typedef struct{set<string> folder,file;} Folder;
typedef pair<string,string> Move;

map<string,Folder>  file_system;
vector<string>      queries;

#define CREATE_FOLDER(f)    \
    {if(file_system.find((f))==file_system.end()) file_system[(f)]=Folder();}

void    input(void)
{
    int N,M,Q;

    cin>>N>>M;

    for(int i=1;i<=N+M;i++)
    {
        string  P,F;
        int     C;

        cin>>P>>F>>C;
        CREATE_FOLDER(P);CREATE_FOLDER(F);

        (C==FOLDER)?
            file_system[P].folder.insert(F)
            :file_system[P].file.insert(F);
    }

    cin>>Q;

    for(int i=1;i<=Q;i++)
    {
        string  q;

        cin>>q;
        queries.push_back(q);
    }
}

string  get_folder_info(string& name)
{
    string  ret;

    for(int i=0;i<name.length();i++)
    {
        char&   c = name[i];

        if( c == '/' )
        {
            ret.clear();
        }
        else
        {
            ret.push_back(c);
        }
    }

    return  ret;
}

int     get_num_of_files(set<string>& all_files,string name)
{
    int ret = file_system[name].file.size();
    set<string>::iterator it;
    
    for(it=file_system[name].file.begin();it!=file_system[name].file.end();it++) 
    {
        all_files.insert(*it);
    }

    for(it=file_system[name].folder.begin();it!=file_system[name].folder.end();it++)
    {
        ret += get_num_of_files(all_files,*it);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=0;i<queries.size();i++)
    {
        set<string> all_files;
        int num_of_files = get_num_of_files(
                    all_files,get_folder_info(queries[i]));
        cout<<all_files.size()<<' '<<num_of_files<<'\n';
    }

    return  0;
}