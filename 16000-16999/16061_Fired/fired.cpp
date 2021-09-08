#include    <iostream>
#include    <string>
#include    <queue>

using namespace std;

typedef pair<int,string>    Employee;   // first:-index,second:name
typedef pair<int,Employee>  Salary;     // first:money,second:Employee

int                         n,d,k;
priority_queue<Salary>      salary_q;
priority_queue<Employee>    fired_q;

void    input(void)
{
    cin>>n>>d>>k;

    for(int i=1;i<=n;i++)
    {
        string  name;
        int     salary;

        cin>>name>>salary;
        salary_q.push(make_pair(salary,make_pair(-i,name)));
    }
}

bool    fire_employee(void)
{
    int saved_money = 0;

    for(int i=1;i<=k;i++)
    {
        int         employee_salary = salary_q.top().first;
        Employee    employee_info = salary_q.top().second;

        salary_q.pop();
        
        saved_money += employee_salary;
        fired_q.push(employee_info);

        if( saved_money >= d )
        {
            return  true;
        }
    }

    return  false;
}

void    print_fired_employee(void)
{
    cout<<fired_q.size()<<'\n';

    for(;!fired_q.empty();fired_q.pop())
    {
        cout<<fired_q.top().second<<", YOU ARE FIRED!\n";
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    if( fire_employee() == false )
    {
        cout<<"impossible\n";
    }
    else
    {
        print_fired_employee();
    }

    return  0;
}