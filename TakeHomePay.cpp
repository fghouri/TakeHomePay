/*
*
* Purpose: Calculate the salary after taking out all the taxes
*
*/

#include <iostream>
#include <cctype>
#include <limits>


#define SS_TAX_RATE         6.2
#define M_TAX_RATE          1.45

using namespace std;

// forwards
void calculateTaxes(double salary, double &incomeTax, double &ssTax, double &mTax);
void displayTakeHomePay();

// main
int main() {

    double salary, incomeTax, ssTax, mTax;
    bool isInputNumeric = false;

    cout << "Enter a salary: "  << endl;
    //cin >> salary;

    // validate
    do {
        std::cout << "Enter the amount you'd like to deposit: " << std::endl;

        if (scanf_s("%lf", &salary) == 1 && salary > 0) {
            isInputNumeric = true;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush buffer
            isInputNumeric = false;
        }
        cout << salary << endl;
    } while (!isInputNumeric);

    if(salary < 15080) {
        cout << "This is less than minimum wage for a yearly salary." << endl; 
        return 1;
    }

    calculateTaxes(salary, incomeTax, ssTax, mTax);

    // display out informatino
    cout << "-----------------------------------" << endl;
    printf("Yearly Salary:\t\t $%0.2f\n", salary);
    printf("Social Security Tax:\t\t $%0.2f\n", ssTax);
    printf("Medicare Tax:\t\t\t $%0.2f\n", mTax);
    printf("Income Tax:\t\t\t $%0.2f\n", incomeTax);
    cout << "-----------------------------------" << endl;
    printf("Take Home Salary:\t\t $%0.2f\n", (salary-incomeTax));
    printf("Monthly Take Home Pay:\t $%0.2f\n", ((salary-incomeTax)/12)); 

    return 0;
}

void calculateTaxes(double salary, double &incomeTax, double &ssTax, double &mTax) {
    // social security tax
    ssTax = (SS_TAX_RATE/100) * salary;

    // medicare tax
    mTax = (M_TAX_RATE/100) * salary;

    // income tax
    double itRate, temp = salary;

    if (temp > 539900) {
        itRate = 37.0;
        incomeTax = (itRate/100) * (salary - 539900);
        temp -= 539900;
        printf("Bracket 7, ITRate: %0.2f, Salary: %0.2f, Income Tax: %0.2f, Temp: %0.2f\n ", itRate, salary, incomeTax, temp);
    }
    if (215950 < temp && temp < 539900) {
        itRate = 35.0;
        incomeTax = incomeTax + ((itRate/100) * (salary - 215950));
        temp -= 215950;
        printf("Bracket 6, ITRate: %0.2f, Salary: %0.2f, Income Tax: %0.2f, Temp: %0.2f\n ", itRate, salary, incomeTax, temp);
    }
    if (170050 < temp && temp < 215950) {
        itRate = 32.0;
        incomeTax = incomeTax + ((itRate/100) * (salary - 170050));
        temp -= 170050;
        printf("Bracket 5, ITRate: %0.2f, Salary: %0.2f, Income Tax: %0.2f, Temp: %0.2f\n ", itRate, salary, incomeTax, temp);
    }
    if (89075 < temp && temp < 170050) {
        itRate = 24.0;
        incomeTax = incomeTax + ((itRate/100) * (salary - 89075));
        temp -= 89075;
        printf("Bracket 4, ITRate: %0.2f, Salary: %0.2f, Income Tax: %0.2f , Temp: %0.2f\n ", itRate, salary, incomeTax, temp);
    }
    if (41775 < temp && temp < 89075) {
        itRate = 22.0;
        incomeTax = incomeTax + ((itRate/100) * (salary - 41775));
        temp -= 41775;
        printf("Bracket 3, ITRate: %0.2f, Salary: %0.2f, Income Tax: %0.2f, Temp: %0.2f\n ", itRate, salary, incomeTax, temp);
    }
    if (10275 < temp && temp < 41775) {
        itRate = 12.0;
        incomeTax = incomeTax + ((itRate/100) * (salary - 10275));
        temp -= 10275;
        printf("Bracket 2, ITRate: %0.2f, Salary: %0.2f, Income Tax: %0.2f, Temp: %0.2f\n ", itRate, salary, incomeTax, temp);
    }
    if(temp < 10275) {
        itRate = 10.0;
        incomeTax = (itRate/100) * salary;
        printf("Bracket 1, ITRate: %0.2f, Salary: %0.2f, Income Tax: %0.2f , Temp: %0.2f\n ", itRate, salary, incomeTax, temp);
    }   
    incomeTax = incomeTax + ssTax + mTax;
}
