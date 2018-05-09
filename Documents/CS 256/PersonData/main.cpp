#include <iostream>
#include <string>

using namespace std;


class PersonData {

private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    int zip;
    string phone;

public:

    PersonData();

    void setlastName(string lName);
    string getLastName();

    void setFirstName(string fName);
    string getFirstName();

    void setAddress(string adrs);
    string getAddress();

    void setCity(string cityName);
    string getCity();

    void setState(string stateName);
    string getState();

    void setZip(int zipCode);
    int getZip();

    void setPhone(string phoneNum);
    string getPhone();




};

PersonData::PersonData() : lastName(""), firstName(""),
                           address(""), city(""), state(""),
                           zip(0), phone(""){
    cout << "PersonData constructor called." << endl;
}

void PersonData::setlastName(string lName) {
    lastName = lName;
}

string PersonData::getLastName() {
    return lastName;
}

void PersonData::setFirstName(string fName) {
    firstName = fName;
}

string PersonData::getFirstName() {
    return firstName;
}

void PersonData::setAddress(string adrs) {
    address = adrs;
}

string PersonData::getAddress() {
    return address;
}

void PersonData::setCity(string cityName) {
    city = cityName;
}

string PersonData::getCity() {
    return city;
}

void PersonData::setState(string stateName) {
    state = stateName;
}

string PersonData::getState() {
    return state;
}

void PersonData::setZip(int zipCode) {
    zip = zipCode;
}

int PersonData::getZip() {
    return zip;
}

void PersonData::setPhone(string phoneNum) {
    phone = phoneNum;
}

string PersonData::getPhone() {
    return phone;
}




class CustomerData : public PersonData {

private:
    int customerNumber;
    bool mailingList;

public:
    CustomerData();

    void setCustomerNum(int num);
    int getCustomerNum();

    void setMailingList(bool mail);
    bool getMailingList();

};

CustomerData::CustomerData() : customerNumber(0), mailingList(false) {
    cout << "CustomerData constructor called." << endl;
}

void CustomerData::setCustomerNum(int num) {
    customerNumber = num;
}

int CustomerData::getCustomerNum() {
    return customerNumber;
}

void CustomerData::setMailingList(bool mail) {
    mailingList = mail;
}

bool CustomerData::getMailingList() {
    return mailingList;
}


class PreferredCustomer : public CustomerData {

private:
    double purchasesAmount;
    double discountLevel;

public:

    PreferredCustomer();

    PreferredCustomer(string lName, string fName, string adrs, string cty,
    string stateName, int zipCode, string phoneNum, int custNum, bool mail,
    double purchaseAmt);

    void setPurchasesAmount(double amount);
    double getPurchasesAmount();

    void setDiscountLevel(double discount);
    double getDiscountLevel();
};

PreferredCustomer::PreferredCustomer() : purchasesAmount(0), discountLevel(0) {

}

PreferredCustomer::PreferredCustomer(string lName, string fName, string adrs, string cty, string stateName, int zipCode,
                                   string phoneNum, int custNum, bool mail, double purchaseAmt) {
    cout << "PreferredCustomer constructor called.\n" << endl;

    setlastName(lName);
    setFirstName(fName);
    setAddress(adrs);
    setCity(cty);
    setState(stateName);
    setZip(zipCode);
    setPhone(phoneNum);
    setCustomerNum(custNum);
    setMailingList(mail);
    purchasesAmount = purchaseAmt;

    if (purchasesAmount < 0) {
        cout << "Sales cannot be less than 0";
        exit(1);
    }

    if (purchasesAmount >= 500 && purchasesAmount < 1000) {
        discountLevel = 0.05;
    } else if (purchasesAmount >= 1000 && purchasesAmount < 1500 ) {
        discountLevel = 0.06;
    } else if (purchasesAmount >= 1500 && purchasesAmount < 2000) {
        discountLevel = 0.07;
    } else if (purchasesAmount >= 2000) {
        discountLevel = 0.1;
    } else {
        discountLevel = 0;
    }


}

void PreferredCustomer::setPurchasesAmount(double amount) {
    purchasesAmount = amount;
}

double PreferredCustomer::getPurchasesAmount() {
    return purchasesAmount;
}

void PreferredCustomer::setDiscountLevel(double discount) {
    discountLevel = discount;
}

double PreferredCustomer::getDiscountLevel() {
    return discountLevel;
}


int main() {

    PreferredCustomer customer("Lansdown", "James", "123 Cool St.", "Awesomeville",
                            "California", 91123, "555-555-5555",
                            1234567, true, 1454);

    cout << "Preferred customer: " << customer.getFirstName() <<
         " " << customer.getLastName() << endl;

    cout << "Address: " << customer.getAddress() << endl;
    cout << "City: " << customer.getCity() << endl;
    cout << "State: " << customer.getState() << endl;
    cout << "Zip: " << customer.getZip() << endl;
    cout << "Phone #: " << customer.getPhone() << endl;
    cout << "Customer #: " << customer.getCustomerNum() << endl;

    if(customer.getMailingList()) {
        cout << "Mailing list: yes"<< endl;
    }else {
        cout << "Mailing list: no" << endl;
    }

    cout << "Purchase Amount: $" << customer.getPurchasesAmount() << endl;
    cout << "Discount level: " << (customer.getDiscountLevel() * 100) << "%" << endl;



    return 0;
}