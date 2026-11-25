#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    ofstream file("persons.txt");

    if (!file)
    {
        cout << "File error!";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        Person p;

        cout << "Enter person name: ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Enter person age: ";
        cin >> p.age;

        file << p.name << endl;
        file << p.age << endl;
    }

    file.close();

    vector<Person> persons;

    ifstream input("persons.txt");

    Person p;

    while (getline(input, p.name))
    {
        if (input >> p.age)
        {
            persons.push_back(p);
        }

        input.ignore();
    }

    input.close();

    if (persons.empty())
    {
        cout << "No persons found!";
        return 0;
    }

    int youngest = persons[0].age;
    int oldest = persons[0].age;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age < youngest)
        {
            youngest = persons[i].age;
        }

        if (persons[i].age > oldest)
        {
            oldest = persons[i].age;
        }
    }

    ofstream result("results.txt");

    result << "Youngest Person(s):" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == youngest)
        {
            result << persons[i].name
                   << " - " << persons[i].age << endl;
        }
    }

    result << "Oldest Person(s):" << endl;

    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age == oldest)
        {
            result << persons[i].name
                   << " - " << persons[i].age << endl;
        }
    }

    result.close();

    cout << "Results saved successfully!";

    return 0;
}