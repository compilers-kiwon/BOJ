#include    <iostream>
#include    <vector>
#include    <map>
#include    <string>
#include    <algorithm>

using namespace std;

#define IMMEDIATE   0
#define DIRECT      1
#define INDIRECT    2

typedef unsigned int    uint32;
typedef struct{uint32 addr_mode,value;} Operand;

#define MOVE    0
#define INPUT   1
#define OUTPUT  2
#define ADD     3
#define MULT    4
#define AND     5
#define OR      6
#define XOR     7
#define BUG     8

#define OPERATION_IDX   0
#define MAX_OPERANDS    3

#define DEST    0
#define SOURCE  1
#define ADDRESS 0
#define ARG1    1
#define ARG2    2

#define MAX_NUM_OF_LOGS     (100+1)
#define NUM_OF_BUG_OPCODE   5

typedef struct{string str;uint32 operation;Operand op[MAX_OPERANDS];}    Instruction;

#define get_addr_mode(c)    (((c)=='#')?IMMEDIATE:((c)=='$')?DIRECT:INDIRECT)
#define char2uint32(c)      ((uint32)((c)-'0'))
#define get_index(c)        ((int)((c)-'A'))

const string    bug_opcode[NUM_OF_BUG_OPCODE] = {"ADD","MULT","AND","OR","XOR"};

void    parse(vector<string>& ret,string& str)
{
    string  tmp;

    for(int i=0;i<str.length();i++)
    {
        char&   c = str[i];

        if( c == ' ' )
        {
            ret.push_back(tmp);
            tmp.clear();
        }
        else
        {
            tmp.push_back(c);
        }
    }
}

void    read_operation(const string& str,Instruction& in)
{
    if( str == "MOVE" )
    {
        in.operation = MOVE;
    }
    else if( str == "INPUT" )
    {
        in.operation = INPUT;
    }
    else if( str == "OUTPUT" )
    {
        in.operation = OUTPUT;
    }
    else if( str == "ADD" )
    {
        in.operation = ADD;
    }
    else if( str == "MULT" )
    {
        in.operation = MULT;
    }
    else if( str == "AND" )
    {
        in.operation = AND;
    }
    else if( str == "OR" )
    {
        in.operation = OR;
    }
    else if( str == "XOR" )
    {
        in.operation = XOR;
    }
    else
    {
        in.operation = BUG;
    }
}

void    read_operand(Operand& o,string& str)
{
    o.addr_mode = get_addr_mode(str[0]);
    o.value = 0;

    for(int i=1;i<str.length();i++)
    {
        o.value = o.value*10+char2uint32(str[i]);
    }
}

void    read_instruction(Instruction& in,vector<string>& s)
{
    in.str = s[OPERATION_IDX];
    read_operation(in.str,in);

    for(int i=1;i<s.size();i++)
    {
        read_operand(in.op[i-1],s[i]);
    }
}

void    read_code(vector<Instruction>& code)
{
    for(;;)
    {
        string          input;
        vector<string>  p;
        Instruction     i;

        getline(cin,input);
        input.push_back(' ');

        parse(p,input);
        read_instruction(i,p);

        code.push_back(i);

        if( i.operation == OUTPUT )
        {
            break;
        }
    }
}

uint32  get_mem_addr(Operand& o,map<uint32,uint32>& m)
{
    uint32  ret;

    if( o.addr_mode == DIRECT )
    {
        ret = o.value;
    }
    else    // addr_mode == INDIRECT
    {
        ret = m[o.value];
    }

    return  ret;
}

uint32  get_value(Operand& o,map<uint32,uint32>& m)
{
    uint32  ret;

    switch(o.addr_mode)
    {
        case    IMMEDIATE:
            ret = o.value;
            break;
        case    DIRECT:
            ret = m[o.value];
            break;
        case    INDIRECT:
            ret = m[m[o.value]];
            break;
        default:
            // do nothing
            break;
    }

    return  ret;
}

bool    simulate(vector<Instruction>& code,vector<uint32>& log)
{
    int                 log_ptr = 0;
    map<uint32,uint32>  mem;

    for(int i=0;i<code.size();i++)
    {
        Instruction&    in = code[i];

        switch(in.operation)
        {
            case    MOVE:
                mem[get_mem_addr(in.op[DEST],mem)] = get_value(in.op[SOURCE],mem);
                break;
            case    INPUT:
                mem[get_mem_addr(in.op[ADDRESS],mem)] = log[log_ptr++];
                break;
            case    OUTPUT:
                if( get_value(in.op[ADDRESS],mem) != log[log_ptr++] )
                {
                    return  false;
                }
                break;
            case    ADD:
                mem[get_mem_addr(in.op[DEST],mem)] = get_value(in.op[ARG1],mem)+get_value(in.op[ARG2],mem);
                break;
            case    MULT:
                mem[get_mem_addr(in.op[DEST],mem)] = get_value(in.op[ARG1],mem)*get_value(in.op[ARG2],mem);
                break;
            case    AND:
                mem[get_mem_addr(in.op[DEST],mem)] = get_value(in.op[ARG1],mem)&get_value(in.op[ARG2],mem);
                break;
            case    OR:
                mem[get_mem_addr(in.op[DEST],mem)] = get_value(in.op[ARG1],mem)|get_value(in.op[ARG2],mem);
                break;
            case    XOR:
                mem[get_mem_addr(in.op[DEST],mem)] = get_value(in.op[ARG1],mem)^get_value(in.op[ARG2],mem);
                break;
            default:
                // do nothing
                break;
        }
    }

    return  true;
}

void    read_log(int& num_of_logs,vector<uint32>* log)
{
    cin>>num_of_logs;getchar();

    for(int i=1;i<=num_of_logs;i++)
    {
        uint32  n = 0;
        string  str;

        getline(cin,str);
        str.push_back(' ');

        for(int j=0;j<str.length();j++)
        {
            char&   c = str[j];

            if( c == ' ' )
            {
                log[i].push_back(n);
                n = 0;
            }
            else
            {
                n = n*10+char2uint32(c);
            }
        }
    }
}

int     main(void)
{
    int                 N;
    vector<uint32>      log[MAX_NUM_OF_LOGS];
    vector<Instruction> code;

    read_code(code);
    read_log(N,log);

    int             cnt = 0;
    vector<int>     represent;
    vector<string>  fix;

    for(int i=0;i<NUM_OF_BUG_OPCODE;i++)
    {
        represent.push_back(i);
    }

    do{
        for(int i=0;i<code.size();i++)
        {
            if( code[i].str=="A" || code[i].str=="B" || code[i].str=="C" || code[i].str=="D" || code[i].str=="E" )
            {
                int idx = get_index(code[i].str[0]);

                read_operation(bug_opcode[represent[idx]],code[i]);
            }
        }

        bool    all_passed = true;

        for(int j=1;j<=N;j++)
        {
            if( simulate(code,log[j]) == false )
            {
                all_passed = false;
                break;
            }
        }

        if( all_passed == true )
        {
            cnt++;

            for(int j=0;j<NUM_OF_BUG_OPCODE;j++)
            {
                fix.push_back(bug_opcode[represent[j]]);
            }
        }
    }while(next_permutation(represent.begin(),represent.end()));

    cout<<cnt<<'\n';

    if( cnt == 1 )
    {
        for(int i=0;i<NUM_OF_BUG_OPCODE;i++)
        {
            cout<<fix[i]<<' ';
        }
        cout<<'\n';
    }

    return  0;
}