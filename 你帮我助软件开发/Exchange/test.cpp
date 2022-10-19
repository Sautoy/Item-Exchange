#include "exchange.h"
#include <iostream>
#include <fstream>

#pragma warning(disable:4996)��

using namespace std;

int main() 
{
	//�����ݴ�userdata.txt�ж�ȡ����
	ifstream infile("userdata.txt", ios::in);
	if (!infile.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}

	itemList block;
	char tmpItemName[50];
	char tmpOwnerName[50];

	while (!infile.eof())
	{
		infile.getline(tmpItemName, 50, '\n');
		if (tmpItemName[0] == '\0') break;//���userdata.txt���ڿ��е����
		infile.getline(tmpOwnerName, 50, '\n');
		item tmp(tmpItemName, tmpOwnerName);
		block.AddItemDirectly(tmp);
	}

	block.tip();

	int selection = 0;
	while (selection != 5) {

		cout << "���������ѡ��" << endl;
		cin >> selection;
		//�ų��Ƿ�����
		while (selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5)
		{
			cout << "������������������:" << endl;
			cin.clear();   //��ֹ�����ַ�������cin�����������ѭ��
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

	cout << "�����˳�" << endl;

	//�����ݱ��浽userdata.txt��
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