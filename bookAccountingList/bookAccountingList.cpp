#include <iostream>
#include <string>
#include <map>
#include "mainConnection.h"

void examination();
int enteringTheYear();
std::string authorInput();
std::string enteringBookTitle();

int main()
{
    setlocale(LC_ALL, "ru");

    std::string input;
    std::map<std::string, int> command;
    DataBase storage;

    command["add"] = 1;
    command["del"] = 2;
    command["all"] = 3;
    command["clear"] = 4;

    std::cout << "Приветствуем в реестре учета книг, выберите действие(для просмотра команд наберите help): ";
    std::cin >> input;

    examination();

    do
    {
        if (input == "help") {
            std::cout << "Введите ваш запрос: ";
            std::cin >> input;
        }

        switch (command[input]) {
        case 1: {
            int year = enteringTheYear();
            std::string author = authorInput();
            std::string nameBook = enteringBookTitle();

            storage.addBook(author, year, nameBook);
            break;
        }
        case 2: {
            std::string nameBook = enteringBookTitle();

            storage.delBook(nameBook);

            break;
        }
        case 3:
            storage.allBook();
            break;
        case 4:
            storage.clearDB();
            break;
        default:
            std::cout << "Неверный ввод" << std::endl;
            break;
        }

        std::cout << "Введите следующий запрос: ";
        std::cin >> input;

        if (input == "help") {
            examination();
        }

    } while (input != "exit");
}

void examination() {
    std::cout << "Команды:" << std::endl;

    std::cout << "add(Добавить)" << std::endl;
    std::cout << "del(Удалить)" << std::endl;
    std::cout << "all(Просмотреть все)" << std::endl;
    std::cout << "clear(Очитска)" << std::endl;
    std::cout << "exit(Выход)" << std::endl;
    std::cout << "help(Список команд)" << std::endl;
}

int enteringTheYear()
{
    int y = 0;
    std::cout << "Введите год издания: ";
    std::cin >> y;

    return y;
}

std::string authorInput()
{
    std::string a = "";

    std::cout << "Введите автора: ";
    std::cin >> a;

    return a;
}

std::string enteringBookTitle()
{
    std::string nb = "";

    std::cout << "Введите книгу: ";
    std::cin >> nb;

    return nb;
}