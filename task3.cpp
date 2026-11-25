#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string text;

    ofstream file("welcome.txt");

    file << "Hello Everybody";

    file.close();

    ifstream input("welcome.txt");

    getline(input, text);

    input.close();

    int position = text.find("body");

    if (position != string::npos)
    {
        text.replace(position, 4, "one");
    }

    ofstream output("welcome.txt");

    output << text;

    output.close();

    cout << text;

    return 0;
}