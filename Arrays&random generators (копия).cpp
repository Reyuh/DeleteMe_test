#include <iostream>
#include <random>
#include <array>

using namespace std;

const size_t ROWS = 5 ;
const size_t ELEMS = 12 ;

double rand_generation(){
double rand_seed;
static mt19937_64 generator (time(nullptr));
rand_seed = double( generator() )/ generator.max();
return (rand_seed);
}

void matrix_cout (const array<array<double,ROWS>,ELEMS>& matrix){
for (auto& row : matrix ){
for (auto elem : row ){
cout « elem « " " ;
}
cout « "\n" ;
}
}

void matrix_fill_from_a_to_b(array<array<double,ROWS>,ELEMS>& matrix, double a, double b){
for (auto& row : matrix ){
for (auto& elem : row){
elem = rand_generation() * ( b-a ) +a;
}
}
}

int main()
{
array<array<double,ROWS>,ELEMS> matrix;
double a , b;

cout « "enter a" ;
cin » a ;
cout « "enter b" ;
cin » b ;
matrix_fill_from_a_to_b ( matrix, a,b);
matrix_cout ( matrix);
}>
