#include "std_lib_facilities.h"

struct Person
{
public:
    Person(){}
    Person(string f, string s, int a) : f{ f }, s{ s }, a{ a } {
        if (a < 0 or a > 150) error("Invalid age");
        string n = f + s;
        for (char c : n) {
            switch (c) {
                case ';':
                case ':':
                case '"':
                case '\'':
                case '[':
                case ']':
                case '*':
                case '&':
                case '^':
                case '%':
                case '$':
                case '#':
                case '@':
                case '!':
                    error("Invalid character in name");
                default:
                    break;
            }
        }
    }
    //string name() const { return n; }
    string first_name() const { return f; }
    string second_name() const { return s; }
    int age() const { return a; }
private:
    //string n; // name
    string f; // f_name
    string s; // s_name
    int a; // age
};

istream& operator>>(istream& is, Person& p) {
    // string n; //name
    string f; //first name
    string s; //second name
    int a; //age

    //cout << "Input name and age:" << endl;
    is >> f >> s >> a;
    p = Person(f, s, a);

    return is;
}

ostream& operator<<(ostream& os, Person& p) {
    return os << "Name: " << p.first_name() << " " << p.second_name() << " Age: " << p.age() << endl;
}

int main() {
    /*
    Person goofy;
    goofy.name = "Goofy";
    goofy.age = 63;
    
    cout << "Name: " << goofy.name << endl << "Age: " << goofy.age << endl;
    */
    Person goofy("Goofy","", 63);

    cout << goofy;

    Person person;

    cout << "Input name(first, second) and age: ";
    cin >> person;
    cout << person;

    vector<Person> vect;
    Person p;
    
    cout << "Input a sequence of \"Persons\": ";
    while (cin >> p) {
        if (p.first_name() == "q") break; // q = quit
        vect.push_back(p);
    }

    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i];
    }
    

    return 0;
}