#include"password.h"
namespace
{
    string password;

    // Intent: 驗證password是否符合規範
    // Pre: password字串
    // Post: 回傳真假值
    bool isValid()
    {
        if (password.length() >= 8)
        {
            for (unsigned i = 0; i < password.length(); i++)
            {
                if (password[i]<'A' || password[i]>'z')
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
}
namespace Authenticate
{
   
    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
                "and at least one non-letter)" << endl;
            cin >> password;
        } while (!isValid());
    }

    string getPassword()
    {
        return password;
    }
}

