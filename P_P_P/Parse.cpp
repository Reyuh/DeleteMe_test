#include "included_structure.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

enum class errors {error_entering_function = 0, error_entering_action = 1};
using namespace std;
Params parse(std::string exemp)
{
    Params obj;

    //string action, body_funct;
   // vector<string> variables;
   // map<string, std::vector<double>> mymap;

    std::smatch m;
    std::smatch extras;
    string reter;

        if (std::regex_search(exemp, m, std::regex("^(\\w+)[^\\s]") )) {
            obj.action = m[0];
        } else {
        throw errors::error_entering_action;
        }


    if (std::regex_search(exemp, m, std::regex("f:(.+)=>"))  ) {
        string vars = m[1];
        size_t i = 0;
        bool is_word = false;
        string res = "";
        size_t vars_length = vars.size();
        while (i != vars_length)
        {
        char buff = vars[i];
        if ((buff != ',') and (buff != ' '))
        {
        res += buff;
        is_word = true;
        }
        if (((buff =' ') or (buff = ',')) and is_word)
        {
        obj.names.push_back(res);
        is_word = false;
        res = "";
        }

        i++;
        }
//        obj.variables.push_back(vars.substr(start_pos));


    }

    if (std::regex_search(exemp, m, std::regex("=>([^;]+)")) ) {
        obj.body_funct = m[1];
    } else {
      throw errors::error_entering_function;
    }

    if (std::regex_search(exemp, m, std::regex("-(\\S[^\\(]+)[\\(]([^\\)]+)\\)")) ) {
        string elem = m[2];
        bool is_word = false;
        size_t elem_length = elem.size();
        size_t i = 0;
        string res = "";
        while (i != elem_length)
        {
        char buff = elem[i];
        if ((buff != ',') and (buff != ' '))
        {
        res += buff;
        is_word = true;
        }
        if (((buff =' ') or (buff = ',')) and is_word)
        {
        obj.values.push_back(res);
        is_word = false;
        res = "";
        }

        i++;
        }
//        obj.mymap[m[1]] = key;



    }
    return obj;
}


