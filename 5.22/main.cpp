#include <iostream>
#include <string>
#include <set>

using namespace std;

void new_string (string a , string b){
set<char> local_set;
    for (int i = 0; i < a.length(); i++){
        char buf = char (a[i]);
        if (buf != ' '){
            local_set.insert(buf);
        }
    }
    for (int i = 0; i < b.length(); i++){
        char buf = char (b[i]);
        if (local_set.count(buf) == 0){
            cout << buf;
        }
    }

}

int main() {
string a;
string b;
getline (cin, a);
getline (cin, b);
new_string(a,b);
}
