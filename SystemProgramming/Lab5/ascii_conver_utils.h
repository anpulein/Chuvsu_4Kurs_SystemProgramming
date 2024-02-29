//
// Created by Dmitry Galkin on 16.02.2024.
//

#ifndef ASCII_CONVER_UTILS_H
#define ASCII_CONVER_UTILS_H
#include <string>

const std::string PATH_FILES_lAB5 = "./Lab5/resources/";

// Прототип функции Asc2Un
bool Asc2Un(const char* fIn, const char* fOut, bool bFailIfExist);
bool Asc2Un1(const char* fIn, const char* fOut, bool bFailIfExist);

#endif //ASCII_CONVER_UTILS_H
