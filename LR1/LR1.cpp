#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
using std::string, std::cout, std::cin, std::endl, std::getline, std::vector, std::to_string;
using std::chrono::steady_clock, std::chrono::duration_cast, std::chrono::microseconds, std::chrono::seconds, std::chrono::duration;


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
	string getData(); // Для записи 
};


Military::Military(const string& name, const string& str_rank, const int& num, const int& agee){
	full_name = name;
	company_number = num; 
	age = agee;
	
	if(str_rank == "Рядовой") rank = 0;
	else if(str_rank == "Младший сержант") rank = 1;
	else if(str_rank == "Сержант") rank = 2;
	else if(str_rank == "Старший сержант") rank = 3;
	else if(str_rank == "Старшина") rank = 4;
	else if(str_rank == "Прапорщик") rank = 5;
	else if(str_rank == "Старший прапорщик") rank = 6;
	else if(str_rank == "Младший лейтенант") rank = 7;
	else if(str_rank == "Лейтенант") rank = 8;
	else if(str_rank == "Старший лейтенант") rank = 9;
	else if(str_rank == "Капитан") rank = 10;
	else if(str_rank == "Майор") rank = 11;
	else if(str_rank == "Подполковник") rank = 12;
	else if(str_rank == "Полковник") rank = 13;
}
       
       
bool Military::operator>(Military obj2){
	if(rank > obj2.rank) return true;
	if(rank < obj2.rank) return false;
	
	// Звания =
	if(full_name > obj2.full_name) return true;
	if(full_name < obj2.full_name) return false;
	
	// Звания =, ФИО =
	if(company_number > obj2.company_number) return true;
	return false;
}

bool Military::operator<(Military obj2){
	if(rank < obj2.rank) return true;
	if(rank > obj2.rank) return false;
	
	// Звания =
	if(full_name < obj2.full_name) return true;
	if(full_name > obj2.full_name) return false;
	
	// Звания =, ФИО =
	if(company_number < obj2.company_number) return true;
	return false;
}

bool Military::operator>=(Military obj2){
	if(rank >= obj2.rank) return true;
	return false;
}

bool Military::operator<=(Military obj2){
	if(rank <= obj2.rank) return true;
	return false;
}


string Military::getData(){
	string str_rank;
	if(rank == 0) str_rank = "Рядовой";
	else if(rank == 1) str_rank = "Младший сержант";
	else if(rank == 2) str_rank = "Сержант";
	else if(rank == 3) str_rank = "Старший сержант";
	else if(rank == 4) str_rank = "Старшина";
	else if(rank == 5) str_rank = "Прапорщик";
	else if(rank == 6) str_rank = "Старший прапорщик";
	else if(rank == 7) str_rank = "Младший лейтенант";
	else if(rank == 8) str_rank = "Лейтенант";
	else if(rank == 9) str_rank = "Старший лейтенант";
	else if(rank == 10) str_rank = "Капитан";
	else if(rank == 11) str_rank = "Майор";
	else if(rank == 12) str_rank = "Подполковник";
	else if(rank == 13) str_rank = "Полковник";
	
	return full_name + ";" + str_rank + ";" + to_string(company_number) + ";" + to_string(age);
}



/*!
	\brief Выполняет сортировку выбором
	
	На итерации i выполняется цикл поиска индекса минимального элемента от i + 1 до конца массива. 
	Таким образом, среди элементов от i до конца массива найден минимальный, который идет "в начало" (в конец отсортированной части массива).
	
	\param[in,out] a Сортируемый массив
	\param[in] size Размер входного массива
*/
template<class T> 
void selectSort(T *a, const long &size){
	long i, j, ind_min;
	T min;
	for(i = 0; i < size - 1; i++){
		ind_min = i; // индекс минимального элемента от i + 1 до конца массива
		min = a[i];
		for(j = i + 1; j < size; j++){ // цикл поиска минимального элемента
			if(a[j] < min){ ind_min = j; min = a[j]; }
		}
		a[ind_min] = a[i]; a[i] = min; // меняем минимальный элемент и a[i]
	}
}

/*!
	\brief Выполняет cортировку простыми вставками
	
	Рассматриваются две части массива: отсортирвоанная (a[0]...a[i-1]) и неотсортированная. 
	Внутренним циклом выполняется сдвиг элементов вправо в отсортированной части массива. 
	Таким образом, освобождается позиция для вставляемого (текущего) элемента (пока выполняется условие того, что он меньше элементов отсортированной части массива). 
	Итого: в нужное место в этой части вставляется новый элемент.
	
	\param[in,out] a Сортируемый массив
	\param[in] size Размер входного массива
*/
template<class T> 
void insertSort(T *a, const long &size){
	long i, j;
	T inserted_elem;
	for(i = 0; i < size; i++){
		inserted_elem = a[i];
		
		for(j = i - 1; j >= 0 && inserted_elem < a[j]; j--) 
			a[j + 1] = a[j]; // сдвиг элементов вправо в отсортированной части массива, для освобождения места для вставляемого элемента (если выполнены условия)
		
		a[j + 1] = inserted_elem; // j + 1 - то самое место, где был последний сдвиг. Т.е. место для вставки элемента
	}
}

/*!
	\brief Выполняет просеивание элемента i пирамиды вниз
	
	Если текущий элемент не максимум из текущего элемента и двух потомков, то он свапается c максимумом и выполняется переход к максимуму.
	Иначе просеивание прекращается, ведь текущий изначально был максимальным.
	
	\param[in,out] heap Куча, в которой просеивается элемент
	\param[in] i Просеиваемый элемент (далее текущий элемент)
	\param[in] heap_size Размер входного массива (далее размер используемой кучи)
*/
template<class T> 
void sift(T* heap, int i, const int &heap_size){   
    int ind_max = i; // индекс старого максимума
    const T elem(heap[i]); // просеиваемый элемент
     
    while(true){
        i = ind_max; // индекс текущего элемента - индекс максимума, куда спускаемся на прошлой итерации
           
        int ind_child = 2 * i + 1; // индекс левого потомка
        if((ind_child < heap_size) && (heap[ind_child] > elem)) ind_max = ind_child; // если есть левый потомок и он больше текущего элемента, то он становится максимальным

        ind_child++; // индекс правого потомка
        if ((ind_child < heap_size) && (heap[ind_child] > heap[ind_max])) ind_max = ind_child; // если есть правый потомок и он больше максимума, то он становится максимальным

        
        if (i == ind_max) break; // если текущий элемент изначально был максимальным (т.е. нам некуда сеять элемент), то конец
       
        heap[i] = heap[ind_max]; // можем менять => свапаем текущий элемент и максимум
        heap[ind_max] = elem; // elem теперь лежит в ячейке, с которой будем работать на след. итерации
    }
}

/*!
	\brief Выполняет пирамидальную сортировку
	
	Сначала выполняется построение кучи просеиванием вниз нелистовых элементов (они имеют индексы от 0 до heap_size / 2 - 1).
	Пока имеет смысл выполнять сортировку (размер кучи > 1) выполняем следующие действия.
	Cвапается корень и последний элемент. Просеивается новый корень. Отделяется последний элемент.
	
	\param[in,out] heap Сортируемый массив (далее куча для пирамидальной сортировки)
	\param[in] heap_size Размер входного массива (далее размер используемой кучи)
*/
template<class T> 
void heapSort(T* heap, int heap_size){ // heap_size - изначально размер массива, далее - размер пирамиды
    for(int i = heap_size / 2 - 1; i >= 0; i--) sift(heap, i, heap_size); // Строим пирамиду: просеиваем вниз нелистовые элементы
   
    while(heap_size > 1){ // пока есть что сортировать
        heap_size--; // отделяем последний элемент

        const T root(heap[0]); // свапаем корень и последний элемент (отделяемый)
        heap[0] = heap[heap_size];
        heap[heap_size] = root;
       
        sift(heap, 0, heap_size); // просеиваем новый корень
    }
}


/*!
	\brief Тело программы
	
	Считывает данные о военнослужащих из файлов. Заполняет массивы военнослужащих, которые далее подлежат сортировке.
	Замеряется время работы сортировок, которое после добавляется в вектор времён. Записывает отсортированные массивы в файлы. 
*/
int main(){
	vector<double> select_time;
	vector<double> insert_time;
	vector<double> heap_time;
	for(auto& size : {100, 1000, 5000, 10000, 20000, 50000, 100000}){
		Military *a = new Military[size]; // 3 сортировки => 3 массива, чтоб время "чисто" мерить
		Military *b = new Military[size];
		Military *c = new Military[size];
		
		string file_in = "data" + to_string(size) + ".txt"; // Имя файла с данными
		std::ifstream in_stream(file_in);
		if(in_stream.is_open()){
		   	string full_name;
			string rank;
			string company_number; // номер роты
			string age;
			
			for(long i = 0; i < size; i++){  		
		   		getline(in_stream, full_name, ';');
		   		getline(in_stream, rank, ';');
		   		getline(in_stream, company_number, ';');
		   		getline(in_stream, age);
		   			
		   		a[i] = Military(full_name, rank, std::stoi(company_number), std::stoi(age));
		   		b[i] = Military(full_name, rank, std::stoi(company_number), std::stoi(age));
		   		c[i] = Military(full_name, rank, std::stoi(company_number), std::stoi(age));
		 	}
			in_stream.close();

			auto start1 = steady_clock::now();
			selectSort(a, size);
			auto end1 = steady_clock::now();
			duration<double> sec1 = end1 - start1;
			
			auto start2 = steady_clock::now();
			insertSort(b, size);
			auto end2 = steady_clock::now();
			duration<double> sec2 = end2 - start2;
			
			auto start3 = steady_clock::now();
			heapSort(c, size);
			auto end3 = steady_clock::now();
			duration<double> sec3 = end3 - start3;
			
			select_time.push_back(sec1.count());
			insert_time.push_back(sec2.count());
			heap_time.push_back(sec3.count());
			
			
			string file_out = "dataOut" + to_string(size) + ".txt";
			std::ofstream out_stream(file_out);
			
			if(out_stream.is_open()){
				for(long i = 0; i < size - 1; i++) out_stream << a[i].getData() << endl; 
				out_stream << a[size - 1].getData();
			}
			out_stream.close();
		
			delete [] a;
			delete [] b;
			delete [] c;
		}
	}
	
	for(auto& time : select_time) cout << time << " ";
	cout << endl;
	
	for(auto& time : insert_time) cout << time << " ";
	 cout << endl;
	
	for(auto& time : heap_time) cout << time << " ";
	 cout << endl;
	
    return 0;
}
