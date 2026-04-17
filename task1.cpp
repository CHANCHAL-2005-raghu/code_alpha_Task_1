#include <iostream>
using namespace std;

int main() {
    int n;
    float grade, total = 0, cgpa;

    cout << "Enter number of subjects: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter grade points for subject " << i << ": ";
        cin >> grade;
        total += grade;
    }

    cgpa = total / n;

    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
