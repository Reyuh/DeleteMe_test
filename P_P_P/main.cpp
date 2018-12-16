#include "parse.h"
#include "cpp_creator.h"
#include <iostream>
using namespace std;

int main()
{
    string exemp = "calc f: x, y,z =>x*x -   5*y + z; -args(5 ,4 , 7 );";
    Params test = parse(exemp);
    cpp_creator(parse(exemp));

 /*   cout << test.action << endl;
    cout << test.body_funct << endl;
    for (size_t i = 0 ; i < test.names.size() ; i ++)
    {
    cout << test.names[i] << " = "<< test.values[i]  << endl;
    }
    for (size_t i = 0 ; i < test.values.size() ; i ++)
    {
    cout << test.values[i] << endl;
    }*/
 //   cout << test.variables[1].name << " KEK " << endl;
//   if (tester(test))
//   cout << " ALL GOOD";
}
