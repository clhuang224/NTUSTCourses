#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool drawS(vector<vector<char>>&);
bool drawT(vector<vector<char>>&);
bool drawL(vector<vector<char>>& draw, int x1, int y1, int x2, int y2);
// Intent: 讓使用者在特定區塊畫上形狀
// Pre: 設定畫布大小的兩個整數、指定形狀的字元及各個形狀的參數
// Post: 印出結果
int main() {

    // 設定畫布長寬
    unsigned m, n;
    cin >> m >> n;
    vector<vector<char>> draw(n, vector<char>(m, '*'));

    // 選擇輸入指令
    string type;
    cin >> type;
    while (type != "EXIT")
    {
        char choice = type[0];
        bool success = true;
        // 選擇形狀
        switch (choice)
        {
        case 'S':
            success = drawS(draw);
            break;
        case 'T':
            success = drawT(draw);
            break;
        case 'L':
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            success = drawL(draw, x1, y1, x2, y2);
            break;
        }
        // 若超出畫布大小，會顯示超出範圍
        if (success)
        {
            for (int i = 0; i < draw.size(); i++)
            {
                for (unsigned j = 0; j < draw[0].size(); j++)
                {

                    cout << draw[i][j];
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Out of range." << endl;
        }
        cout << endl;
        cin >> type;
    }
}
// Intent: 畫出方形
// Pre: 畫布的二維陣列
// Post: 修改陣列並回傳是否成功
bool drawS(vector<vector<char>>& draw) {
    int x, y, width;
    cin >> width >> x >> y;
    return drawL(draw, x, y, x + width - 1, y) && drawL(draw, x, y, x, y + width - 1) &&
        drawL(draw, x + width - 1, y, x + width - 1, y + width - 1) && drawL(draw, x, y + width - 1, x + width - 1, y + width - 1);
}

// Intent: 畫出線條
// Pre: 畫布的二維陣列及兩個頂點的座標
// Post: 修改陣列並回傳是否成功
bool drawL(vector<vector<char>>& draw, int x1, int y1, int x2, int y2) {
    if (x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 &&
        x1 < draw[0].size() && x2 < draw[0].size() && y1 < draw.size() && y2 < draw.size())
    {
        // ｜
        if (x1 == x2)
        {
            if (y1 > y2)
            {
                swap(y1, y2);
            }
            for (unsigned i = y1; i <= y2; i++)
            {
                draw[i][x1] = 'X';
            }
        }
        // －
        else if (y1 == y2)
        {
            if (x1 > x2)
            {
                swap(x1, x2);
            }
            for (unsigned i = x1; i <= x2; i++)
            {
                draw[y1][i] = 'X';
            }
        }
        else
        {
            int j = 0;
            if (x1 > x2)
            {
                swap(x1, x2);
                swap(y1, y2);
            }
            // ／
            if (y1 < y2)
            {
                for (int i = x1; i <= x2; i++)
                {
                    draw[y1 + j][i] = 'X';
                    j++;
                }
            }
            // ＼
            else
            {
                for (int i = x1; i <= x2; i++)
                {
                    draw[y1 - j][i] = 'X';
                    j++;
                }
            }

        }
        return true;
    }
    else
    {
        return false;
    }
}
// Intent: 畫出三角
// Pre: 畫布的二維陣列
// Post: 修改陣列並回傳是否成功
bool drawT(vector<vector<char>>& draw) {
    unsigned int x, y, width;
    string face;
    cin >> width >> x >> y >> face;
    if (face[0] == 'L')
    {
        // ←
        drawL(draw, x, y, x - width + 1, y);
        if (face[1] == 'U')
        {
            // ↑
            drawL(draw, x, y, x, y - width + 1);
            // ↙
            return drawL(draw, x, y - width + 1, x - width + 1, y);
        }
        else
        {
            // ↓
            drawL(draw, x, y, x, y + width - 1);
            // ↖
            return drawL(draw, x, y + width - 1, x - width + 1, y);
        }
    }
    else
    {
        // →
        drawL(draw, x, y, x + width - 1, y);
        if (face[1] == 'U')
        {
            // ↑
            drawL(draw, x, y, x, y - width + 1);
            // ↘
            return drawL(draw, x, y - width + 1, x + width - 1, y);
        }
        else
        {
            // ↓
            drawL(draw, x, y, x, y + width - 1);
            // ↗
            return drawL(draw, x, y + width - 1, x + width - 1, y);
        }
    }
}