#include    <iostream>
#include    <vector>
#include    <string>
#include    <map>
#include    <set>

using namespace std;

#define MAX_PERMISSIONS 8

const static string permissions[MAX_PERMISSIONS] = {
    "","X","RW","RXW","R","RX","RW","RXW"
};

typedef struct {
    int     permission;
    string  owner,group;
} File;

static map<string,File>         file_info;
static map<string,set<string>>  my_groups;

#define get_owner_permission(attr)  (permissions[(attr)/100])
#define get_group_permission(attr)  (permissions[((attr)/10)%10])
#define get_other_permission(attr)  (permissions[(attr)%10])

#define SUCCESS 1
#define FAIL    0

#define is_group_owner(my_groups,file_owned_group) \
    ((my_groups).find((file_owned_group))!=(my_groups).end())

int parse(string& str,vector<string>& ret)
{
    string  cur;

    str.push_back(' ');

    for (int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if (c==' ' || c==',') {
            ret.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }

    return  0;
}

int read_information(void)
{
    int     U,F;
    string  buf;
    
    getline(cin,buf);
    sscanf(buf.c_str(),"%d %d",&U,&F);

    for (int i=1;i<=U;i++) {
        vector<string>  s;

        getline(cin,buf);
        parse(buf,s);

        for (;!s.empty();s.pop_back()) {
            my_groups[s.front()].insert(s.back());
        }
    }

    for (int i=1;i<=F;i++) {
        vector<string>  s;

        getline(cin,buf);
        parse(buf,s);

        string& file_name = s[0];
        int     file_permission = stoi(s[1]);
        string& owner_name = s[2];
        string& group_name = s[3];

        file_info[file_name] = {file_permission,owner_name,group_name};
    }

    return  0;
}

int do_query(const vector<string>& args)
{
    const string&   user = args[0];
    const string&   file = args[1];
    const string&   op = args[2];

    map<string,File>::iterator  fp = file_info.find(file);

    // 1. user
    if (fp->second.owner == user) {
        if (get_owner_permission(fp->second.permission).find(op[0]) == string::npos) {
            return  FAIL;
        }

        return  SUCCESS;
    }

    // 2. group
    set<string>& groups = my_groups[user];

    if (is_group_owner(groups,fp->second.group)) {
        if (get_group_permission(fp->second.permission).find(op[0]) == string::npos) {
            return  FAIL;
        }

        return  SUCCESS;
    }

    // 3. other
    if (get_other_permission(fp->second.permission).find(op[0]) == string::npos) {
        return  FAIL;
    }

    return  SUCCESS;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    read_information();

    int     Q;
    string  buf;

    getline(cin,buf);
    sscanf(buf.c_str(),"%d",&Q);

    for (int i=1;i<=Q;i++) {
        vector<string>  s;

        getline(cin,buf);
        parse(buf,s);
        cout<<do_query(s)<<'\n';
    }

    return  0;
}