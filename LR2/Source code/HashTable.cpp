/*!
	\file
	\brief Файл реализации методов класса хеш-таблицы HashTable.
*/
#include "HashTable.h"

unsigned int HashTable::ROT13Hash(const string &key){
	unsigned int hash = 0;
	for (auto elem : key) {
		hash += (unsigned char)(elem);
		hash -= (hash << 13) | (hash >> 19);
	}
	return hash % size;
}

void HashTable::insert(Military data){
	unsigned int index = ROT13Hash(data.getFullName());
	
	if(table[index]) handleCollision(index); // Если индекс уже занят, то необходимо обработать коллизию
	table[index] = new HashNode(data); // Иначе добавляем элемент в таблицу
}

void HashTable::handleCollision(unsigned int &index){ // Линейное пробирование
	++index %= size;
	while(table[index]) ++index %= size; 
}

bool HashTable::find(const string &key){
	unsigned int index = ROT13Hash(key);
	
	unsigned int i = index;
	while(table[i]->key != key){ // Если элемент с первой проверки не нашли, то не факт, что его нет. Из-за коллизии он мог "переехать" в другое место.
		++i %= size; 
		if(i == index) return false;
	} 
	return true;
}
