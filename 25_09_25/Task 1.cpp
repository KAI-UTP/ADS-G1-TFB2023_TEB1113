#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int readInt(const string& prompt, int minVal = numeric_limits<int>::min(), int maxVal = numeric_limits<int>::max()) {
    int value;
    while (true) {
        cout << prompt;
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number. Try again.\n";
            continue;
        }
        if (value < minVal || value > maxVal) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Out of range. Try again.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

string readLineNonEmpty(const string& prompt) {
    string s;
    while (true) {
        cout << prompt;
        if (!getline(cin, s)) {
            cin.clear();
            continue;
        }
        if (!s.empty()) return s;
        cout << "Input cannot be empty. Try again.\n";
    }
}

struct Student {
    int id;
    string name;
    string email;
};

int main() {
    int opt = 1;
    while (opt != 2) {
        int num = readInt("Enter number of students: ", 1);
        vector<Student> students(num);

        for (int i = 0; i < num; i++) {
            cout << "\nStudent " << i + 1 << " Details:\n";
            students[i].name  = readLineNonEmpty("Enter name: ");
            students[i].id    = readInt("Enter id: ");
            students[i].email = readLineNonEmpty("Enter email: ");
        }

        for (int i = 0; i < num; i++) {
            cout << "\nStudent " << i + 1 << " Details:\n";
            cout << "Name : " << students[i].name  << "\n";
            cout << "ID   : " << students[i].id    << "\n";
            cout << "Email: " << students[i].email << "\n";
        }

        opt = readInt("\nContinue? (1 for YES, 2 for NO): ", 1, 2);
        cout << "\n";
    }
    return 0;
}
