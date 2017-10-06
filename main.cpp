#include <iostream>
#include <string>

using namespace std;


int main() {
string a;
char b1,b2;
getline (cin, a);

for (int i=0; i<a.length(); i++)
{
	char buf = char(a[i]);
	if(buf != ' ')
	{
		b1=buf;
		break;
	}
}

for (int j=a.length()-1; j>0 ; j--)
{
	char buf = char(a[j]);
	if(buf != ' ')
	{
		b2=buf;
		break;
	}
}

cout << "\n" << b1 << "\n" << b2;
if (b1=b2){
	cout << "first and last elem are equal";
}
}
