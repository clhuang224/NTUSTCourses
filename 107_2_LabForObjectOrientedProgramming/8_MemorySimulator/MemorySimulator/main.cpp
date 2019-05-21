#include <iostream>
#include <string>
#include <vector>
using namespace std;
void runCommand(vector<long long>&, string);
void setString(vector<long long>&, int);
void setChar(vector<long long>&, int);
void setShort(vector<long long>&, int);
void setInt(vector<long long>&, int);
void getString(vector<long long>, int);
void getChar(vector<long long>, int);
void getShort(vector<long long>, int);
void getInt(vector<long long>, int);
int main() {
    unsigned memorySize, commandAmount = 0;
    cin >> memorySize;
    while (!cin.eof())
    {
        cin >> commandAmount;
        vector<long long> memory(memorySize, 0);
        for (unsigned i = 0; i < commandAmount; i++)
        {
            string command;
            cin >> command;
            runCommand(memory, command);
        }
    }
}

// Intent: 針對記憶體執行指令
// Pre: 陣列位置、Set或Get字串
// Post: 陣列被改變
void runCommand(vector<long long>& memory, string command)
{
    if (command == "Set")
    {
        int address;
        string type;
        cin >> address >> type;
        if (type == "String")
        {
            setString(memory, address);
        }
        else if (type == "char")
        {
            setChar(memory, address);
        }
        else if (type == "short")
        {
            setShort(memory, address);
        }
        else if (type == "int")
        {
            setInt(memory, address);
        }
    }
    else if (command == "Get")
    {
        int address;
        string type;
        cin >> address >> type;
        if (type == "String")
        {
            getString(memory, address);
        }
        else if (type == "char")
        {
            getChar(memory, address);
        }
        else if (type == "short")
        {
            getShort(memory, address);
        }
        else if (type == "int")
        {
            getInt(memory, address);
        }
    }
}

// Intent: 存入字串
// Pre: 陣列位置、指標
// Post: 陣列被改變
void setString(vector<long long>& memory, int address)
{
    string value;
    cin >> value;

    for (unsigned i = 0; i < value.length(); i++)
    {
        if (address < 0 || address + i> memory.size() - 1)
        {
            cout << "Violation Access." << endl;
            i += value.length();
        }
        else
        {
            memory[static_cast<unsigned>(address) + i] = static_cast<long long>(value[i]);
        }
    }

}

// Intent: 存入0-255的數字
// Pre: 陣列位置、指標
// Post: 陣列被改變
void setChar(vector<long long>& memory, int address)
{
    int value;
    cin >> value;
    if (address < 0 || static_cast<unsigned>(address) > memory.size() - 1)
    {
        cout << "Violation Access." << endl;
    }
    else
    {
        memory[static_cast<unsigned>(address)] = value;
    }
}

// Intent: 存入0-65536的數字
// Pre: 陣列位置、指標
// Post: 陣列被改變
void setShort(vector<long long>& memory, int address)
{
    int input;
    cin >> input;
    vector<long long> value(0);
    while (input > 0)
    {
        value.push_back(input % 256);
        input /= 256;
    }
    for (unsigned i = 0; i < value.size(); i++)
    {
        if (address < 0 || address + i> memory.size() - 1)
        {
            cout << "Violation Access." << endl;
            i += value.size();
        }
        else
        {
            memory[static_cast<unsigned>(address) + i] = static_cast<int>(value[i]);
        }
    }
}

// Intent: 存入0-4294967295的數字
// Pre: 陣列位置、指標
// Post: 陣列被改變
void setInt(vector<long long>& memory, int address)
{
    long long input;
    cin >> input;
    vector<long long> value;
    while (input > 0)
    {
        value.push_back(input % 256);
        input /= 256;
    }
    for (unsigned i = 0; i < value.size(); i++)
    {
        if (address < 0 || address + i > memory.size() - 1)
        {
            cout << "Violation Access." << endl;
            i += value.size();
        }
        else
        {
            memory[static_cast<unsigned>(address) + i] = value[i];
        }
    }

}

// Intent: 以String的格式印出資料
// Pre: 陣列位置、指標
// Post: 印出資料
void getString(vector<long long> memory, int address)
{
    if (address < 0)
    {
        cout << "Violation Access." << endl;
    }
    else
    {
        for (unsigned i = static_cast<unsigned>(address); i < memory.size() && memory[i] != 0; i++)
        {
            if (i > memory.size() - 1)
            {
                cout << "Violation Access." << endl;
                i += memory.size();
            }
            else
            {
                cout << static_cast<char>(memory[i]);
            }

        }
        cout << endl;
    }

}

// Intent: 印出一格資料
// Pre: 陣列位置、指標
// Post: 印出資料
void getChar(vector<long long> memory, int address)
{
    if (address < 0 || static_cast<unsigned>(address) > memory.size() - 1)
    {
        cout << "Violation Access." << endl;
    }
    else
    {
        cout << memory[address] << endl;
    }
}

// Intent: 以short的方式印出兩格資料
// Pre: 陣列位置、指標
// Post: 印出資料
void getShort(vector<long long> memory, int address)
{
    if (address < 0 || static_cast<unsigned>(address) + 2 > memory.size() - 1)
    {
        cout << "Violation Access." << endl;
    }
    else
    {
        cout << memory[address] + memory[address + 1] * 256 << endl;
    }
}

// Intent: 以int的方式印出兩格資料
// Pre: 陣列位置、指標
// Post: 印出資料
void getInt(vector<long long> memory, int address)
{
    if (address < 0 || static_cast<unsigned>(address) + 4 > memory.size() - 1)
    {
        cout << "Violation Access." << endl;
    }
    else
    {
        cout << memory[address] + memory[address + 1] * 256 + memory[address + 1] * 256 * 256 + memory[address + 1] * 256 * 256 * 256 << endl;
    }
}