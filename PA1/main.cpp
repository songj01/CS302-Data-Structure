#include <iostream>
#include <string>
#include <iomanip>
#include "EmployeeList.h"

using namespace std;

int main()
{
    EmployeeList emp;
    emp.readEmployeeData();
    emp.sortEmployeeData();
    emp.printEmployeeData();
    emp.calculateEmployeeData();
}
