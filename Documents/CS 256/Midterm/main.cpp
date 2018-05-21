//Github - https://github.com/rainko/Nimbus/blob/master/Documents/CS%20256/Midterm/main.cpp

#include <iostream>
#include <string>
#include <vector>


using namespace std;


/****************Human******************/

class Human {

private:
    string _name;
    int _age;
    char _sex;

    Human();

    friend class Parent;
    friend class Child;

protected:
    Human(string name, int age, char sex);

public:
    void setName(string name);
    string getName();

    void setAge(int age);
    int getAge();

    void setSex(char sex);
    char getSex();

    virtual string work() = 0;

};

Human::Human() :_name(""), _age(0), _sex(' ') {;
}

Human::Human(string name, int age, char sex) :
        _name(name), _age(age), _sex(sex) {
}

void Human::setName(string name) {
    _name = name;
}

string Human::getName() {
    return _name;
}

void Human::setAge(int age) {
    _age = age;
}

int Human::getAge() {
    return _age;
}

void Human::setSex(char sex) {
    _sex = sex;
}

char Human::getSex() {
    return _sex;
}


/******************Parent********************/

class Child;

class Parent : public Human {

private:

    Parent();
    vector<Child> children;

    friend class Parent;

public:

    Parent(string name, int age, char sex);

    void setChildren(vector<Child>&  newChildren);
    vector<Child>& getChildren();

    void nameChild(Child& child, string name);

    string work() override;

};

Parent::Parent() : Human(), children() {}

Parent::Parent(string name, int age, char sex) :
Human(name, age, sex) {
}

void Parent::setChildren(vector<Child>& newChildren) {
    children = newChildren;
}


vector<Child>& Parent::getChildren(){
    return children;
}


string Parent::work() {
    if (this->getSex() == 'M') {
        return "Safety inspector";
    } else {
        return "Housewife";
    }
}



/*****************Child**********************/

class Child : public Human {

private:
    Parent Mom;
    Parent Dad;

    Child();

    friend class Parent;

public:
    Child(string name, int age, char sex, Parent mom, Parent dad);

    string work() override;

};

Child::Child() :
Human(), Mom("", 0, ' '), Dad("", 0, ' ') {
}

Child::Child(string name, int age, char sex, Parent mom, Parent dad) :
        Human(name, age, sex), Mom(mom), Dad(dad) {

}

string Child::work() {
    if (this->getAge() > 3) {
        return "Student";
    } else {
        return "Play";
    }
}

void Parent::nameChild(Child& child, string name) {
    child._name = name;
}








int main() {

    vector<Child> children;

    Parent homer("Homer", 36, 'M');
    Parent marge("Marge", 34, 'F');

    Child lisa("", 12, 'F', marge, homer);
    Child bart("", 10, 'M', marge, homer);
    Child maggie("", 3, 'F', marge, homer);

    children.push_back(lisa);
    children.push_back(bart);
    children.push_back(maggie);

    homer.setChildren(children);
    marge.setChildren(children);

    marge.nameChild(maggie, "Maggie");
    homer.nameChild(bart, "Bart");
    homer.nameChild(lisa, "Lisa");

    cout << homer.getName() << " " << homer.getAge() << " " <<  homer.getSex() << " " << homer.work();
    cout << endl << lisa.getName() << " " << lisa.getAge() << " " <<  lisa.getSex() << " " << lisa.work();
    cout << endl << maggie.getName() << " " << maggie.getAge() << " " <<  maggie.getSex() << " " << maggie.work();



    return 0;
}







































