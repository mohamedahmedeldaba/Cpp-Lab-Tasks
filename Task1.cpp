#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    int id;
    float grade;

    cout << "Enter student full name: ";
    getline(cin, name);

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student grade: ";
    cin >> grade;

    ofstream file("Student.txt");

    if (!file)
    {
        cout << "File error!";
        return 1;
    }

    file << "Name: " << name << endl;
    file << "ID: " << id << endl;
    file << "Grade: " << grade << endl;

    file.close();

    cout << "Data saved successfully!";

    return 0;
}