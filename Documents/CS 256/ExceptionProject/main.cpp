#include <iostream>
#include <string>

using namespace std;


/****************Employee******************/


class Employee{
    string _name, _hireDate;
    int _number;

public:

    Employee();
    Employee(string name, string date, int number);

    void setName(string name);
    string getName();

    void setNumber(int number);
    int getNumber();

    void setHireDate(string date);
    string getHireDate();
};

Employee::Employee() : _name(""), _hireDate(""), _number(0) {
}

Employee::Employee(string name, string date, int number) :
_name(name), _hireDate(date), _number(number) {

    if (_number < 0 || _number > 9999) {
        string InvalidEmployeeNumber = "Employee number cannot be < 0 or > 9999";
        throw InvalidEmployeeNumber;
    }

}

void Employee::setName(string name) {
    _name = name;
}

string Employee::getName() {
    return _name;
}

void Employee::setNumber(int number) {
    if (number < 0 || number > 9999) {
        string InvalidEmployeeNumber = "Employee number cannot be < 0 or > 9999";
        throw InvalidEmployeeNumber;
    }
    _number = number;
}

int Employee::getNumber() {
    return _number;
}

void Employee::setHireDate(string date) {
    _hireDate = date;
}

string Employee::getHireDate() {
    return _hireDate;
}

/**************ProductionWorker*******************/

class ProductionWorker : public Employee {

private:
    int _shift;
    double _payRate;

public:
    ProductionWorker();
    ProductionWorker(string name, string date, int number, int shift, double payRate);

    void setShift(int shift);
    int getShift();

    void setPayRate(double payRate);
    double getPayRate();
};

ProductionWorker::ProductionWorker() :
        Employee(), _shift(0), _payRate(0){
}

ProductionWorker::ProductionWorker(string name, string date, int number, int shift, double payRate) :
Employee(name, date, number), _shift(shift), _payRate(payRate) {
    if (shift < 1 || shift > 2) {
        string InvalidShiftException = "Shift must be 1 or 2.";
        throw InvalidShiftException;
    }

    if (_payRate < 0) {
        string InvalidPayRate = "Pay rate must be > 0.";
        throw InvalidPayRate;
    }
}

void ProductionWorker::setShift(int shift) {
    _shift = shift;
    if (shift < 1 || shift > 2) {
        string InvalidShiftException = "Shift must be 1 or 2.";
        throw InvalidShiftException;
    }
}

int ProductionWorker::getShift() {
    return _shift;
}

void ProductionWorker::setPayRate(double payRate) {
    if (payRate < 0) {
        string InvalidPayRate = "Pay rate must be > 0.";
        throw InvalidPayRate;
    } else {
        _payRate = payRate;
    }
}

double ProductionWorker::getPayRate() {
    return _payRate;
}


int main() {

    Employee employee;

    try {
        employee.setNumber(150993);
    }catch(string e) {
        cout << endl << "employee:";
        cout << endl << e << endl;
    }


    try {
        Employee employee2("John", "May 21, 2007", 10987);
    }catch (string e) {
        cout << endl << "employee2";
        cout << endl << e << endl;
    }


    ProductionWorker worker;

    try{
        worker.setShift(2);
        worker.setPayRate(-3);
    } catch(string e) {
        cout << endl << "worker:";
        cout << endl << e << endl;
    } catch (string e) {
        cout << endl << "worker:";
        cout << endl << e << endl;
    }

    try {
        ProductionWorker worker2("Wilson", "June 5, 2019", 784, 3, 5.00);
    }catch (string e) {
        cout << endl << "worker2:";
        cout << endl << e << endl;
    }

    return 0;
}