//
// Created by Dmitry Galkin on 07.02.2024.
//

#ifndef ERROR_UTILS_H
#define ERROR_UTILS_H

#include <iostream>
#include <string>
#include <cstdlib> // Для использования exit()

const std::string PATH_FILES = "../Lab3/resources/";

// Функция ReportError для вывода сообщений об ошибках и завершения программы
void ReportError(std::string& userMessage, int exitCode, bool printErrorMsg, std::string rus_error);

void TryOpenFile(const char* filename, const char* mode, std::string rus_error);

void TryOpenFile(const char* filename, const char* mode);

void TryEditFile(const char* filename, const char* mode, std::string rus_error);


#endif //ERROR_UTILS_H
