#include <iostream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

void test_for_double (string a){
set<char> LocalSet;
bool test=true;
    for (int i = 0; i < a.length(); i++){
        char buf = char (a[i]);
        int letter_count;
        if (buf != ' '){
            for (int j = a.length() - 1; j > 0; j--){
                char buf2 = char(a[j]);
                if (buf == buf2){
                    letter_count++;
                    if (letter_count > 2){
                        cout << "any letter meeting more that 2 times" << "\n";
                        test = false;
                        break;
                        break;
                    }
                }
            }
        LocalSet.insert(buf);
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
