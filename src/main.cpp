#include <iostream>
#include <windows.h>
#include <string>
#include <format>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

#include "plot.h"
#include "plot_search.h"


int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	ifstream fin;
	PlotSearch C;
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
			C.inputMasInfo();
			system("pause");
			break;
		case 2:
			cout << (PlotArray&)C;
			system("pause");
			break;
		case 3:
			C.delInfo();
			system("pause");
			break;
		case 4:
			fin >> (PlotArray&)C;
			system("pause");
			break;
		case 5:
			C.correctInfo();
			system("pause");
			break;
		case 6:
		{
			ofstream fout;
			fout << (PlotArray&)C;
			system("pause");
			break;
		}
		case 7:
			C.sortPrice();
			system("pause");
			break;
		case 8:
			C.sortOwner();
			system("pause");
			break;
		case 9:
			C.sortStruct();
			system("pause");
			break;
		case 10:
			C.makePerech();
			system("pause");
			break;
		case 11:
			cout << (PlotSummary&)C;
			system("pause");
			break;
		case 12:
			C.sortName();
			system("pause");
			break;
		case 13:
			C.sortCount();
			system("pause");
			break;
		case 14:
		{
			ofstream fout;
			fout << (PlotSummary&)C;
			system("pause");
			break;
		}
		case 15:
			C.findPr();
			system("pause");
			break;
		case 16:
			cout << C;
			system("pause");
			break;
		case 17:
			C.sortNa();
			system("pause");
			break;
		case 18:
			C.sortPr();
			system("pause");
			break;
		case 19:
		{
			ofstream fout;
			fout << C;
			system("pause");
			break;
		}
		case 20: {
			PlotSearch b(C);
			cout << "Исходные\n";
			cout << (PlotArray&)C << (PlotSummary&)C << (PlotSearch&)C;
			cout << "Копии:\n";
			cout << (PlotArray&)b << (PlotSummary&)b << (PlotSearch&)b;
			system("pause");
			break;
		}
		case 21:
		{
			PlotSearch a, b;
			a = b = C;
			cout << "Исходные\n";
			cout << (PlotArray&)C << (PlotSummary&)C << (PlotSearch&)C;
			cout << "Копия 1:\n";
			cout << (PlotArray&)b << (PlotSummary&)b << (PlotSearch&)b;
			cout << "Копия 2:\n";
			cout << (PlotArray&)b << (PlotSummary&)b << (PlotSearch&)b;
			system("pause");
			break;
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
