/*!
	\file
	\brief Тело программы
	
	Считывает данные о военнослужащих из файлов. Заполняет бинарное дерево, красно-черное дерево, хеш-таблицу и multimap.
	Замеряет время поиска по ключу, которое после добавляется в вектор времён, выводимый на экран. Считает количество коллизий.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <map>

#include "BinTree.h"
#include "RBTree.h"
#include "HashTable.h"

using std::string, std::cout, std::cin, std::endl, std::getline, std::vector, std::to_string;
using std::chrono::steady_clock, std::chrono::duration_cast, std::chrono::microseconds, std::chrono::seconds, std::chrono::duration;

int main(){ // g++ main.cpp Military.h Military.cpp BinTree.h BinTree.cpp RBTree.h RBTree.cpp HashTable.h HashTable.cpp
	vector<double> binTreeTime;
	vector<double> rbTreeTime;
	vector<double> hashTableTime;
	vector<int> numberOfCollisions;
	
	vector<double> multiMapTime;
	
	std::map<int, string> m{{100, "Де Цыцык Енович"}, {1000, "Полозенко Мирбек Миннисламович"}, {5000, "Шишаков Алик Шакурович"}, 
		{10000, "Вторых Имамутдин Кязымович",}, {20000, "Биушкин Шахзод Джамбулатович", }, {50000, "Гречнев Миндаугас Винерович", }, {100000, "Швиндт Юрие Махмутович"}}; 
	
	for(auto& size : {100, 1000, 5000, 10000, 20000, 50000, 100000}){
		string file_in = "data" + to_string(size) + ".txt"; // Имя файла с данными
		std::ifstream in_stream(file_in);
		if(in_stream.is_open()){
		   	string full_name;
			string rank;
			string company_number; // номер роты
			string age;
			
			BinTree bintree;
			RBTree rbtree;
			HashTable htable(size);
			std::multimap<string, Military> mm;
			
			vector<unsigned int> hashes;
			int count = 0; // Число коллизий для текущего размера 
			
			for(unsigned int i = 0; i < size; i++){  		
		   		getline(in_stream, full_name, ';');
		   		getline(in_stream, rank, ';');
		   		getline(in_stream, company_number, ';');
		   		getline(in_stream, age);
		   			
		   		bintree.insert(Military(full_name, rank, std::stoi(company_number), std::stoi(age)));
		   		rbtree.insert(Military(full_name, rank, std::stoi(company_number), std::stoi(age)));
		   		htable.insert(Military(full_name, rank, std::stoi(company_number), std::stoi(age)));

		   		unsigned int hash = htable.ROT13Hash(full_name);
		   		if(std::find(hashes.begin(), hashes.end(), hash) != hashes.end()) count++;
		   		else hashes.push_back(hash);
		   		
		   		mm.insert({full_name, Military(full_name, rank, std::stoi(company_number), std::stoi(age))});
		 	}
			in_stream.close();
					
			auto start1 = steady_clock::now();
			bintree.find(m[size]);
			auto end1 = steady_clock::now();
			duration<double> sec1 = end1 - start1;

			auto start2 = steady_clock::now();
			rbtree.find(m[size]);
			auto end2 = steady_clock::now();
			duration<double> sec2 = end2 - start2;
			
			auto start3 = steady_clock::now();
			htable.find(m[size]);
			auto end3 = steady_clock::now();
			duration<double> sec3 = end3 - start3;
			
			auto start4 = steady_clock::now();
			mm.find(m[size]);
			auto end4 = steady_clock::now();
			duration<double> sec4 = end4 - start4;

			binTreeTime.push_back(sec1.count());
			rbTreeTime.push_back(sec2.count());
			hashTableTime.push_back(sec3.count());
			multiMapTime.push_back(sec4.count());
			numberOfCollisions.push_back(count);
		}
	}
	
	for(auto& time : binTreeTime) cout << time << " ";
	cout << endl;
	
	for(auto& time : rbTreeTime) cout << time << " ";
	cout << endl;
	
	for(auto& time : hashTableTime) cout << time << " ";
	cout << endl;
	
	for(auto& count : numberOfCollisions) cout << count << " ";
	cout << endl;
	
	for(auto& time : multiMapTime) cout << time << " ";
	cout << endl;
		
    return 0;
}
