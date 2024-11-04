#include <iostream>
#include <string>
#include <map>
#include "mainConnection.h"

void examination();

int main()
{
    setlocale(LC_ALL, "ru");

    std::string input;
    std::map<std::string, int> command;

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
        case 1:
            std::cout << "Добавление книги" << std::endl;
            break;
        case 2:
            std::cout << "Удаление книги" << std::endl;
            break;
        case 3:
            std::cout << "Просмотр всех книг" << std::endl;
            break;
        case 4:
            std::cout << "Очистка списка книг" << std::endl;
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