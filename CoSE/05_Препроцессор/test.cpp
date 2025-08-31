#include "stdafx.h"
#include <iostream>

using namespace Dictionary;
using namespace std;

// ������� ��� ������������
#define TEST_CREATE_01
#define TEST_CREATE_02
#define TEST_ADDENTRY_03
#define TEST_ADDENTRY_04
#define TEST_GETENTRY_05
#define TEST_GETENTRY_06
#define TEST_UPDENTRY_07
#define TEST_UPDENTRY_08
#define TEST_DICTIONARY

void testCreate01() {
#ifdef TEST_CREATE_01
    cout << "\n���� CREATE_01: �������� ��������� ���������� THROW01" << endl;
    try {
        char longName[100] = "ThisNameIsTooLongForDictionaryAndShouldGenerateAnException";
        Instance dict = Create(longName, 10);
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testCreate02() {
#ifdef TEST_CREATE_02
    cout << "\n���� CREATE_02: �������� ��������� ���������� THROW02" << endl;
    try {
        Instance dict = Create("Test", 101); // DICTMAXSIZE = 100
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testAddEntry03() {
#ifdef TEST_ADDENTRY_03
    cout << "\n���� ADDENTRY_03: �������� ��������� ���������� THROW03" << endl;
    try {
        Instance dict = Create("Test", 2);
        Entry e1 = { 1, "First" };
        Entry e2 = { 2, "Second" };
        Entry e3 = { 3, "Third" };
        
        AddEntry(dict, e1);
        AddEntry(dict, e2);
        AddEntry(dict, e3); // ������ ������� ����������
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testAddEntry04() {
#ifdef TEST_ADDENTRY_04
    cout << "\n���� ADDENTRY_04: �������� ��������� ���������� THROW04" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        Entry e2 = { 1, "Second" }; // ��� �� id
        
        AddEntry(dict, e1);
        AddEntry(dict, e2);
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testGetEntry05() {
#ifdef TEST_GETENTRY_05
    cout << "\n���� GETENTRY_05: �������� ��������� ���������� THROW05" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e = GetEntry(dict, 1); // ������� ����
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testGetEntry06() {
#ifdef TEST_GETENTRY_06
    cout << "\n���� GETENTRY_06: �������� ��������� ���������� THROW06" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        AddEntry(dict, e1);
        DelEntry(dict, 2); // �������������� id
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testUpdEntry07() {
#ifdef TEST_UPDENTRY_07
    cout << "\n���� UPDENTRY_07: �������� ��������� ���������� THROW07" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        Entry e2 = { 2, "Update" };
        AddEntry(dict, e1);
        UpdEntry(dict, 3, e2); // �������������� id
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testUpdEntry08() {
#ifdef TEST_UPDENTRY_08
    cout << "\n���� UPDENTRY_08: �������� ��������� ���������� THROW08" << endl;
    try {
        Instance dict = Create("Test", 5);
        Entry e1 = { 1, "First" };
        Entry e2 = { 2, "Second" };
        Entry e3 = { 1, "Update" }; // ����������� id
        
        AddEntry(dict, e1);
        AddEntry(dict, e2);
        UpdEntry(dict, 2, e3);
        cout << "������: ���������� �� ���� �������������" << endl;
    }
    catch (exception& e) {
        cout << "�����: ����������� ����������: " << e.what() << endl;
    }
#endif
}

void testDictionary() {
#ifdef TEST_DICTIONARY
    cout << "\n���� DICTIONARY: ������������ ������ ��������" << endl;
    try {
        // �������� ������� ���������
        Instance students = Create("��������", 10);
        
        // ���������� ���������
        Entry s1 = { 1, "������" };
        Entry s2 = { 2, "������" };
        Entry s3 = { 3, "�������" };
        Entry s4 = { 4, "������" };
        Entry s5 = { 5, "�������" };
        Entry s6 = { 6, "�������" };
        Entry s7 = { 7, "�����" };
        
        AddEntry(students, s1);
        AddEntry(students, s2);
        AddEntry(students, s3);
        AddEntry(students, s4);
        AddEntry(students, s5);
        AddEntry(students, s6);
        AddEntry(students, s7);
        
        // �������� ������� ��������������
        Instance teachers = Create("�������������", 10);
        
        // ���������� ��������������
        Entry t1 = { 1, "�����������" };
        Entry t2 = { 2, "�������" };
        Entry t3 = { 3, "��������" };
        Entry t4 = { 4, "���������" };
        Entry t5 = { 5, "��������" };
        Entry t6 = { 6, "��������" };
        Entry t7 = { 7, "�����" };
        
        AddEntry(teachers, t1);
        AddEntry(teachers, t2);
        AddEntry(teachers, t3);
        AddEntry(teachers, t4);
        AddEntry(teachers, t5);
        AddEntry(teachers, t6);
        AddEntry(teachers, t7);
        
        // ����� ����������� ��������
        cout << "\n���������� ��������:" << endl;
        Print(students);
        cout << endl;
        Print(teachers);
        
        // ������� ������
        Delete(students);
        Delete(teachers);
        
        cout << "\n�����: ���� ������� ��������" << endl;
    }
    catch (exception& e) {
        cout << "������: " << e.what() << endl;
    }
#endif
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "=== ������ ������������ ===" << endl;
    
    testCreate01();
    testCreate02();
    testAddEntry03();
    testAddEntry04();
    testGetEntry05();
    testGetEntry06();
    testUpdEntry07();
    testUpdEntry08();
    testDictionary();
    
    cout << "\n=== ������������ ��������� ===" << endl;
    
    return 0;
} 