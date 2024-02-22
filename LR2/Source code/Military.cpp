/*!
	\file
	\brief Файл реализации методов класса военнослужащего Military.
*/
#include "Military.h"

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


string Military::getData() const{
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
