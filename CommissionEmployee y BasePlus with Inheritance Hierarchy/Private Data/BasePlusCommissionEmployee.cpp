#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

//constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string&first, const string& last, const string& ssn,
    double sales, double rate, double salary)
    // explicitly call base-class constructor
    : CommissionEmployee(first,last,ssn,sales,rate) {        
        setBaseSalary(salary); //validate and store salary
    }

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary < 0.0){
        throw invalid_argument("Salary must be >=0.0");
    }
    baseSalary = salary;
}

//return base salary
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}
// calculate earnings
double BasePlusCommissionEmployee::earnings() const{
    //derived class cannot access the base class's private data
    return baseSalary + (commissionRate * grossSales);
}

// return string representation of ComissionEmployee object
string BasePlusCommissionEmployee::toString() const {
    ostringstream output;
    output << fixed << setprecision(2); //two digits precision
    output << "commission employee: " << firstName << " " << lastName
        << "\nsocial security number: " << socialSecurityNumber
        << "\ngross sales: " << grossSales
        << "\ncommission rate: " << commissionRate
        << "\nbase salary: " << baseSalary;
    return output.str();
}