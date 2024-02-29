//
// Created by Dmitry Galkin on 20.02.2024.
//

#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H
#include <string>

const int MAX_LINE_LENGTH = 256; // Предполагаемая максимальная длина строки
const int NUM_LINES = 10; // Количество выводимых строк
const std::string PATH_FILES_lAB7 = "../Lab7/resources/";

void tail(const std::string& filename);
void getLines(const std::string& filename, int startLine, int numLines);

#endif //TEXT_UTILS_H
