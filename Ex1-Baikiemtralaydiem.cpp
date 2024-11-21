#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string process_name(const string& name) {
    string result;
    bool new_word = true;

    for (int i = 0; i < name.length(); i++) {
        char ch = name[i];
        if (ch == ' ') {
            if (!result.empty() && result[result.length() - 1] != ' ') {
                result += ' ';
            }
            new_word = true;
        } else {
            result += new_word ? toupper(ch) : tolower(ch);
            new_word = false;
        }
    }

    if (!result.empty() && result[result.length() - 1] == ' ') {
        result.erase(result.length() - 1);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string name;
        getline(cin, name);
        cout << process_name(name) << endl;
    }

    return 0;
}


