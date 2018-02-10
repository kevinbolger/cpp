//
//  main.cpp
//
// This file contains a class "user", with collects attributes such as age, dob, firs/last name, full name.
// This is part of a larger project to create a 'fantasy league' program using C++.
// I'm sharing the code below because I found it difficult to source information on creating dates, ages etc.
// I hope this resource can help others get there quicker
//

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

/* Note: Age is approximate. Does not currently support Leap Years//
global function takes time_t object birthday and calculates in years, the difference
between then and todays date/time. Can be used as generic "Years Since Event" calculator.
Can be easily modified to calculate days, hours, minutes etc. */
int ageCalculator(time_t birthday){
    time_t now;
    struct tm nowLocal;
    now = time(NULL);
    nowLocal = *localtime(&now);
    time_t todaysDay = mktime(&nowLocal);
    int age = (todaysDay - birthday)/60/60/24/365.0;
    return age;
};

// Takes time_t object and returns it in string format
string dateString(time_t dateTime){
    string output = ctime(&dateTime);
    return output;
};

// Takes date inputs and uses those to generate time_t object 
// which is plugged in to the functions above.
time_t  dateCreate(int day, int month, int year){
    struct tm date = {0};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;
    time_t dateTime;
    dateTime = mktime(&date);
    return dateTime;
};

class user{
private:
    int age;
    string dob;
    string name;
    string firstName;
    string lastName;
public:
    void setAgeData(int day, int month, int year){
        time_t dateTime = dateCreate(day,month,year);
        dob = dateString(dateTime);
        age = ageCalculator(dateTime);
    }
    void setName(string forename, string surname){
        name = forename + " " + surname;
        firstName = forename;
        lastName = surname;
    };
    
    void greetUser(){
        cout << "Hello, " << firstName << ". I hope you are well today!\n";
    }
    
    void printUserAge(){
        cout << name << "\'s Age: " << age << "\n";
    }
    
    void printUserDOB(){
        cout << name << "\'s DOB: " << dob << "\n";
    }
    
};

int main() {

    // Create a JDoe object, assign its name and dob and print some messages.
    user JDoe;
    JDoe.setName("John","Doe");
    JDoe.setAgeData(30, 1, 1980);
    JDoe.greetUser();
    JDoe.printUserAge();
    JDoe.printUserDOB();

}
