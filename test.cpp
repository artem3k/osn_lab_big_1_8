#include <iostream>
#include <string>
#include <clocale>
#include "Engineer.h"

using namespace std;

template <class T>
void pass(const string& name, T wait, T result){
    if(wait == result){
        cout << "Тест «" << name << "» завершился успешно\n";
    }else{
        cout << "Ошибка, результат выполнения метода «" << name << "»\n";
    }
}

int main(){
    //Русификация
    #ifdef _WIN32
        system("CHCP 65001"); // UTF-8
    #else
        setlocale(LC_ALL,"RUS");
    #endif

    cout << "Лабораторная работа номер 1.8 \n Круглый Артём Васильевич \n Гордиенко Максим Артёмов\n\n";
    cout << "Проверка класса Engineer\n";

    {
        Engineer engineer = Engineer();
        pass("False is_work", false,engineer.is_work());
    }
    {
        Engineer engineer = Engineer("1","1","1",1, true);
        pass("True is_work", true,engineer.is_work());
    }
    {
        Engineer engineer = Engineer();
        engineer.work("test");
        pass("work", true,engineer.is_work());
    }
    {
        Engineer engineer = Engineer("1","1","1",1, true);
        engineer.endWork();
        pass("endWork is end", false,engineer.is_work());
        pass("endWork plus completed_tasks", 2,engineer.completed_tasks);
    }

    return 0;
}