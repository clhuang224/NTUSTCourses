#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;
void insertData(vector<StRec>&, string, string, string);
int searchData(vector<StRec>, string, string, string);
void deleteData(vector<StRec>&, string, string, string);
void printData(vector<StRec>);
bool inputCheck(string, string, string);

// Intent: 讓使用者輸入、印出、刪除、尋找學生資料
// Pre: 選擇功能、學生姓名及電話
// Post: 依據所選擇的功能更新資料或印出結果
int main() {
	vector<StRec> studentRecord(0);
	string command;
	string firstName;
	string lastName;
	string phone;
	while (!cin.eof()) {
		// 輸入功能指令
		cin >> command;

		// Print
		if (command == "print")
		{
			printData(studentRecord);
		}
		// Insert
		else if (command == "insert")
		{
			cin >> firstName >> lastName >> phone;
			if (inputCheck(firstName, lastName, phone))
			{
				insertData(studentRecord, firstName, lastName, phone);
			}
		}
		// Search
		else if (command == "search")
		{
			cin >> firstName >> lastName >> phone;
			if (inputCheck(firstName, lastName, phone))
			{
				int result = searchData(studentRecord, firstName, lastName, phone);
				if (result != -1)
				{
					cout << result << endl;
				}
			}
		}
		// Delete
		else if (command == "delete")
		{
			cin >> firstName >> lastName >> phone;
			if (inputCheck(firstName, lastName, phone))
			{
				deleteData(studentRecord, firstName, lastName, phone);
			}
		}
		// 輸入錯誤指令
		else
		{
			cout << "Input Error" << endl;
		}
	}
}
// Intent: 檢查輸入資料是否符合規範
// Pre: 學生姓名及電話
// Post: 回傳布林值；不符規範時會印出錯誤訊息
bool inputCheck(string firstName, string lastName, string phone)
{
	// 檢查電話均為數字
	for (int i = 0; i < phone.length(); i++)
	{
		if (phone[i] < 48 || phone[i]>57)
		{
			cout << "Input Error" << endl;
			return false;
		}
	}
	// 檢查各項資料長度在規範以內
	if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15)
	{
		cout << "Input Error" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

// Intent: 將學生資料加入陣列
// Pre: 陣列、學生姓名及電話
// Post: 更新陣列；陣列已滿或已有相同資料時會印出錯誤訊息
void insertData(vector<StRec>& studentRecord, string firstName, string lastName, string phone) {

	// 檢查是否已達數量上限
	if (studentRecord.size() == 10)
	{
		cout << "Insert Error" << endl;
		return;
	}
	// 檢查有無相同資料
	for (int i = 0; i < studentRecord.size(); i++)
	{
		if (firstName == studentRecord[i].firstName ||
			lastName == studentRecord[i].lastName ||
			phone == studentRecord[i].phone)
		{
			cout << "Insert Error" << endl;
			return;
		}
	}
	// 將資料放入陣列中
	StRec current = { "", "", "" };
	for (int i = 0; i < firstName.length(); i++)
	{
		current.firstName[i] = firstName[i];
	}
	current.firstName[firstName.length()] = '\0';
	for (int i = 0; i < lastName.length(); i++)
	{
		current.lastName[i] = lastName[i];
	}
	current.lastName[lastName.length()] = '\0';
	for (int i = 0; i < phone.length(); i++)
	{
		current.phone[i] = phone[i];
	}
	current.phone[phone.length()] = '\0';
	studentRecord.push_back(current);

}

// Intent: 查詢學生資料在陣列中的位置
// Pre: 陣列、學生姓名及電話
// Post: 回傳index；不存在資料時會印出錯誤訊息並回傳-1
int searchData(vector<StRec> studentRecord, string firstName, string lastName, string phone) {
	// 尋找相符資料
	for (int i = 0; i < studentRecord.size(); i++)
	{
		if (firstName == studentRecord[i].firstName &&
			lastName == studentRecord[i].lastName &&
			phone == studentRecord[i].phone)
		{
			return i;
		}
	}
	// 無相符資料
	cout << "Search Error" << endl;
	return -1;
}

// Intent: 刪除指定資料
// Pre: 陣列、學生姓名及電話
// Post: 更新陣列；不存在資料時會印出錯誤訊息
void deleteData(vector<StRec>& studentRecord, string firstName, string lastName, string phone) {
	// 尋找相符資料
	for (int i = 0; i < studentRecord.size(); i++)
	{
		if (firstName == studentRecord[i].firstName &&
			lastName == studentRecord[i].lastName &&
			phone == studentRecord[i].phone)
		{
			// 刪除資料
			studentRecord.erase(studentRecord.begin() + i);
			return;
		}
	}
	// 無相符資料
	cout << "Delete Error" << endl;
}

// Intent: 印出所有學生資料
// Pre: 陣列、學生姓名及電話
// Post: 印出所有學生資料
void printData(vector<StRec> studentRecord) {
	// 無資料
	if (studentRecord.empty())
	{
		cout << "Print Error" << endl;
	}
	// 有資料
	else
	{
		for (StRec data : studentRecord)
		{
			cout << data.firstName << " " << data.lastName << " " << data.phone << endl;
		}
	}

}