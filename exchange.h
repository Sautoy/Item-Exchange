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
			cout << "��ӭʹ�á������������Ʒ���������" << endl;
			cout << "�����Ʒ��Ϣ������1" << endl;
			cout << "ɾ����Ʒ��Ϣ������2" << endl;
			cout << "��ʾ��Ʒ�б�������3" << endl;
			cout << "������Ʒ��Ϣ������4" << endl;
			cout << "�˳�������5" << endl;
		}

		void AddItemDirectly(const item tmp) {
			list.push_back(tmp);
		}

		void AddItem() {
			char tmpItemName[50];
			char tmpOwnerName[50];

			cout << "������Ҫ��ӵ���Ʒ����:" << endl;
			cin >> tmpItemName;
			cout << "���������Ʒ����������:" << endl;
			cin >> tmpOwnerName;

			item tmp(tmpItemName, tmpOwnerName);
			list.push_back(tmp);
			cout << "��Ʒ��Ϣ��ӳɹ���" << endl;
		}

		//���б����ж������Ҫ�����Ʒʱ��ֻ��ɾ���ǰ��һ����Ʒ
		void DeleteItem() {
			char tmpItemName[50];
			char tmpOwnerName[50];

			cout << "������Ҫɾ������Ʒ����:" << endl;
			cin >> tmpItemName;
			cout << "���������Ʒ����������:" << endl;
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
				cout << "��Ʒ��Ϣɾ���ɹ���" << endl;
			else 
				cout << "δ�ҵ�Ҫɾ������Ʒ��Ϣ��" << endl;
		}

		void ShowItem() {
			vector<item>::iterator it;
			int number = 1;

			cout << left << setw(10) << "���" << " " 
				<< left << setw(12) << "��Ʒ����" << " " 
				<< left << setw(12) << "��������" << right << endl;
			for (it = list.begin(); it != list.end(); it++) 
			{
				cout << left << setw(10) << number << " "
					<< left << setw(12) << list[number - 1].itemName << " "
					<< left << setw(12) << list[number - 1].ownerName << right << endl;
				number++;
			}

			cout << "��Ʒ�嵥�й���" << number-1 << "����¼" << endl;
		}

		void SearchItem() {
			char tmpItemName[50];

			cout << "������Ҫ���ҵ���Ʒ����:" << endl;
			cin >> tmpItemName;

			vector<item>::iterator it;
			int index = 0;
			int number = 0;

			cout << left << setw(10) << "���" << " "
				<< left << setw(12) << "��Ʒ����" << " "
				<< left << setw(12) << "��������" << right << endl;

			for (it = list.begin(); it != list.end(); it++,index++)
				if (strcmp(list[index].itemName, tmpItemName) == 0) {
					number++;
					cout << left << setw(10) << number << " "
						<< left << setw(12) << list[index].itemName << " "
						<< left << setw(12) << list[index].ownerName << right << endl;
				}
			
			cout << "���ҵ�" << number << "������Ҫ�����Ʒ��Ϣ" << endl;
		}

};
