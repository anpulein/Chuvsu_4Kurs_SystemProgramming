<div>
<p align="center" style="font-size=14pt; font-weight: bolder;">МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ
<br>
Федеральное государственное бюджетное учреждение высшего образования
<br>
«Чувашский государственный университет И.Н. Ульянова»
<br>
Факультет информатики и вычислительной техники 
<br>
Кафедра вычислительной техники
<br> <br> <br> <br> <br> <br> <br><br> <br> <br>
Системное программирование
<br>
Лабораторная работа 1
<br>
«Копирование файлов в Unix системе»
</p>

<br> <br> <br> <br><br> <br><br>

<span>
<p align="right" style="font-size=14pt; font-weight: bolder;">Выполнил:</p>
<p align="right" style="font-size=14pt;">Студент группы ИВТ-41-20 <br>
Галкин Д.С.
</p>
</span> <br>

<span>
<p align="right" style="font-size=14pt; font-weight: bolder;">Проверил:</p>
<p align="right" style="font-size=14pt;">Яковлев С.B.</p>
</span>

<br> <br>
<br> <br>
<br> <br>
<br> <br>
<p align="center" style="font-size=10pt;">Чебоксары, 2023</p>
<div style="page-break-after:always;  visibility:hidden"></div>
</div>

### Цель работы:

Написать, ввести, построить и выполнить три программы копирования файлов **cpC**, **cpW**, **cpCF** с указанной строкой запуска.
1. cpC: копирование файлов с использованием стандартной библиотеки C, которая поддерживает объекты потокового ввода-вывода FiLE. (копирует файл1 в файл2)
2. Выяснить, как поведет себя программа cpC, если входной файл открыть в двоичном режиме, а выходной - в текстовом, и наоборот. 
3. Измерить быстродействие программ копирования на файлах размером 10К, 100К, 1М, 10М, 100М, возможно, с применением функции DWORD GetTickCount(VOID)
<div style="page-break-after:always;  visibility:hidden"></div>
### Полный текст программы:

cpC_files.h
```C++
//  
// Created by Dmitry Galkin on 02.02.2024.  
//  
  
#ifndef CPC_FILES_H  
#define CPC_FILES_H  
#include <string>  
#include <fstream>  
  
namespace Lab1 {  
    class File {  
    public:  
        std::string read_file();  
        void write_file(std::string data);  
        std::string read_file(std::string nameFile);  
        void write_file(std::string data, std::string nameFile);  
        static long long getCurrentTimeMillis();  
    private:  
       const std::string IN_PATH_FILE = "../Lab1/resources/";  
       const std::string OUT_PATH_FILE = "../Lab1/resources/";  
    };  
}  
  
#endif //CPC_FILES_H
```

<div style="page-break-after:always;  visibility:hidden"></div>

Lab1.cpp
```C++
//  
// Created by Dmitry Galkin on 02.02.2024.  
//  
  
  
#include "cpC_files.h"  
#include <vector>  
#include <sys/time.h>  
using namespace Lab1;  
using namespace std;  
  
// Функция для измерения текущего времени в миллисекундах  
long long File::getCurrentTimeMillis() {  
    timeval tv{};  
    gettimeofday(&tv, nullptr);  
    return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);  
}  
  
  
string File::read_file() {  
  
    string line;  
    string data;  
    ifstream in(IN_PATH_FILE, ios::binary);  
  
    if (in.is_open()) {  
        while (getline(in, line)) {  
            data += line;  
        }  
    }  
  
    in.close();  
  
    return data;  
}  
  
string File::read_file(string nameFile) {  
  
    string line;  
    string data;  
    ifstream in(IN_PATH_FILE + nameFile, ios::binary);  
  
    if (in.is_open()) {  
        while (getline(in, line)) {  
            data += line;  
        }  
    }  
  
    in.close();  
  
    return data;  
}  
  
void File::write_file(string data) {  
  
    ofstream out(OUT_PATH_FILE);  
    if(out.is_open()) {  
        out << data;  
    }  
  
    out.close();  
}  
  
void File::write_file(string data, string nameFile) {  
  
    ofstream out(OUT_PATH_FILE + nameFile);  
    if(out.is_open()) {  
        out << data;  
    }  
  
    out.close();  
}
```

<div style="page-break-after:always;  visibility:hidden"></div>

main.cpp
```C++
#include "Lab1/cpC_files.h"  
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
void start_lab1();  
  
int main() {  
  
    start_lab1();  
    return 0;  
}  
  
  
void start_lab1() {  
  
    vector<std::string> files = {"10K_file", "100K_file", "1M_file", "10M_file", "100M_file"};  
    vector<long long> times;  
  
    auto *file = new Lab1::File();  
  
    for (const auto &name_file : files) {  
        string sourcePath = name_file; // Укажите путь к исходному файлу  
        string destinationPath = name_file + "_copy"; // Путь к файлу назначения  
  
  
        long long startTime = Lab1::File::getCurrentTimeMillis();  
        string data = file->read_file(name_file);  
        file->write_file(data, destinationPath);  
        long long endTime = Lab1::File::getCurrentTimeMillis();;  
  
        times.push_back(endTime - startTime);  
    }  
  
    // Вывод результатов в виде таблицы  
    std::cout << "File Size\tTime (ms)\n";  
    for (size_t i = 0; i < files.size(); ++i) {  
        std::cout << files[i] << "\t" << times[i] << "\n";  
    }  
}
```

<div style="page-break-after:always;  visibility:hidden"></div>

### Пример работы:

![[CleanShot 2024-02-02 at 15.48.39@2x.png]]

![[CleanShot 2024-02-02 at 15.49.00@2x.png]]