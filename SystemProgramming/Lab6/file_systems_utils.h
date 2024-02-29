//
// Created by Dmitry Galkin on 16.02.2024.
//

#ifndef FILE_SYSTEMS_UTILS_H
#define FILE_SYSTEMS_UTILS_H
#include <string>

// Вывод справочника
void printHelp();
// Создание файла или каталога
void create(const std::string& name);
// Удаления файла или каталога
void remove(const std::string& name);
// Копирование файла или каталога
void copy(const std::string& source, const std::string& destination);
// Переименование файла или каталога
void rename(const std::string& oldName, const std::string& newName);

#endif //FILE_SYSTEMS_UTILS_H
