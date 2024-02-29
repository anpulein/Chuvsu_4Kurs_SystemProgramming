//
// Created by Dmitry Galkin on 15.02.2024.
//

#include "write_utils.h"

#include <iostream>
#include <string>
#include <unistd.h>

// Функция для разбора командной строки
int Options(int argc, char* argv[], const std::string& optStr, bool& sFlag) {
    sFlag = false; // Инициализация флага -s как false
    int fileIndex = 1; // Индекс первого файла в argv

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg[0] == '-') { // Проверка на наличие опции
            for (size_t j = 1; j < arg.length(); ++j) {
                if (arg[j] == 's') {
                    sFlag = true; // Установка флага -s
                } else {
                    std::cerr << "Неизвестная опция: " << arg[j] << std::endl;
                }
            }
        } else {
            fileIndex = i; // Индекс первого неопционного аргумента
            break;
        }
    }

    return fileIndex; // Возвращение индекса первого файла
}


void CatFile(int inFile, int outFile) {
    const size_t BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = read(inFile, buffer, BUFFER_SIZE)) > 0) {
        if (write(outFile, buffer, bytesRead) != bytesRead) {
            std::cerr << "Ошибка записи" << std::endl;
            return;
        }
    }

    if (bytesRead < 0) {
        std::cerr << "Ошибка чтения" << std::endl;
    }
    else {
        write(outFile, "\n", 1);
    }
}

