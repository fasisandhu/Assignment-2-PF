//Muhammad Faseeh
//l215357@lhr.nu.edu.pk

#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>
using namespace std;

//Menu function for step 0
void menu() {
	cout << "1. Account Info" << endl;
	cout << "2. Balance" << endl;
	cout << "3. Deposit" << endl;
	cout << "4. Withdraw" << endl;
	cout << "5. Exit" << endl;
}
//Balance function for step 2
void balancefunc(int balance) {
	//There is use of simple if else statement
	if (balance > 1000) {
		cout << "Balance is: " << balance << endl;
	}
	else
	{
		cout << "Low Balance" << endl;
		cout << "Balance is: " << balance << endl;
	}
					
}

//Deposit function for step 3
int deposit(int balance) {
	int amount;
	cout << "Enter the amount: ";
	cin >> amount;
	//Following if statement is used for validating the input that it is positve
	//if not positive the user is asked again
	if (amount < 0)
	{
		cout << "Invalid Amount"<<endl;
		cout << "Enter the amount again: ";
		cin >> amount;
	}
	if (amount > 0)
	{
		balance = balance + amount;
		cout << "Balance is updated"<<endl;
		cout << "New Balance = " << balance << endl;
		return balance;
	}
	else
	{
		cout << "Balance is not updated"<<endl;
		return balance;
	}
	/*while (amount < 0 && count < 2) {
		cout << "Enter the amount: ";
		cin >> amount;
		if (amount < 0) {
			cout << "Invaild amount" << endl;
		}
		count++;
	}*/
	/*cout << "Enter the amount: ";
	cin >> amount;
	if (amount < 0)
	{
		cout << "Invaild amount"<<endl;
		cout << "Enter the amount: ";
		cin >> amount;
		if (amount > 0)
		{
			cout << "Invaild amount again" << endl;
			return balance;
		}

	}*/

	/*return amount >= 0 ? amount + balance : balance;*/
	
}


//Withdraw function for step 4
int withdraw(int balance) {
	int amount, tax,c=0;
	cout << "Enter the amount: ";
	cin >> amount;
	//I have used count variable so it asks for the value only two times.
	while (amount % 500 != 0  && c<2)
	{
		cout << "Enter amount again in multiples of 5 "<<endl;
		cin >> amount;
		if (amount % 500 == 0)
		{
			break;
		}
		c++;
	}

	if (amount > balance && amount%500==0)
	{
		cout << "Insufficient Balance "<<endl;
		cout << "Enter the amount again " << endl;
		cin >> amount;
	}
	//The following if will run if user has input a sufficent amount and in multiples of 5
	//meaning both the required conditions of questions are fulfilled.
	if (amount < balance && amount%500==0)
	{
		cout << "Please collect your cash "<<endl;
		balance=balance-amount;
		if (amount <= 3999)
		{
			return balance;
		}
		if (amount > 3999 && amount<=5999)
		{
			tax = (5.3 * balance) / 100;
			return	balance = balance - tax;
		}
		if (amount > 5999 && amount<=9999)
		{
			tax = (6.8 * balance) / 100;
			return balance = balance - tax;
		}
		if (amount > 9999)
		{
			tax = (8.4 * balance) / 100;
			return balance = balance - tax;
		}
			
	}
	else
	{
		cout << "Insufficient Balance" << endl;
		return balance;
	}
}

//Exit Funtions for step 5.
void exit(int balance, int checkbalance) {
	cout << "Thank You for Using FAST Banking" << endl;
	if (balance == checkbalance)
	{
		cout << "Kanjooos Insaan!" << endl;
	}
	else
	{
		cout << "Tmhara Grade Paka ha" << endl;
	}
}

int main()
{
	srand(time(0));
	int id,balance=25000,choice,checkbalance;
	string name="fasi", accounttype="defualt";
	//STEP 0
	/*cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your ID: ";
	cin >> id;
	cout << "Enter your balance in account: ";
	cin >> balance;
	cout << "Enter your account type: ";
	cin >> accounttype;*/
	checkbalance = balance;
	id = rand();
	

	do {
		//This function will clear the screen
		system("cls");
		//This is the function for menu which will appear in every iteration of loop
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		//STEP 1--Account Info
		if (choice == 1)
		{
			cout << "Account Info " << endl;
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
			cout << "Balance: " << balance << endl;
			cout << "Account Type:" << accounttype << endl;

		}
		//STEP 2--Balance
		if (choice == 2)
		{
			balancefunc(balance);
			
		}
		//Step 3--Deposit
		if (choice == 3)
		{
			balance = deposit(balance);
			
			/*cout << "New Balance = " << balance<<endl;*/
		}
		//Step 4--Withdraw
		if (choice == 4)
		{
			balance = withdraw(balance);
		}
		if (choice == 5)
		{
			exit(balance, checkbalance);
			break;
		}
		//After the performing the required function the compiler will read the following
		//function and will wait for the user to press enter to continue.
		//If i donot use the following fuction the program doesnot stop and next iteration start 
		//which clears the screen.
		system("pause");
	} while (1);//I have put an infinite conditon so that the loop will only end when
	//user press 5 for exit.
	
}

