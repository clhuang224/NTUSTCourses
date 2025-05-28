#include "BankAccount.h"

long BankAccount::allMoneyInBank = 0;

// Intent: 初始化
// Pre: 無
// Post: 初始化帳戶的餘額為0
BankAccount::BankAccount()
{
	balance = 0;
}

// Intent: 初始化
// Pre: 無
// Post: 初始化帳戶的餘額為x
BankAccount::BankAccount(long x)
{
	balance = x;
	allMoneyInBank += x;
}

// Intent: 存入帳戶
// Pre: BankAccount帳戶、long金額
// Post: 帳戶金額增加、銀行總額增加
void BankAccount::save(long x)
{
	balance += x;
	allMoneyInBank += x;
}

// Intent: 提出帳戶
// Pre: BankAccount帳戶、long金額
// Post: 帳戶金額減少、銀行總額減少
void BankAccount::withdraw(long x)
{
	balance -= x;
	allMoneyInBank -= x;
}

// Intent: 查看帳戶餘額
// Pre: BankAccount帳戶
// Post: 回傳餘額
long BankAccount::getBalance()
{
	return balance;
}

// Intent: 查看銀行總額
// Pre: BankAccount帳戶
// Post: 回傳銀行總額
long BankAccount::getAllMoneyInBank()
{
	return allMoneyInBank;
}