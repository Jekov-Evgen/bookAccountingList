#pragma once

#include "connect.h"


class DataBase
{
public:
	DataBase();

	void addBook(std::string, int, std::string);
	void delBook(std::string);
	void allBook();
	void clearDB();

private:
	int year;
	std::string author;
	std::string bookTitle;
};