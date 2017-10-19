#include <iostream>

using namespace std;

int main()
{
char field[8][8];
for (auto & row : field)
{
    for (auto& elem : row)
    {
        elem = '0';
    }
}

int n,m;
cout << "enter n" ;
cin >> n ;
cout << "enter m" ;
cin >> m ;
n--;
m--;

field[n][m] = 'F';

for (int i = 0 ; i < 8 ; i ++ )
{
    for ( int j = 0 ; j < 8 ; j ++)
    {
       if ((i == n) and (j != m))
       {
           field [i][j] = '*' ;
       }
       if ((j == m) and (i != n))
       {
           field [i][j] = '*' ;
       }

    }
}

for (int k = -7 ; k < 8 ; k++)
{
    if (k!=0)
    {
        int i = n + k ;
        int j = m + k ;
        if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = '*';
        }
        i = n - k ;
        j = m + k ;
        if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = '*';
        }
    }
}


int i = n + 2;
int j = m + 1;
  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }
j = m - 1;
  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }
i = n - 2;
  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }
j = m + 1;  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }
j = m + 2;
i = n + 1;
  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }
i = n - 1;
  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }
j = m - 2;
  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }
i = n + 1;
  if ( ( i < 8 ) and (i > - 1) and (j > -1) and (j < 8 ) )
        {
            field [i][j] = 'H';
        }



for (auto & row : field)
{
    for (auto elem : row)
    {
      cout << elem << " " ;
    }
    cout << "\n";
}

}
