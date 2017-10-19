#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
	FILE *file;
	char *fname = "main.cpp";
	char result_string[100];

	file = fopen(fname,"r");

	if(file == NULL)
	{
		printf("cant open a file '%s'",fname);
		return 0;
	}


	while ( fgets ( result_string , sizeof (result_string) , file ) )
	{   bool test = true;
	    for  ( int i = 0 ; i < 60 ; i ++ )
        {
            if ( result_string[i] == '\n' )
            {
                test = false;
            }
        }
        if (test)
        {
            cout << result_string ;
	    }
	}

}
