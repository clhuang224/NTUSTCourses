#pragma once
#include <iostream>
using namespace std;

class BankAccount
{
public:
	BankAccount();
	BankAccount(long x);
	void save(long x);
	void withdraw(long x);
	long getBalance();
	static long getAllMoneyInBank();
private:
	static long allMoneyInBank;
	long balance;
};

