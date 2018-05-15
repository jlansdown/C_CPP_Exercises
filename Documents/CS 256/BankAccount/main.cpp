#include <iostream>
#include <iomanip>
#include<string>
#include <sstream>

using namespace std;


/*****************BankAccount***************/


class BankAccount {

private:
    double annualInterestRate;

protected:

    double balance;
    int deposits;
    int withdrawals;
    double monthlyServiceCharge;

    BankAccount();
    BankAccount(double bal, double interest);

public:
    virtual string deposit(double amount);
    virtual string withdrawal(double amount);

    virtual void calcInt();
    virtual void monthlyProc() = 0;

};

BankAccount::BankAccount() : balance(0),
                             annualInterestRate(.01),
                             monthlyServiceCharge(1.00),
                             deposits(0),
                             withdrawals(0) {

}

BankAccount::BankAccount(double bal, double interest) {
    balance = bal;
    annualInterestRate = interest;
    monthlyServiceCharge = 1.00;
    deposits = 0;
    withdrawals = 0;
}


string BankAccount::deposit(double amount) {
    stringstream outString;
    string total;

    deposits++;
    balance += amount;

    outString << fixed << setprecision(2) << "Deposit: " << amount << "\nTotal deposits: " << deposits;

    total = outString.str();

    return total;
}

string BankAccount::withdrawal(double amount) {
    stringstream outString;
    string total;

    withdrawals++;
    balance -= amount;

    outString << "Withdrew: " << fixed << setprecision(2) << amount << "\nTotal withdrawals: " << withdrawals
            << "\nBalance: " << balance;

    total = outString.str();

    return total;
}


void BankAccount::calcInt() {
    double monthlyInterestRate = (annualInterestRate/12);
    double monthlyInterest = balance * monthlyInterestRate;

    balance += monthlyInterest;
}

void BankAccount::monthlyProc() {
    balance -= monthlyServiceCharge;
    calcInt();
    withdrawals = 0;
    deposits = 0;
    monthlyServiceCharge = 0;

    cout << fixed << setprecision(2) << endl << "Monthly proc occured!\nBalance: "
         << balance << endl;
}


/*********SavingsAccount*******************/


class SavingsAccount : private BankAccount {

private:
    bool status = false;

public:
    SavingsAccount();
    SavingsAccount(double bal, double interest);


    string deposit(double amount) override ;
    string withdrawal(double amount) override;
    void monthlyProc() override;
};

SavingsAccount::SavingsAccount() : BankAccount(), status(false) {
}

SavingsAccount::SavingsAccount(double bal, double interest) :
        BankAccount(bal, interest) {
    if (bal >= 25) {
        status = true;
    } else {
        status = false;
    }
}

string SavingsAccount::withdrawal(double amount) {
    if (balance < 25) {
        status = false;
    }

    if(status) {
        return "Savings Account\n" + BankAccount::withdrawal(amount);
    } else {
        return "Savings Account\nThis savings account is inactive.";
    }
}

string SavingsAccount::deposit(double amount) {
    stringstream outString;
    string total;

    if (balance + amount >= 25) {
        status = true;
    }

    outString << fixed << setprecision(2) << "Savings Account\n" << BankAccount::deposit(amount) <<
              "\nBalance: " << balance;

    total = outString.str();
    return total;
}

void SavingsAccount::monthlyProc() {
    if (this->withdrawals > 4) {
        this->monthlyServiceCharge++;
    }

    BankAccount::monthlyProc();

    if (this->balance < 25) {
        this->status = false;
    }
}

/**************CheckingAccount*******************/


class CheckingAccount : private BankAccount {

private:
    bool penalty;

public:
    CheckingAccount();
    CheckingAccount(double bal, double interest);


    string deposit(double amount) override;
    string withdrawal(double amount) override;
    void monthlyProc() override;
};

CheckingAccount::CheckingAccount() : BankAccount(), penalty(false) {
}

CheckingAccount::CheckingAccount(double bal, double interest):
        BankAccount(bal, interest), penalty(false) {
}

string CheckingAccount::deposit(double amount) {
    stringstream outString;
    string total;

    outString << fixed << setprecision(2) << "Checking Account\n" <<
              BankAccount::deposit(amount) + "\nBalance: " <<
              balance;

    total = outString.str();
    return total;
}

string CheckingAccount::withdrawal(double amount) {
    stringstream outString;
    string total;

    if((balance - amount) < 0) {
        balance -= 15;      //Service charge


        outString << fixed << setprecision(2) << "Checking Account"
                "\nWithdrawal incomplete, insufficient funds. \nBalance: "
                     << balance;

        total = outString.str();

        return total;
    }

    if (penalty) {
        balance -= 0.1;
    }

    return "Checking Account\n" + BankAccount::withdrawal(amount);
}

void CheckingAccount::monthlyProc() {
    monthlyServiceCharge += 5;

    if (balance < 0) {
        penalty = true;
    }

    BankAccount::monthlyProc();
}

/*******************Main************************/


int main() {

    int selection = 0, exit = 0, count = 0, amount = 0;
    SavingsAccount savings(24, 2);
    CheckingAccount checking(30, 1);


    do {
        cout << endl << "\n1) Checking deposit\n2) Checking withdrawal\n"
                "3) Savings deposit\n4) Savings withdrawal\n5) Exit\nSelection: ";


        do {
            if (cin >> selection) {
                break;
            } else {
                cout << "Please enter a valid integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while (!isdigit(selection));


        switch (selection) {
            case 1:
                cout << "Deposit amount: ";
                do {
                    if (cin >> amount) {
                        break;
                    } else {
                        cout << "Please enter a valid integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while (!isdigit(amount));
                cout << endl << checking.deposit(amount);
                break;

            case 2:
                cout << "Withdrawal amount: ";
                do {
                    if (cin >> amount) {
                        break;
                    } else {
                        cout << "Please enter a valid integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while (!isdigit(amount));
                cout << endl << checking.withdrawal(amount);
                break;

            case 3:
                cout << "Deposit amount: ";
                do {
                    if (cin >> amount) {
                        break;
                    } else {
                        cout << "Please enter a valid integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while (!isdigit(amount));
                cout << endl << savings.deposit(amount);
                break;

            case 4:
                cout << "Withdrawal amount :";
                do {
                    if (cin >> amount) {
                        break;
                    } else {
                        cout << "Please enter a valid integer: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }while (!isdigit(amount));
                cout << endl << savings.withdrawal(amount);
                break;

            case 5:
                exit = 5;
                break;

            default:
                cout << "Invalid selection" << endl;
                break;
        }
        count++;
        if (count % 5 == 0) {
            cout << endl << "\nSavings account:";
            savings.monthlyProc();
            cout << "\nChecking account:";
            checking.monthlyProc();
        }
    }while (exit != 5);

    return 0;
}