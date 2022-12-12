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
vector<Move>        operations;
vector<string>      queries;

#define CREATE_FOLDER(f)    \
    {if(file_system.find((f))==file_system.end()) file_system[(f)]=Folder();}

void    input(void)
{
    int N,M,K,Q;

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

    cin>>K;

    for(int i=1;i<=K;i++)
    {
        Move    m;

        cin>>m.first>>m.second;
        operations.push_back(m);
    }

    cin>>Q;

    for(int i=1;i<=Q;i++)
    {
        string  q;

        cin>>q;
        queries.push_back(q);
    }
}

map<string,Folder>::iterator
        get_folder_info(string& name,bool move_operation)
{
    if( name == "main" )
    {
        return  file_system.find(name);
    }

    vector<string>  p;
    string          tmp;

    name.push_back('/');

    for(int i=0;i<name.length();i++)
    {
        char&   c = name[i];

        if( c == '/' )
        {
            p.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp.push_back(c);
        }
    }

    if( move_operation == true )
    {
        file_system[p[p.size()-2]].folder.erase(p.back());
    }

    return  file_system.find(p.back());
}

void    merge(set<string>& dst,set<string>& src)
{
    for(set<string>::iterator it=src.begin();it!=src.end();it++)
    {
        dst.insert(*it);
    }
}

void    copy_subs(map<string,Folder>::iterator dst,
                        map<string,Folder>::iterator src)
{
    merge(dst->second.folder,src->second.folder);
    merge(dst->second.file,src->second.file);
}

void    move_operation(string& src,string& dst)
{
    map<string,Folder>::iterator    src_folder,dst_folder;

    src_folder = get_folder_info(src,true);
    dst_folder = get_folder_info(dst,false);

    copy_subs(dst_folder,src_folder);
    file_system.erase(src_folder);
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

    for(int i=0;i<operations.size();i++)
    {
        move_operation(operations[i].first,operations[i].second);
    }

    for(int i=0;i<queries.size();i++)
    {
        set<string> all_files;
        int num_of_files = get_num_of_files(all_files,
                                get_folder_info(queries[i],false)->first);
        
        cout<<all_files.size()<<' '<<num_of_files<<'\n';
    }

    return  0;
}