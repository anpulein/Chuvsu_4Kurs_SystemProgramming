//
// Created by Dmitry Galkin on 16.02.2024.
//

#include "ascii_conver_utils.h"

#include <fstream>
#include <iostream>
#include <locale>
#include <codecvt>

// bool Asc2Un(const char* fIn, const char* fOut, bool bFailIfExist) {
//     // Проверка существования выходного файла, если задан флаг bFailIfExist
//     std::ifstream testExist(fOut);
//     if (bFailIfExist && testExist.good()) {
//         testExist.close();
//         std::cerr << "Output file already exists. Use -i to ignore.\n";
//         return false;
//     }
//     testExist.close();
//
//     // Открытие входного файла в ASCII режиме
//     std::ifstream inFile(fIn);
//     if (!inFile) {
//         std::cerr << "Could not open input file.\n";
//         return false;
//     }
//
//     // Открытие выходного файла в UNICODE режиме с применением locale для преобразования
//     std::ofstream outFile(fOut, std::ios::binary);
//     std::locale loc(std::locale::classic(), new std::codecvt_utf16<wchar_t>);
//     outFile.imbue(loc);
//
//     if (!outFile) {
//         std::cerr << "Could not open output file.\n";
//         inFile.close();
//         return false;
//     }
//
//     char ch;
//     while (inFile.get(ch)) {
//         wchar_t wch = ch; // Простое преобразование в wchar_t
//         outFile.write(reinterpret_cast<const char*>(&wch), sizeof(wchar_t));
//     }
//
//     inFile.close();
//     outFile.close();
//     return true;
// }


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

// bool Asc2Un1(const char* fIn, const char* fOut, bool bFailIfExist) {
//     // Проверка существования выходного файла, если необходимо
//     if (bFailIfExist && std::filesystem::exists(fOut)) {
//         return false; // Файл существует, завершаем с ошибкой
//     }
//
//     // Открытие входного файла для чтения в UTF-8
//     std::ifstream input(fIn, std::ios::binary);
//     if (!input.is_open()) {
//         return false; // Не удалось открыть входной файл
//     }
//
//     // Подготовка конвертера для чтения UTF-8 и записи в UTF-16 или UTF-32
//     std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//
//     // Открытие выходного файла для записи
//     std::ofstream output(fOut, std::ios::binary | std::ios::out);
//     if (!output.is_open()) {
//         return false; // Не удалось открыть выходной файл
//     }
//
//     // Чтение и конвертация
//     std::string utf8String;
//     while (std::getline(input, utf8String)) {
//         // Конвертация строки из UTF-8 в UTF-16
//         std::wstring utf16String = converter.from_bytes(utf8String);
//
//         // Запись в выходной файл (вам может потребоваться настроить запись в зависимости от вашей системы)
//         output.write(reinterpret_cast<const char*>(utf16String.data()), utf16String.size() * sizeof(wchar_t));
//
//         // Для разделения строк можно добавить символы новой строки, если они нужны
//         output.put('\0'); // Для UTF-16 (для UTF-32 используйте другой размер)
//         output.put('\n');
//     }
//
//     // Закрытие файлов
//     input.close();
//     output.close();
//
//     return true; // Успешное завершение
// }

// // Функция преобразования из UTF-8 в UTF-16
// std::wstring UTF8toUnicode(const std::string& s) {
//     std::wstring ws;
//     wchar_t wc;
//     for (int i = 0; i < s.length();) {
//         unsigned char c = s[i];
//         if ((c & 0x80) == 0) {
//             wc = c;
//             ++i;
//         } else if ((c & 0xE0) == 0xC0) {
//             wc = (s[i] & 0x1F) << 6;
//             wc |= (s[i + 1] & 0x3F);
//             i += 2;
//         } else if ((c & 0xF0) == 0xE0) {
//             wc = (s[i] & 0xF) << 12;
//             wc |= (s[i + 1] & 0x3F) << 6;
//             wc |= (s[i + 2] & 0x3F);
//             i += 3;
//         } else if ((c & 0xF8) == 0xF0) {
//             // Этот блок для 4-байтных символов UTF-8, который может быть представлен в UTF-16
//             // используя пару суррогатов, требует особой обработки. Однако здесь он не реализован,
//             // так как это выходит за рамки базовой UTF-16 конвертации.
//             i += 4; // Пропускаем символ, но в реальных сценариях здесь должна быть корректная обработка.
//         }
//         ws += wc;
//     }
//     return ws;
// }
//
// bool Asc2Un1(const char* fIn, const char* fOut, bool bFailIfExist) {
//     if (bFailIfExist && std::filesystem::exists(fOut)) {
//         return false; // Файл существует
//     }
//
//     std::ifstream input(fIn, std::ios::binary);
//     if (!input.is_open()) {
//         return false; // Не удалось открыть входной файл
//     }
//
//     std::ofstream output(fOut, std::ios::binary | std::ios::out);
//     if (!output.is_open()) {
//         return false; // Не удалось открыть выходной файл
//     }
//
//     std::string utf8String;
//     while (std::getline(input, utf8String)) {
//         // Используем вашу функцию для конвертации строки из UTF-8 в UTF-16
//         std::wstring utf16String = UTF8toUnicode(utf8String);
//
//         // Запись в выходной файл
//         output.write(reinterpret_cast<const char*>(utf16String.data()), utf16String.size() * sizeof(wchar_t));
//
//         // Добавление символов новой строки (важно сохранять их в правильной кодировке)
//         wchar_t newline[] = {'\r', '\n'};
//         output.write(reinterpret_cast<const char*>(&newline), sizeof(newline));
//     }
//
//     input.close();
//     output.close();
//
//     return true; // Успешное завершение
// }
