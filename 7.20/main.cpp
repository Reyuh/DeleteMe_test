#include <iostream>
#include <random>
#include <iomanip>

using namespace std;


double rand_generation(){
double rand_seed;
static mt19937_64 generator (time(nullptr));
rand_seed = double( generator() )/ generator.max();
return (rand_seed);
}

int main()
{
    int size_y, size_x ;
    cout << " enter number of rows " ;
    cin >> size_y ;
    cout << " enter number of elements in each row " ;
    cin >> size_x ;
    int **ary = new int*[size_y];
    for( int i = 0 ; i < size_y ; i ++ ) {
        ary[i] = new int[size_x + 1];
    }

    for ( int i = 0 ; i < size_y ; i ++  )
    {
        for ( int j = 0 ; j < size_x ; j ++ )
        {
            ary [i][j] =  int (100* rand_generation()) ;
            cout << setw(4) << ary [i][j] ;
            ary [i][size_x +1] += ary [i][j] ;
        }
        cout << setw(12) << ary [i][size_x + 1] ;
        cout << "\n" ;
    }
    for ( int k = 0 ; k < size_y - 1 ; k ++ )
    {
        int array_max_sum_number = ary [k][size_x + 1] ;
        int ** array_buf = new int*[1] ;

        for ( int i = k + 1 ; i < size_y ; i ++ )
        {
            if (ary[i][size_x + 1] > array_max_sum_number)
            {
                array_max_sum_number = ary[i][size_x + 1] ;
                array_buf[1] = ary[k] ;
                ary[k] = ary[i] ;
                cout << "Chlen" << "\n" ;
                ary[i] = array_buf[1] ;
            }
        }
        delete array_buf ;
    }


    for ( int i = 0 ; i < size_y ; i ++  )
    {
        for ( int j = 0 ; j < size_x ; j ++ )
        {
            cout << setw(4) << ary [i][j] ;
        }
        cout << setw(12) << ary [i][size_x + 1] ;
        cout << "\n" ;
    }

    for ( int i = 0 ; i < size_y ; i ++ )
    {
        delete ary[i] ;
    }
    delete []ary ;

}
