#include "Dictionary.h"
#include "stdafx.h"
namespace dictionary {

	Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
		Instance newDict;
		if (strlen(name) > DICTNAMEMAXSIZE) {
			throw(char*)THROW01;
		}
		for (int i = 0; i < strlen(name); i++) {
			newDict.name[i] = name[i];
		}
		newDict.name[strlen(name)] = '\0';
		if (size > DICTMAXSIZE) {
			throw(char*)THROW02;
		}
		newDict.maxsize = size;
		newDict.size = 0;
		return newDict;
	}
	void AddEntry(Instance& inst, Entry ed) {
		if (inst.size == inst.maxsize) throw (char*)THROW03;
		for (int i = 0; i < inst.size; i++) {
			if (ed.id == inst.dictionary[i]->id) throw (char*)THROW04;
		}
		inst.dictionary[inst.size] = new Entry();
		inst.dictionary[inst.size]->id = ed.id;
		for (int i = 0; i < strlen(ed.name); i++) {
			inst.dictionary[inst.size]->name[i] = ed.name[i];
		}
		inst.dictionary[inst.size]->name[strlen(ed.name)] = '\0';
		inst.size++;
	}
	void DelEntry(Instance& inst, int id) {
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i]->id == id) {
				delete inst.dictionary[i];
				for (int j = i; j < inst.size - 1; j++) {
					inst.dictionary[j] = inst.dictionary[j + 1];
				}
				inst.size--;
				inst.dictionary[inst.size] = nullptr;
				return;
			}
		}
		throw THROW06;
	}
	Entry GetEntry(Instance inst, int id) {
		Entry getElement;
		for (int i = 0; i < inst.size; i++) {
			if (id == inst.dictionary[i]->id) {
				getElement.id = inst.dictionary[i]->id;
				for (int j = 0; j < strlen(inst.dictionary[i]->name); j++)
					getElement.name[j] = inst.dictionary[i]->name[j];
				getElement.name[strlen(inst.dictionary[i]->name)] = '\0';
				return getElement;
			}
		}
		throw (char*)THROW05;
	}
	void UpdEntry(Instance& inst, int id, Entry new_ed) {
		bool isFound = false;
		for (int i = 0; i < inst.size; i++)
		{
			if (inst.dictionary[i]->id == id)
			{
				for (int j = i; j < inst.size; j++) //+1
				{
					if (new_ed.id == inst.dictionary[j]->id) {
						throw (char*)THROW08;
					}
				}
				isFound = true;

				inst.dictionary[i]->id = new_ed.id;
				strcpy_s(inst.dictionary[i]->name, new_ed.name);
				break;
			}
			else if (new_ed.id == inst.dictionary[i]->id)
			{
				throw (char*)THROW08;
			}
		}
		if (!isFound)
		{
			throw (char*)THROW07;
		}
	}

	void Delete(Instance& inst) {
		for (int i = 0; i < inst.size; i++) {
			delete[] inst.dictionary[i];
		}
		inst.size = 0;
	}
	void Print(Instance inst) {
		std::cout << "-------" << inst.name << "-------" << std::endl;
		for (int i = 0; i < inst.size; i++) {
			std::cout << inst.dictionary[i]->id << ' ';
			for (int j = 0; j < strlen(inst.dictionary[i]->name); j++) {
				std::cout << inst.dictionary[i]->name[j];
			}
			std::cout << std::endl;
		}
	}
}
