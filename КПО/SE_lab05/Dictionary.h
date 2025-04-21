#pragma once
#include<iostream>
#include<cstring>
#include<cstdlib>
#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30
#define THROW01 "Create: превшен размер имени словаря"
#define THROW02 "Create: превышен размер максимального емкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование индетификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование индетификатора"
namespace dictionary {
	struct Entry {
		int		id;
		char	name[ENTRYNAMEMAXSIZE];
	};

	struct Instance {
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		int size;
		Entry* dictionary[DICTMAXSIZE];
	};
	Instance Create(const char name[DICTNAMEMAXSIZE], int size);
	void AddEntry(Instance& inst, Entry ed);
	void DelEntry(Instance& inst, int id);
	void UpdEntry(Instance& inst, int id, Entry new_ed);
	Entry GetEntry(Instance inst, int id);
	void Print(Instance d);
	void Delete(Instance& d);
}
