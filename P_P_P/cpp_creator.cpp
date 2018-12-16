#include <iostream>
#include <fstream>
#include "cpp_creator.h"
#include"tester.h"
int cpp_creator(Params getted)
{
    if (tester(getted))
    {
    std::ofstream out;          // поток для записи
    out.open("/home/reyuh/P_P_P/123/main.cpp"); // окрываем файл для записи


    if (out.is_open())
    {
        out << "#include <iostream>" << std::endl;
        out << "using namespace std;" << std::endl;
        out << "int main()" << std::endl;
        out << "{" << std::endl;

        for (int i = 0 ; i < getted.names.size() ; i++)
        {
        out << " double " << getted.names[i] << " = " << getted.values[i] << " ; " << std::endl;
        }
       // out << getted.names[getted.names.size()] << " = " << getted.values[getted.names.size()] << " ; "<< std::endl;
        out << "cout <<" << getted.body_funct << "<< std:: endl;" << std:: endl;
        out << "}" << std::endl;
    }

    }
    else
    std::cout << " you have entered incorrect string" << std::endl;
}
