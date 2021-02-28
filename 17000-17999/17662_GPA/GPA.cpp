#include    <iostream>
#include    <string>
#include    <map>
#include    <vector>

using namespace std;

int C,M,s;

typedef map<string,double>  Score;
typedef vector<string>      Class;

void    read_class_info(map<string,double>& class_info)
{
    for(int i=1;i<=C;i++)
    {
        string  c;
        int     u;

        cin>>c>>u;
        class_info[c] = u;
    }
}

void    read_major_class(map<string,Class>& major,
                         vector<string>& major_order)
{
    for(int i=1;i<=M;i++)
    {
        string  m;
        int     n;

        cin>>m>>n;
        major_order.push_back(m);

        for(int j=1;j<=n;j++)
        {
            string  c;

            cin>>c;
            major[m].push_back(c);
        }
    }
}

void    read_student(vector<Score>& student)
{
    for(int i=1;i<=s;i++)
    {
        int     t;
        Score   result;

        cin>>t;

        for(int j=1;j<=t;j++)
        {
            string  c;
            double  g;

            cin>>c>>g;
            result[c] = g;
        }

        student.push_back(result);
    }
}

bool    take_all_required_classes(Score& taken,Class& c,
                                  double& unit,double& score,
                                  map<string,double>& class_info)
{
    for(int i=0;i<c.size();i++)
    {
        if( taken.find(c[i]) == taken.end() )
        {
            return  false;
        }

        unit += class_info[c[i]];
        score += taken[c[i]]*class_info[c[i]];
    }

    return  true;
}

void    get_gpa(double& total_gpa,
                map<string,double>& major_gpa,
                map<string,double>& class_info,
                map<string,Class>& major,
                Score& taken)
{
    double              num_of_units_to_be_taken = 0.0;
    double              weighted_score = 0.0;
    map<string,double>  major_nuit_to_be_taken;
    map<string,double>  major_weighted_score;

    for(map<string,double>::iterator it=taken.begin();
        it!=taken.end();it++)
    {
        const string&   class_name = it->first;
        const double&   received_score = it->second;

        num_of_units_to_be_taken += class_info[class_name];
        weighted_score += class_info[class_name]*received_score;
    }

    total_gpa = weighted_score/num_of_units_to_be_taken;

    for(map<string,Class>::iterator it=major.begin();it!=major.end();it++)
    {
        double  major_unit,major_weighted_score;

        major_unit = major_weighted_score = 0.0;

        if( take_all_required_classes(taken,it->second,major_unit,major_weighted_score,class_info) == false )
        {
            continue;
        }
        
        major_gpa[it->first] = major_weighted_score/major_unit;  
    }
}

void    calculate_and_print_GPA(map<string,double>& class_info,
                                map<string,Class>& major,
                                vector<Score>& student,
                                vector<string>& major_class)
{
    for(int i=1;i<=s;i++)
    {
        double              gpa;
        map<string,double>  major_gpa;

        get_gpa(gpa,major_gpa,class_info,major,student[i-1]);

        cout<<"Student "<<i<<'\n';
        printf("GPA: %.2f\n",gpa);

        for(int j=0;j<major_class.size();j++)
        {
            if( major_gpa.find(major_class[j]) == major_gpa.end() )
            {
                continue;
            }

            printf("%s: %.2f\n",major_class[j].c_str(),major_gpa[major_class[j]]);
        }
    }
}

int     main(void)
{
    int K;

    cin>>K;

    for(int i=1;i<=K;i++)
    {
        map<string,double>  class_unit;
        map<string,Class>   major_name;
        vector<string>      major_list;
        vector<Score>       result;

        cin>>C>>M>>s;

        read_class_info(class_unit);
        read_major_class(major_name,major_list);
        read_student(result);

        cout<<"Data Set "<<i<<":\n";
        calculate_and_print_GPA(class_unit,major_name,result,major_list);
        cout<<'\n';
    }

    return  0;
}