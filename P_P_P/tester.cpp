#ifndef tester_H
#define tester_H
#include "included_structure.h"
#include"tester.h"
#include <set>

bool tester (Params getted)
{
if (getted.names.size() != getted.values.size())
return false;

int i = 0;
bool is_word = false;
std::set<std::string> set_of_names;
        std::string res = "";
        size_t getted_length = getted.body_funct.size();
        while (i != getted_length)
        {
        char buff = getted.body_funct[i];
        bool test = std::isdigit(buff);
        if ((buff != ',') and (buff != ' ')and (buff != '+')and (buff != '-')and (buff != '/')and (buff != '*') and !test  )
        {
        res += buff;
        is_word = true;
        }
        if (((buff =' ') or (buff = ',')or (buff = '+')or (buff = '-')or (buff = '/')or (buff = '*') or test) and is_word)
        {
        set_of_names.insert(res);
        is_word = false;
        res = "";
        }

        i++;
        }

if (set_of_names.size() != getted.values.size())
return false;
else
return true;
};
#endif

