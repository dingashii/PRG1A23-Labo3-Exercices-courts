#include <iostream>
#include <string>

using namespace std;

char& plus_petite_lettre(string& s) {
    char* plus_petit = nullptr;  // Initialise avec nullptr

    for (char& c : s) {
        if (islower(c)) {
            if (plus_petit == nullptr || c <= *plus_petit) {
                plus_petit = &c;
            }
        }
    }
    return *plus_petit;
}

int main() {
    string s{"wisigoth"};
    plus_petite_lettre(s) = '*';
    cout << s << endl;
    // affiche wisi*oth

    s = "abraracourcix";
    plus_petite_lettre(s) = '*';
    cout << s << endl;
    // affiche abrar*courcix

    return 0;
}
