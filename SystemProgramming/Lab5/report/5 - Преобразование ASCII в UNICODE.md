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
Лабораторная работа 5
<br>
«Преобразование ASCII в UNICODE»
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
<p align="center" style="font-size=10pt;">Чебоксары, 2024</p>
<div style="page-break-after:always;  visibility:hidden"></div>
</div>

### Цель работы:

Напишите программу копирования файла с преобразованием из ASCII в UNICODE:
```bash
atou [-i] FileIn FileOut
```
1. Опция **-i** запрещает замену существующего файла. Непосредственное преобразование файла необходимо осуществить служебной функцией:
```cpp
BOOL Asc2Un(LPCTSTR fIn, LPCTSTR fOut, BOOL bFailfExist)
```
2. Проверьте все варианты использования программы **atou**
3. Функция **CreateFile** позволяет задать характеристики доступа к файлу, чтобы повысить быстродействие. Пример - **FILE_FLAG_SEQUENTIAL_SCAN**. Примените этот флаг в функции  **Asc2Un** и определите, повышается ли быстродействие для больших файлов
4. Выполните функцию **Asc2Un** с определенной переменной  UNICODE и без нее. Каков эффект  и есть ли он вообще?
<div style="page-break-after:always;  visibility:hidden"></div>
### Полный текст программы:

ascii_conver_utils.h
```cpp
//  
// Created by Dmitry Galkin on 16.02.2024.  
//  
  
#ifndef ASCII_CONVER_UTILS_H  
#define ASCII_CONVER_UTILS_H  
#include <string>  
  
const std::string PATH_FILES_lAB5 = "./Lab5/resources/";  
  
// Прототип функции Asc2Un  
bool Asc2Un(const char* fIn, const char* fOut, bool bFailIfExist);  
  
#endif //ASCII_CONVER_UTILS_H
```

<div style="page-break-after:always;  visibility:hidden"></div>

Lab5.cpp
```cpp
//  
// Created by Dmitry Galkin on 16.02.2024.  
//  
  
#include "ascii_conver_utils.h"  
  
#include <fstream>  
#include <iostream>  
#include <locale>  
#include <codecvt>  
    
bool Asc2Un(const char* fIn, const char* fOut, bool bFailIfExist) {  
    // Проверка существования выходного файла  
    std::ifstream testExist(fOut);  
    if (bFailIfExist && testExist.good()) {  
        testExist.close();  
        std::cerr << "Output file already exists. Use -i to ignore.\n";  
        return false;  
    }  
    testExist.close();  
  
    // Открытие входного файла в двоичном режиме  
    std::ifstream inFile(fIn, std::ios::binary);  
    if (!inFile) {  
        std::cerr << "Could not open input file.\n";  
        return false;  
    }  
  
    // Открытие выходного файла в двоичном режиме  
    std::ofstream outFile(fOut, std::ios::binary);  
    if (!outFile) {  
        std::cerr << "Could not open output file.\n";  
        inFile.close();  
        return false;  
    }  
  
    // Копирование содержимого файла  
    outFile << inFile.rdbuf();  
  
    inFile.close();  
    outFile.close();  
    return true;  
}
```

<div style="page-break-after:always;  visibility:hidden"></div>

main.cpp
```cpp
#include "Lab4/write_utils.h"  
#include <iostream>  
#include <vector>  
#include <sys/termios.h>  
  
using namespace std; 
  
void start_lab4(int argc, char* argv[]);  
  
int main(int argc, char* argv[]) {  
  
    if(start_lab5(argc, argv))  
	    return 1; 
    return 0;  
}
  
  
bool start_lab5(int argc, char* argv[]) {  
    if (argc < 3) {  
        std::cerr << "Usage: atou [-i] FileIn FileOut\n";  
        return true;  
    }  
  
    bool ignoreIfExists = false;  
    const char* fileIn;  
    const char* fileOut;  
  
    // Обработка аргументов командной строки  
    if (argc == 4 && std::string(argv[1]) == "-i") {  
        ignoreIfExists = true;  
        fileIn = argv[2];  
        fileOut = argv[3];  
    } else {  
        fileIn = argv[1];  
        fileOut = argv[2];  
    }  
  
    // Вызов функции преобразования  
    if (!Asc2Un1(fileIn, fileOut, ignoreIfExists)) {  
        std::cerr << "Error converting file from ASCII to UNICODE.\n";  
        return true;  
    }  
  
    std::cout << "File converted successfully.\n";  
  
    return false;  
}
```


<div style="page-break-after:always;  visibility:hidden"></div>

### Пример работы:

![[CleanShot 2024-02-21 at 16.06.43@2x.png]]
![[CleanShot 2024-02-21 at 16.06.52@2x.png]]