#include <iostream>
#include <windows.h>
#include <string>
#include <format>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>


#include "StructTypes.h"
#include "Classses.h"
#include "agregate.h"



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ofstream fout;
	ifstream fin;
	agregate K;
	int choice(0);
	while (true) {
		system("cls"); //Для очистки экрана 
		cout << "Программа для обработки файлов Садоводческих участков\n";
		cout << "\nМеню функций:\n";
		cout << "1.   Ввод информации с клавиатуры\n";
		cout << "2.   Просмотр существующего массива данных\n";
		cout << "3.   Удаление строки \n";
		cout << "4.   Вывод БД из файла\n";
		cout << "5.   Редактирование записи в базе данных\n";
		cout << "6.   Сохранить массив в файл\n";
		cout << "7.   Сортировка массива по цене\n";
		cout << "8.   Сортировка массива по имени владельца в алфавитном порядке\n";
		cout << "9.   Сортировка массива по названию товарищества и имени владельца\n";
		cout << "------------------------Перечень------------------------------------\n";
		cout << "10.   Создание перечня\n";
		cout << "11.   Вывод перечня на экран\n";
		cout << "12.   Сортировка перечня в алфавитном порядке\n";
		cout << "13.   Сортировка перечня по возрастанию\n";
		cout << "14.   Сохранения перечня в файл\n";
		cout << "------------------------Поиск по цене--------------------------------\n";
		cout << "15.   Поиск в масcиве участков цена которых превышает заданную\n";
		cout << "16.   Вывод результатов поиска\n";
		cout << "17.   Сортировка поиска в алфавитном порядке\n";
		cout << "18.   Сортировка поиска по возрастанию цены\n";
		cout << "19.   Сохранения поиска в файл\n";
		cout << "------------------------Проверка конструкторов-------------------------------------------------\n";
		cout << "20.  Проверка конструктора копирования\n";
		cout << "21   Проверка оператора присваивания\n";
		cout << "-------------------------------------------------------------------------\n";
		cout << "22.  Выход из программы\n";
		cout << "\nВаш выбор: "; cin >> choice; cout << "\n";
		if (cin.fail()) {
			cin.clear();
			string s;
			cin >> s;
			cout << "Это не пункт меню\n";
			system("pause");
			continue;
		}
		switch (choice) {
		case 1:
			K.InputMasInfo();
			system("pause");
			break;
		case 2:
			K.outputMasInfo();
			system("pause");
			break;
		case 3:
			K.deleteInfo();
			system("pause");
			break;
		case 4:
			K.inputFile();
			system("pause");
			break;
		case 5:
			K.correctMasInfo();
			system("pause");
			break;
		case 6:
			K.outputMasInfoFile();
			system("pause");
			break;
		case 7:
			K.sortPriceA();
			system("pause");
			break;
		case 8:
			K.sortOwnerA();
			system("pause");
			break;
		case 9:
			K.sortStructA();
			system("pause");
			break;
		case 10:
			K.makePerechA();
			system("pause");
			break;
		case 11: {
			K.outputPerech();
			system("pause");
			break;
		}
		case 12:
			K.sortPerechName();
			system("pause");
			break;
		case 13:
			K.sortPerechCount();
			system("pause");
			break;
		case 14:
			K.outputPerechFile();
				system("pause");
			break;
		case 15:
			K.findPrice();
			system("pause");
			break;
		case 16:
			K.outputFind();
			system("pause");
			break;
		case 17:
			K.sortFindNa();
			system("pause");
			break;
		case 18:
			K.sortFindPr();
			system("pause");
			break;
		case 19:
			K.outputFindFile();
			system("pause");
			break;
		case 20:
		{
			agregate b(K);
			cout << "ДО\n\n";
			cout << b << K;
			b.sortPriceA();
			b.sortPerechName();
			b.sortFindNa();
			cout << "ПОСЛЕ\n\n";
			cout << b << K;
			system("pause");
			break;
		}
		case 21:
		{
			agregate b, c;   c = b = K;
			cout << "ДО\n\n";
			cout << c << b << K;
			c.sortPriceA();
			c.sortPerechName();
			c.sortFindNa();
			cout << "ПОСЛЕ\n\n";
			cout << c << b << K;
		}
		case 22:
			cout << "\nКонец работы\n";
			system("pause");
			return 1;
		default: {
			cout << "Неверная команда\n";
			system("pause");
			break;
		}
		}
	}
	cout << "Конец работы\n";
	return 1;
}
