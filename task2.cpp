#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;

    ifstream file("fruit.txt");

    if (!file)
    {
        cout << "File not found!";
        return 1;
    }

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

    ofstream output("fruit.txt", ios::app);

    output << "Fresh Fruits" << endl;

    output.close();

    cout << "Message added successfully!";

    return 0;
}