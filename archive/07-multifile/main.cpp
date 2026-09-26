#include <iostream>
#include <windows.h>
#include <string>
#include <format>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

#include "StructTypes.h"
#include "Classes.h"


int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ifstream fin;
	mas A, X;
	masB B, Z;
	masC C, Y;
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
		cout << "10.  Проверка конструктора копирования\n";
		cout << "11   Проверка оператора присваивания\n";
		cout << "------------------------Перечень------------------------------------\n";
		cout << "12.   Создание перечня\n";
		cout << "13.   Вывод перечня на экран\n";
		cout << "14.   Проверка конструктора копирования перечня\n";
		cout << "15.   Проверка оператора присваивания перечня\n";
		cout << "16.   Сортировка перечня в алфавитном порядке\n";
		cout << "17.   Сортировка перечня по возрастанию\n";
		cout << "18.   Сохранения перечня в файл\n";
		cout << "------------------------Поиск по цене--------------------------------\n";
		cout << "19.   Поиск в масcиве участков цена которых превышает заданную\n";
		cout << "20.   Вывод результатов поиска\n";
		cout << "21.   Проверка конструктора копирования поиска\n";
		cout << "22.   Проверка оператора присваивания поиска\n";
		cout << "23.   Сортировка поиска в алфавитном порядке\n";
		cout << "24.   Сортировка поиска по возрастанию цены\n";
		cout << "25.   Сохранения поиска в файл\n";
		cout << "-------------------------------------------------------------------------\n";
		cout << "26.  Выход из программы\n";
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
			A.inputMasInfo();
			system("pause");
			break;
		case 2:
			cout << A;
			system("pause");
			break;
		case 3:
			A.delInfo();
			system("pause");
			break;
		case 4:
			fin >> A;
			system("pause");
			break;
		case 5:
			A.correctInfo();
			system("pause");
			break;
		case 6:
		{
			ofstream fout;
			fout << A;
			system("pause");
			break;
		}
		case 7:
			A.sortPrice();
			system("pause");
			break;
		case 8:
			A.sortOwner();
			system("pause");
			break;
		case 9:
			A.sortStruct();
			system("pause");
			break;
		case 10: {
			mas X(A);
			cout << "Исходные массивы:\n";
			cout << A << X;
			X.sortOwner();
			cout << "Неизмененный массив\n\n";
			cout << A << "Измененный массив\n\n" << X;
			system("pause");
			break;
		}
		case 11: {
			mas f, d; f = d = A;
			cout << f << d << A;
			A.sortPrice();
			cout << f << d << A;
			system("pause");
			break;
		}
		case 12:
			makePerech(A, B);
			system("pause");
			break;
		case 13:
			cout << B;
			system("pause");
			break;
		case 14:
		{
			masB Z(B);
			cout << Z << B;
			Z.sortName();
			cout << Z << B;
			system("pause");
			break;
		}
		case 15:
		{
			masB q, w; q = w = B;
			cout << q << w << B;
			B.sortCount();
			cout << q << w << B;
			system("pause");
			break;
		}
		case 16:
			B.sortName();
			system("pause");
			break;
		case 17:
			B.sortCount();
			system("pause");
			break;
		case 18:
		{
			ofstream fout;
			fout << B;
			system("pause");
			break;
		}
		case 19:
			C.findPr(A);
			system("pause");
			break;
		case 20:
			cout << C;
			system("pause");
			break;
		case 21:
		{
			masC Y(C);
			cout << Y << C;
			Y.sortNa();
			cout << Y << C;
			system("pause");
			break;
		}
		case 22:
		{
			masC v, b;
			v = b = C;
			cout << v << b << C;
			v.sortPr();
			cout << v << b << C;
			system("pause");
			break;
		}
		case 23:
			C.sortNa();
			system("pause");
			break;
		case 24:
			C.sortPr();
			system("pause");
			break;
		case 25:
		{
			ofstream fout;
			fout << C;
			system("pause");
			break;
		}
		case 26:
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
