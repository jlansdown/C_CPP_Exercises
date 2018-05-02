#include <iostream>
#include <string>

using namespace std;


class DayOfTheYear {

private:
    int dayOfYear;

    static const string January;
    static const string February;
    static const string March ;
    static const string April;
    static const string May;
    static const string June;
    static const string July;
    static const string August;
    static const string September;
    static const string October;
    static const string November;
    static const string December;

public:

    DayOfTheYear();
    DayOfTheYear(int day);
    DayOfTheYear(string month, int day);

    void print();
    string convertDay();

    DayOfTheYear& operator++ ();
    DayOfTheYear& operator-- ();

};

DayOfTheYear::DayOfTheYear() : dayOfYear(1) {}


DayOfTheYear::DayOfTheYear(int day) {
    dayOfYear = day;
}

DayOfTheYear::DayOfTheYear(string month, int day) {

    if (day > 31) {
        cout << "Day must be <= 31";
        exit(1);
    }

    if (month == January) {
        dayOfYear = day;
    } else if (month == February) {
        dayOfYear = 31 + day;
    } else if (month == March) {
        dayOfYear = 59 + day;
    } else if (month == April) {
        dayOfYear = 90 + day;
    } else if (month == May) {
        dayOfYear = 120 + day;
    } else if (month == June) {
        dayOfYear = 151 + day;
    } else if (month == July) {
        dayOfYear = 181 + day;
    } else if (month == August) {
        dayOfYear = 212 + day;
    } else if (month == September) {
        dayOfYear = 242 + day;
    } else if (month == October) {
        dayOfYear = 273 + day;
    } else if (month == November) {
        dayOfYear = 304 + day;
    } else {
        dayOfYear = 334 + day;
    }
}


void DayOfTheYear::print() {
    cout << "Day " << dayOfYear << " would be " << convertDay();
}


string DayOfTheYear::convertDay() {
    if (dayOfYear <= 31) {
        return January + " " + to_string(dayOfYear);
    } else if (dayOfYear > 31 && dayOfYear <= 59) {
        return February + " " + to_string(dayOfYear - 31);
    } else if (dayOfYear > 59 && dayOfYear <= 90) {
        return March + " " + to_string(dayOfYear - 59);
    } else if (dayOfYear > 90 && dayOfYear <= 120) {
        return April + " " + to_string(dayOfYear - 90);
    } else if (dayOfYear > 120 && dayOfYear <= 151) {
        return May + " " + to_string(dayOfYear - 120);
    } else if (dayOfYear > 151 && dayOfYear <= 181) {
        return June + " " + to_string(dayOfYear - 151);
    } else if (dayOfYear > 181 && dayOfYear <= 212) {
        return July + " " + to_string(dayOfYear - 181);
    } else if (dayOfYear > 212 && dayOfYear <= 242) {
        return August + " " + to_string(dayOfYear - 212);
    } else if (dayOfYear > 242 && dayOfYear <= 273) {
        return September + " " + to_string(dayOfYear - 242);
    } else if (dayOfYear > 273 && dayOfYear <= 304) {
        return October + " " + to_string(dayOfYear - 273);
    } else if (dayOfYear > 304 && dayOfYear <= 334) {
        return November + " " + to_string(dayOfYear - 304);
    } else {
        return December + " " + to_string(dayOfYear - 334);
    }
}

DayOfTheYear& DayOfTheYear::operator++() {
    this->dayOfYear += 1;
    if (this->dayOfYear > 365) {
        this->dayOfYear = 1;
    }
    return *this;
}

DayOfTheYear& DayOfTheYear::operator--() {
    this->dayOfYear -= 1;
    if (this->dayOfYear < 1) {
        this->dayOfYear = 365;
    }
    return *this;
}

const string DayOfTheYear::January = "January";
const string DayOfTheYear::February = "February";
const string DayOfTheYear::March = "March";
const string DayOfTheYear::April = "April";
const string DayOfTheYear::May = "May";
const string DayOfTheYear::June = "June";
const string DayOfTheYear::July = "July";
const string DayOfTheYear::August = "August";
const string DayOfTheYear::September = "September";
const string DayOfTheYear::October = "October";
const string DayOfTheYear::November = "November";
const string DayOfTheYear::December = "December";


int main() {

    DayOfTheYear firstDay;
    DayOfTheYear randDay(178);
    DayOfTheYear lastDay("December", 31);

    cout << "First day: ";
    firstDay.print();
    cout << "\nFirst day ++: ";
    ++firstDay;
    firstDay.print();
    cout << "\nFirst day --: ";
    --firstDay;
    --firstDay;
    firstDay.print();

    cout << endl << "\nRandom day: ";
    randDay.print();
    cout << "\nRandom day ++: ";
    ++randDay;
    randDay.print();
    cout << "\nRandom day --: ";
    --randDay;
    --randDay;
    randDay.print();

    cout << endl << "\nLast day: ";
    lastDay.print();
    cout << "\nLast day ++: ";
    ++lastDay;
    lastDay.print();
    cout << "\nLast day --: ";
    --lastDay;
    --lastDay;
    lastDay.print();

    return 0;
}