

#include <iostream>
#include <vector>
using namespace std;
class Person
{
protected:
    char* name;
    int age;
public:
    Person() = default;
    Person(const char* n, int a) :age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }
    void Print()
    {
        cout << "Name:" << name << endl;
        cout << "Age: " << age << endl;
    }
    void Input()
    {
        char buff[30];
        cout << "Enter name: ";
        cin.getline(buff,30);
        delete[] name;
        name = new char[strlen(buff)+1];
        strcpy_s(name, strlen(buff) + 1, buff);
        cout << "Enter age: ";
        cin >> age;

    }
    ~Person()
    {
        delete[] name;
    }
};
class Student :public Person
{
    char* Uni;
public:
    Student() = default;
    Student(const char* u, const char* n, int a) : Person(n, a)
    {
        Uni = new char[strlen(u) + 1];
        strcpy_s(Uni, strlen(u) + 1, u);
    }
    void Print()
    {
        Person::Print();
        cout << "University: " << Uni << endl;
    }
    void Input()
    {
        Person::Input();
        char buff[30];
        cout << "Enter the university: ";
        cin.getline(buff, 30);
        delete[] Uni;
        Uni = new char[strlen(buff) + 1];
        strcpy_s(Uni, strlen(buff) + 1, buff);
    }
    ~Student()
    {
        delete[] Uni;
    }
};
class Teacher :public Person
{
    char* school;
    int income;
    vector<string> subjects;
public:
    Teacher() = default;
    Teacher(const char* s, int i, vector<string> sub, const char* n, int a) : Person(n, a)
    {
        school = new char[strlen(s) + 1];
        strcpy_s(school, strlen(s) + 1, s);
        subjects = sub;
        income = i;
    }
    void Print()
    {
        Person::Print();
        cout << "School: " << school << endl;
        cout << "Income: " << income << endl;
        cout << "Subjects: ";
        for (size_t i = 0; i < subjects.size(); i++)
        {
            cout << subjects[i] <<" ";
        }
    }
    ~Teacher()
    {
        delete[] school;
    }
};
class Driver :public Person
{
    int autonum;
    int serial;
    bool dLicense;
public:
    Driver() = default;
    Driver(const char* n, int a, int an, int ser, bool d) : Person(n, a)
    {
        autonum = a;
        serial = ser;
        dLicense = d;
    }
    void Print()
    {
        Person::Print();
        cout << "Number of the Car: " << autonum<< endl;
        cout << "Serial Number: " << serial << endl;
        cout << "Driver License: " << (dLicense ? "Yes" : "No") << endl;
    }
};
class Doctor :public Person
{
    char* specialization;
    int experience;
    bool isFamily;
public:
    Doctor() = default;
    Doctor(const char* n, int a, const char* spec, int exp, bool is) : Person(n, a)
    {
        specialization = new char[strlen(spec) + 1];
        strcpy_s(specialization, strlen(spec) + 1, spec);
        experience = exp;
        isFamily = is;
    }
    void Print()
    {
        Person::Print();
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << endl;
        cout <<"Is Family doctor: " << (isFamily ? "Yes" : "No") << endl;
    }
    ~Doctor()
    {
        delete[] specialization;
    }
};
int main()
{
    
}

