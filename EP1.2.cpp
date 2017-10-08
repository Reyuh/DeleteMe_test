#include <iostream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

void test_for_double (string a){
set<int> local_set;
bool test=true;
    for (int i = 0; i < a.length(); i++){
        char buf = char (a[i]);
        int letter_count;
        if (buf != ' '){
            if (local_set.count(int(buf)) == 0 ){
                for (int j = a.length() - 1; j > 0; j--){
                char buf2 = char(a[j]);
                if (buf == buf2){
                    letter_count++;
                    if (letter_count == 1){
                        cout<< buf <<"\n" << "letter meeting 2 times or more " << "\n"; // Проверка на то что буква встречается 2 раза или более. Если требуется строго больше 2х раз - то if (letter_count ==1)
                        test = false;
                        break;
                        }
                    }
                }
            }

        local_set.insert(int(buf));
        letter_count = 0;
        }
    }
if (test){
    cout << "not any letter meeting more that 2 times";
}
}

int main() {
string a;
getline (cin, a);
test_for_double(a);
}
