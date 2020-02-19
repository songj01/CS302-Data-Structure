#include "EmployeeList.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/// Initilize the employee information

EmployeeList::EmployeeList(){
    head = NULL; ///< Initilize head node
    temp = NULL; ///< Initilize temp node

    int setemployeeSum =0; ///< create setemployeeSum variable with initialization
    cout << "How many employees do you want to enter?\n"; ///< prompt for employees
    cout << "please enter: "; ///< prompt for inputing the number of employees
    cin >> setemployeeSum; ///< input the number of employee
    cout <<"Attention: Please end with '/' when entering characters!!"<<endl;///< prompt information
    employeeSum = setemployeeSum; ///< set variable
    }

/// read employee inforamtion
void EmployeeList::readEmployeeData(){
    int i=0;                                ///< Initialize the number

   /** read all of the employees' infrmation
     * cantain name,age,etc.
     */
     while(i< employeeSum) {              ///< loop condition
        Eynode n = new employeeDataNode;  ///< create a new node
        n->next = NULL;                   ///< Initialization
        cout << "Please enter the information of employee: \n\n\n";  ///< prompt
        cout << "Please enter the name of employee: \n"; ///< prompt for inputiing name
        getline(cin,n->Name,'/');                        ///< input name
        cout << "Please enter the ID of employee: \n";   ///< prompt for inputiing IdNumber
        cin >> n->IdNumber;                              ///< input IdNumber
        cout << "Please enter the age of employee: \n";  ///< prompt for inputiing Age
        cin >> n->Age;                                    ///< input information
        cout << "Please enter the dept of employee: \n";  ///< prompt for inputiing Dept
        getline(cin,n->Dept,'/');                         ///< input information
        cout << "Please enter the contact of employee: \n"; ///< prompt for inputiing Contact
        cin >> n->Contact;                                 ///< input information
        cout << "Please enter the address of employee: \n"; ///< prompt for inputiing Addr
        getline(cin,n->Addr,'/');

        i++;                                            ///< variable+1

        if(head==NULL){                                 ///< judgement condition
        head=n;                                         ///< result
    }
    else{                                               ///< result when if is false
        n->next=head;
        head = n;
       }
   }
}

/** sort the information according the ID Number from small to large
  * with bubble agorithm
  */
void EmployeeList::sortEmployeeData() {
    Eynode i, j, tmp1, tmp2;  ///< define variable i, j, tmp1,tmp2

    bool flag = true;         ///< set variable flag with value
     /// first two node exchage
   for (i = head; flag;) {
        flag = false;
            if (i->IdNumber > i->next->IdNumber) {   ///< the condition of if
            tmp1 = head->next;      ///< exchange
            head->next = tmp1->next; ///< exchange
            tmp1->next = head;       ///< exchange
            head = tmp1;             ///< exchange
            flag = true; ///< the condition of for loop end
            }
    i = head;
    tmp1 = head;
/// sort the inforamtion based on comparsion
    for (j = head->next; j->next != NULL; j = j->next) {
        if (j->IdNumber > j->next->IdNumber) {
            tmp2 = j->next;                  ///< exchange
            j->next = j->next->next;         ///< exchange
            tmp2->next = j;                  ///< exchange
            tmp1->next = tmp2;               ///< exchange
            j = tmp1->next;                  ///< exchange
            flag = true;
            }
        tmp1 = tmp1->next;  ///< tmp1 move to next
    }
    }
}

/// print the sort the information
void EmployeeList::printEmployeeData(){
    int j= employeeSum;                        ///< define variable j
    temp = head;
                            ///< initilization
/** when the condition is truen
  * will print the information if employees
  */
    while(j>0){
            if(temp!=NULL){
                cout<<"  "<<temp->Name<<"  "<< temp->IdNumber<<"  "<< temp->Age<<"  "<<temp->Dept<<"  "<<temp->Contact<<"  "<<temp->Addr<<endl;
                temp= temp->next;
            }
      j--;
    }

}
/// calculate the information
void EmployeeList::calculateEmployeeData(){

    float totalAge=0, avgAge; ///< define variable total Age and avgAge
    int j= employeeSum;       ///< define variable j with value
    temp = head;

    while(j>0){
    if(temp!=NULL){
        totalAge+=temp->Age;   ///< calculate the total ages of employees
        temp= temp->next;      ///< pointer move to the next
        j--;
        }
    }
     avgAge= totalAge/employeeSum; ///< calculate the average age of employee
     cout << "aveAge = " ;
     /// output the avaerage age of employees with precision
    cout << fixed << setprecision(1)<< avgAge << endl;
}
