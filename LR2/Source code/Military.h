/*!
	\file
	\brief Заголовочный файл с описанием военнослужащего.

	Данный файл содержит в себе определение класса военнаслужащего.
*/
#ifndef MILITARY_H
#define MILITARY_H

#include <string>
using std::string, std::to_string;

/*!
	\brief Класс, содержащий данные о служащем воинского полка.

	Данный класс содержит ФИО, звание, номер роты, возраст военнослужащего. 
*/
class Military{
public:
	string full_name; ///< ФИО
	int rank; ///< Звание
	int company_number; ///< Номер роты
	int age; ///< Возраст
	
public:
	Military() : full_name(""), rank(0), company_number(0), age(0) {} ///< Конструктор умолчания
	
	/*!
	\brief Конструктор копирования
	\param[in] obj2 Объект, которым инициализирующий текущий объект
	*/
	Military(const Military &obj2) : full_name(obj2.full_name), rank(obj2.rank), company_number(obj2.company_number), age(obj2.age) {}
	~Military(){} ///< Деструктор
	
	/*!
	\brief Конструктор с параметрами
	\param[in] name ФИО военнослужащего
	\param[in] str_rank Звание
	\param[in] num Номер роты
	\param[in] agee Возраст
	*/
	Military(const string& name, const string& str_rank, const int& num, const int& agee);
	
	/*!
	\brief Перегруженный оператор >
	
	Сравнение выполняется по полям: звание, ФИО, номер роты.	
	\param[in] obj2 Объект, c которым сравнивается текущий объект
	\return Результат сравнения на >
	*/
	bool operator>(Military obj2);
	
	/*!
	\brief Перегруженный оператор <
	
	Сравнение выполняется по полям: звание, ФИО, номер роты.	
	\param[in] obj2 Объект, c которым сравнивается текущий объект
	\return Результат сравнения на <
	*/
	bool operator<(Military obj2);
	
	/*!
	\brief Перегруженный оператор >=
	
	Сравнение выполняется по званиям.
	\param[in] obj2 Объект, c которым сравнивается текущий объект
	\return Результат сравнения на >=
	*/
	bool operator>=(Military obj2);
	
	/*!
	\brief Перегруженный оператор <=
	
	Сравнение выполняется по званиям.
	\param[in] obj2 Объект, c которым сравнивается текущий объект
	\return Результат сравнения на <=
	*/
	bool operator<=(Military obj2);
	
	/*!
	\brief Метод для получения строки, содержащей поля класса
	
	Полученные строки нужны для записи в выходной файл.
	\return Строка, содержщая ФИО, звание, номер роты, возраст.
	*/
	string getData() const; // Для записи 
	
	/*!
	\brief Метод для получения ФИО
	
	\return Строка, содержщая ФИО.
	*/
	string getFullName() const{ return full_name; }
};

#endif
