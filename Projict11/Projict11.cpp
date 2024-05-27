#pragma warning(disable : 4996)

#pragma once

#include <iostream>
#include <string>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include<iomanip>

using namespace std;
void ReadeClientInfo(clsBankClient &Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter lastName: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\n Enter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void UpdateCLient()
{
	string AccountNumber = "";
	cout << "\nPlease Enter Client Account Number: " << endl;
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount Number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\n\nUpdate Client Info: ";
	cout << "\n______________________________\n";
	ReadeClientInfo(Client1);

	clsBankClient::enSaveResults SaveResult;
	SaveResult = Client1.Save();
	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:
	{
		cout << "\nAccount Updated Successfully :-)\n";
		Client1.Print();
		break;
	}
	case clsBankClient::enSaveResults::svFaildEmptyObject:
	{
		cout << "\nAccount Updated was not saved because it's Empty";
		break;
	}
	
	}

}


void AddNewClient()
{
	cout << "\nPlease Enter Account Number: ";
	string AccountNumber = clsInputValidate::ReadString();
	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount Number Is Already Used, Choose another one: ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient NewCLient = clsBankClient::GetAddNewClientObject(AccountNumber);
	ReadeClientInfo(NewCLient);
	clsBankClient::enSaveResults SaveResult;
	SaveResult = NewCLient.Save();
	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:
	{
		cout << "\nAccount Updated Successfully :-)\n";
		NewCLient.Print();
		break;
	}
	case clsBankClient::enSaveResults::svFaildEmptyObject:
	{
		cout << "\nAccount Updated was not saved because it's Empty";
		break;
	}
	case clsBankClient::enSaveResults::svFaildAccountNumberExists:
	{
		cout << "\nAccount Added Successfully :-)\n";
		NewCLient.Print();
		break;
	}
	}

}

int main()
{
	AddNewClient();
	system("pause>0");
	return 0;
}