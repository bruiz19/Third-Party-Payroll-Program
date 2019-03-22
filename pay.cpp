#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "person.h"
#include "person.cpp"

using namespace std;

void readData(vector<Person> &Empvect);
void getCompanies(vector<Person> &Empvect, vector<string> &compVect);
void PrintHighestPaid(vector<Person> &Empvect);
void seperateAndSave(vector<Person> &Empvect, vector<string> &compVect);


int main() {

vector<Person> employees;
vector<string> companyNames;

readData(employees);
getCompanies(employees, companyNames);
PrintHighestPaid(employees);

seperateAndSave(employees, companyNames);

}

void readData(vector<Person> &Empvect) {

Person beta;
fstream myFile;
myFile.open("input.txt");

string Fname;
string Lname;
int id;
string compName;
float hours;
float payrate;

if (myFile.fail()) {
cout << "Cannot open the file." << endl;

}

myFile >> Fname >> Lname >> id >> compName >> hours >> payrate;
beta.setFirstName(Fname); beta.setLastName(Lname); beta.setEmployeeId(id);
beta.setCompanyName(compName); beta.setHoursWorked(hours); beta.setPayRate(payrate);

Empvect.push_back(beta);

}

myFile.close();

}


}

void getCompanies(vector<Person> &Empvect,vector<string> &compVect) {

for (unsigned int i = 0; i < Empvect.size(); i++) {

compVect.push_back(Empvect.at(i).getCompanyName());

}

}

void PrintHighestPaid(vector<Person> &Empvect) {

int counter = 0;
int id;
string coName;
string empName;
float total;

cout << showpoint;
for (unsigned int i = 0; i < Empvect.size(); i++) {

if (counter < Empvect.at(i).totalPay()) {

counter = Empvect.at(i).totalPay();
id = Empvect.at(i).getEmployeeId();
coName = Empvect.at(i).getCompanyName();
empName = Empvect.at(i).fullName();
total = Empvect.at(i).totalPay();

}


}

cout << "Highest paid: " << empName << endl;
cout << "Employee ID: " << id << endl;
cout << "Employer: " << coName << endl;
cout << "Total Pay: $" << total <<endl;

}


void seperateAndSave(vector<Person> &Empvect, vector<string> &compVect) {

string name;

for (unsigned int i = 0; i < compVect.size(); i++) {

float totalpay = 0;
name = compVect.at(i);

ofstream outputFile (name+".txt");
ifstream inputFile;

inputFile.open(name+".txt");

outputFile << "Company: " << name << ".txt" << endl;
outputFile << "___________________________________________________________________" << endl;

for (unsigned int i = 0; i < Empvect.size()-1; i++) {

if (name == Empvect.at(i).getCompanyName()) {

outputFile << Empvect.at(i).fullName() << Empvect.at(i).getEmployeeId() << Empvect.at(i).getCompanyName() << "$" << Empvect.at(i).totalPay() << endl;

totalpay += Empvect.at(i).totalPay();

}


}
outputFile << "Total Pay: $" << totalpay;
outputFile.close();

}


}
