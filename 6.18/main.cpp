#include <iostream>
#include <string>
#include <set>

using namespace std;

void repeating_of_letters (string a){
set<char> local_set;
    for (int i = 0; i < a.length(); i++){
        char buf = char (a[i]);
        int letter_count = 1;
        if (buf != ' '){
            if (local_set.count(buf) == 0 ){
                for (int j = a.length(); j > i; j--){
                char buf2 = char(a[j]);
                if (( local_set.count( buf2 ) != 1 ) and ( buf == buf2 )){
                    letter_count++;
                    }
                }
                cout << buf << " is used " << letter_count << " time(s) " << "\n" ;
            }

        local_set.insert(buf);
        letter_count = 1;
        }
    }
}

int main() {
string a;
getline (cin, a);
repeating_of_letters(a);
}
