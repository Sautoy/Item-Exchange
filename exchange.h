#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>

using namespace std;

struct item {
	char itemName[50];
	char ownerName[50];

	item(const char* iN = NULL, const char* oN = NULL) {
		strcpy_s(itemName, iN);
		strcpy_s(ownerName, oN);
	}
	item(const item& it) {
		strcpy_s(itemName, it.itemName);
		strcpy_s(ownerName, it.ownerName);
	}
	~item() {}

};

class itemList
{
private:

	vector<item> list;

	public:

		item& operator[] (int index) {
			return list[index];
		}

		int size() {
			return list.size();
		}

		void tip() {
			cout << "欢迎使用“你帮我助”物品交换软件！" << endl;
			cout << "添加物品信息请输入1" << endl;
			cout << "删除物品信息请输入2" << endl;
			cout << "显示物品列表请输入3" << endl;
			cout << "查找物品信息请输入4" << endl;
			cout << "退出请输入5" << endl;
		}
		
		//直接添加物品，无用户交互，仅用于在用户操作之前从userdata.txt中读取之前储存的数据
		void AddItemDirectly(const item tmp) {
			list.push_back(tmp);
		}
		
		//添加物品，含用户使用提示
		void AddItem() {
			char tmpItemName[50];
			char tmpOwnerName[50];

			cout << "请输入要添加的物品名称:" << endl;
			cin >> tmpItemName;
			cout << "请输入该物品的物主姓名:" << endl;
			cin >> tmpOwnerName;

			item tmp(tmpItemName, tmpOwnerName);
			list.push_back(tmp);
			cout << "物品信息添加成功！" << endl;
		}

		//删除物品：当列表中有多件符合要求的物品时，只能删除最靠前的一件物品
		void DeleteItem() {
			char tmpItemName[50];
			char tmpOwnerName[50];

			cout << "请输入要删除的物品名称:" << endl;
			cin >> tmpItemName;
			cout << "请输入该物品的物主姓名:" << endl;
			cin >> tmpOwnerName;

			vector<item>::iterator it;
			int index = 0;
			bool flag = false;

			for (it = list.begin(); it != list.end(); it++, index++)
			{
				if (strcmp(list[index].itemName, tmpItemName) == 0 
					&& strcmp(list[index].ownerName, tmpOwnerName) == 0)
				{
					list.erase(it);
					flag = true;
					break;
				}
			}

			if(flag) 
				cout << "物品信息删除成功！" << endl;
			else 
				cout << "未找到要删除的物品信息！" << endl;
		}

		void ShowItem() {
			vector<item>::iterator it;
			int number = 1;

			cout << left << setw(10) << "序号" << " " 
				<< left << setw(12) << "物品名称" << " " 
				<< left << setw(12) << "物主名称" << right << endl;
			for (it = list.begin(); it != list.end(); it++) 
			{
				cout << left << setw(10) << number << " "
					<< left << setw(12) << list[number - 1].itemName << " "
					<< left << setw(12) << list[number - 1].ownerName << right << endl;
				number++;
			}

			cout << "物品清单中共有" << number-1 << "条记录" << endl;
		}

		void SearchItem() {
			char tmpItemName[50];

			cout << "请输入要查找的物品名称:" << endl;
			cin >> tmpItemName;

			vector<item>::iterator it;
			int index = 0;
			int number = 0;

			cout << left << setw(10) << "序号" << " "
				<< left << setw(12) << "物品名称" << " "
				<< left << setw(12) << "物主名称" << right << endl;
			
			//遍历寻找
			for (it = list.begin(); it != list.end(); it++,index++)
				if (strcmp(list[index].itemName, tmpItemName) == 0) {
					number++;
					cout << left << setw(10) << number << " "
						<< left << setw(12) << list[index].itemName << " "
						<< left << setw(12) << list[index].ownerName << right << endl;
				}
			
			cout << "共找到" << number << "条符合要求的物品信息" << endl;
		}

};
