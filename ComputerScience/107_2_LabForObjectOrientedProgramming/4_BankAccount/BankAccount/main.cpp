#include "BankAccount.h"
int main() {
	BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
	cout << BankAccount::getAllMoneyInBank() << endl;
	for (int i = 0; i < 4; i++)
	{
		bankAccount2.save(BankAccount::getAllMoneyInBank());
	}
	cout << bankAccount1.getBalance() << endl;
	cout << bankAccount2.getBalance() << endl;
	cout << bankAccount3.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	system("pause");
	return 0;
}