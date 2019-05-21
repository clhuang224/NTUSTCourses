#include "HotDogStand.h"

unsigned int totalSlod = 0;

//Intent: 初始化店鋪資訊
//Pre: 無
//Post: 新建物件並初始化；更新總售出量
HotDogStand::HotDogStand(string newId, unsigned int newSold)
{
    id = newId;
    sold = newSold;
    totalSlod += sold;
}
//Intent: 模擬售出
//Pre: HotDogStand物件
//Post: 售出量、總售出量增加
void HotDogStand::justSold()
{
    sold++;
    totalSlod++;
}

//Intent: 取得售出量
//Pre: HotDogStand物件
//Post: 回傳售出量
unsigned int HotDogStand::thisStandSoldAmount()
{
    return sold;
}

//Intent: 取得總售出量
//Pre: 無
//Post: 回傳總售出量
unsigned int HotDogStand::allStandSoldAmount()
{
    return totalSlod;
}

//Intent: 印出店鋪id和售出量
//Pre: HotDogStand物件
//Post: 印出結果
void HotDogStand::print()
{
    cout << id << " " << sold << endl;
}