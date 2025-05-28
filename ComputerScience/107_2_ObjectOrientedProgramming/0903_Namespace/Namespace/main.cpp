#include <iostream>
#include "password.h"
#include "user.h"
using Authenticate::inputPassword;
using Authenticate::inputUserName;
using Authenticate::getPassword;
using Authenticate::getUserName;

int main()
{
	inputUserName();
	inputPassword();
	cout << "Your username is " << getUserName() <<
		" and your password is: " <<
		getPassword() << endl;

	system("pause");
	return 0;
}