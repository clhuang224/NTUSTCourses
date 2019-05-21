#include "user.h"

namespace
{
    string username;

    // Intent: 驗證username是否符合規範
    // Pre: username字串
    // Post: 回傳真假值
    bool isValid()
    {
        if (username.length() == 8)
        {
            for (unsigned i = 0; i < username.length(); i++)
            {
                if ('z' < username[i] || username[i] < 'A')
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }

    }
}

namespace Authenticate
{
    void inputUserName()
    {
        do
        {
            cout << "Enter your username (8 letters only)" << endl;
            cin >> username;
        } while (!isValid());
    }

    string getUserName()
    {
        return username;
    }
}

