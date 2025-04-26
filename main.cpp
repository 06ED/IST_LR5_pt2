#include <iostream>

using namespace std;

bool is_correct(const string &value) {
    try {
        if (const int i = stoi(value); value.length() == std::to_string(i).length()) {
            return true;
        }
        return false;
    } catch (...) {
        return false;
    }
}

int enter_value() {
    string value;

    while (true) {
        getline(cin, value);
        if (is_correct(value)) {
            return stoi(value);
        }
    }
}

int get_reminder(const int a, const int b) {
    return a % b;
}

int get_division(const int a, const int b) {
    return b / a;
}


int main() {
    const int a = enter_value();
    const int b = enter_value();

    cout << "Reminder: " << get_reminder(a, b) << endl;
    cout << "Division: " << get_division(a, b) << endl;
}
