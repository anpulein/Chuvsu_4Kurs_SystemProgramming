//
// Created by Dmitry Galkin on 15.02.2024.
//

#ifndef WRITE_UTILS_H
#define WRITE_UTILS_H

#include <string>

const std::string PATH_FILES_lAB4 = "../Lab4/resources/";

// Функция для разбора командной строки
int Options(int argc, char* argv[], const std::string& optStr, bool& sFlag);

void CatFile(int inFile, int outFile);

#endif //WRITE_UTILS_H
