#include <iostream>
#include <string>
#include <iomanip>


#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

using namespace std;


typedef struct employeeDataNode
{
    string Name;     ///< The name of employee
    int  IdNumber;  ///< The ID number of employee
    int  Age;       ///< The age of employee
    string Dept;    ///< The department of employee
    int  Contact;  ///< The contact of employee
    string  Addr;  ///< The address of employee
    /// Initialize the informstion of employee
    employeeDataNode(){
        Name= "NULL";
        IdNumber= 0;
        Age = 0;
        Dept = "NULL";
        Contact = 0;
        Addr = "NULL";
        };
   employeeDataNode* next;/// The pointer
} * Eynode;    ///< Define Eynode that is the same as emloyeeNode *


class EmployeeList
{
    public:
        /// Create an EmployeeList class with some initial values
        EmployeeList();
        ///user input the informations of employee according to the prompt
        void readEmployeeData();

        /** Based on the IdNumber input by user
         * program will sort the employee informations
         * from samll to large.
         */
        void sortEmployeeData();

        /// Print the sorted information
        void printEmployeeData();

        /** This is a mothod to analzye some statistics
         * the function will calculate the average age of
         * employesss. */
        void calculateEmployeeData();
    private:
        int employeeSum;  /**< the total number of employee that
                               user wants to read. */
        Eynode  head; ///< head node
        Eynode  temp; /// tempoary node
};                     // end of class EmployeeList

#endif // EMPLOYEELIST_H
