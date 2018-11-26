//#include "parse.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

enum class errors {error_entering_function = 0, error_entering_action = 1};

/*class Enter_func_exeption: public exception
{
  virtual const char* what() const noexcept
  {
    return "something went wrong with enter string at function part";
  }
};*/



struct Params
{
    string action, body_funct;
    vector<string> variables;
    map<string, std::vector<double>> mymap;
};

Params parse(string exemp)
{
    Params obj;

    //string action, body_funct;
   // vector<string> variables;
   // map<string, std::vector<double>> mymap;

    std::smatch m;

        if (std::regex_search(exemp, m, std::regex("^(\\w+)[^\\s]") )) {
            obj.action = m[0];
        } else {
        throw errors::error_entering_action;
        }


    if (std::regex_search(exemp, m, std::regex("f:(.+)=>"))  ) {
        string vars = m[1];
        size_t start_pos = 0;
        size_t pos;

        while ((pos = vars.find(",", start_pos)) != string::npos) {
            obj.variables.push_back(vars.substr(start_pos, pos - start_pos));
            start_pos = pos + 1;

        }
        obj.variables.push_back(vars.substr(start_pos));


    }

    if (std::regex_search(exemp, m, std::regex("=>([^;]+)")) ) {
        obj.body_funct = m[1];
    } else {
      throw errors::error_entering_function;
    }

    if (std::regex_search(exemp, m, std::regex("-(\\S[^\\(]+)[\\(]([^\\)]+)\\)")) ) {

        string elem = m[2];
        size_t start_key = 0;
        size_t pos_key;
        vector<double> key;

        while ((pos_key = elem.find(",", start_key)) != string::npos) {
            ///key.push_back(elem.substr(start_key, pos_key - start_key));
            key.push_back(stod(elem.substr(start_key, pos_key - start_key)));
            start_key = pos_key + 1;

        }
        key.push_back(stod(elem.substr(start_key)));

        obj.mymap[m[1]] = key;



    }
    return obj;
}


int main()
{
    string exemp = "calc f:x, y =>x*x - 5*y + z; -args(5 ,4 );";



    Params test = parse(exemp);

    cout << test.action ;
}
