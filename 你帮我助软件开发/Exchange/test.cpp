#include "exchange.h"
#include <iostream>
#include <fstream>

#pragma warning(disable:4996)；

using namespace std;

int main() 
{
	//将数据从userdata.txt中读取出来
	ifstream infile("userdata.txt", ios::in);
	if (!infile.is_open()) {
		cout << "文件打开失败！" << endl;
		exit(0);
	}

	itemList block;
	char tmpItemName[50];
	char tmpOwnerName[50];

	while (!infile.eof())
	{
		infile.getline(tmpItemName, 50, '\n');
		if (tmpItemName[0] == '\0') break;//针对userdata.txt存在空行的情况
		infile.getline(tmpOwnerName, 50, '\n');
		item tmp(tmpItemName, tmpOwnerName);
		block.AddItemDirectly(tmp);
	}

	block.tip();

	int selection = 0;
	while (selection != 5) {

		cout << "请输入你的选择：" << endl;
		cin >> selection;
		//排除非法输入
		while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5)
		{
			cout << "输入有误，请重新输入:" << endl;
			cin.clear();   //防止输入字符串导致cin被跳过造成死循环
			cin.ignore(100,'\n');
			cin >> selection;
		}

		switch (selection)
		{
		case 1: block.AddItem(); break;
		case 2: block.DeleteItem(); break;
		case 3: block.ShowItem(); break;
		case 4: block.SearchItem(); break;
		}
	}

	cout << "您已退出" << endl;

	//将数据保存到userdata.txt中
	ofstream outfile;
	outfile.open("userdata.txt", ios::in);

	int i = 0;
	while (i<block.size()) {
		outfile << block[i].itemName << "\n" ;
		outfile << block[i].ownerName << "\n";
		i++;
	}
	
	outfile.close();
	return 0;
}