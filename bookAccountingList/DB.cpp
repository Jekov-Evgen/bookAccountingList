#include "DB.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>

DataBase::DataBase() {
	try {
		std::fstream listOfData("DB.txt");

        listOfData.close();
	}
	catch (const std::exception&) {
		std::cerr << "������ �������� �����" << std::endl;
	}
}


void DataBase::addBook(std::string author, int year, std::string nameBook) {
	try {
		std::fstream listOfData("DB.txt", std::ios::out | std::ios::app);

		listOfData << "��������: " << nameBook << " ";
		listOfData << "�����: " << author << " ";
		listOfData << "��� �������: " << year << std::endl;

        listOfData.close();
	}
	catch (const std::exception&) {
        std::cerr << "������ �������� �����" << std::endl;
	}
}

void DataBase::allBook() {
	try {
		std::fstream listOfData("DB.txt", std::ios::in);
		std::string out;

		while (std::getline(listOfData, out)) {
			std::cout << out << std::endl;
		}

        listOfData.close();
	}
	catch (const std::exception&) {
		std::cerr << "������ �������� �����" << std::endl;
	}
}


void DataBase::delBook(std::string nameBook) {
    try {
        std::ifstream listOfData("DB.txt");
        if (!listOfData) {
            throw std::runtime_error("������ �������� ����� DB.txt ��� ������");
        }

        std::ofstream tempList("temporary.txt");
        if (!tempList) {
            throw std::runtime_error("������ �������� ����� temporary.txt ��� ������");
        }

        std::string temp;
        bool found = false;

        while (std::getline(listOfData, temp)) {
            if (temp.find(nameBook) == std::string::npos) {
                tempList << temp << std::endl;
            }
            else {
                found = true;
            }
        }

        listOfData.close();
        tempList.close();

        if (!found) {
            std::cerr << "����� �� ������� � ���� ������." << std::endl;
            std::remove("temporary.txt");
            return;
        }

        if (std::remove("DB.txt") != 0) {
            std::cerr << "������ �������� ������� ����� DB.txt" << std::endl;
            return;
        }

        if (std::rename("temporary.txt", "DB.txt") != 0) {
            std::cerr << "������ �������������� temporary.txt � DB.txt" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}