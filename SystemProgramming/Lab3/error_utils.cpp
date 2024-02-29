//
// Created by Dmitry Galkin on 07.02.2024.
//

#include "error_utils.h"


// Функция ReportError для вывода сообщений об ошибках и завершения программы
void ReportError(const std::string& userMessage, int const exitCode, bool const printErrorMsg, std::string rus_error) {
    std::cerr << userMessage << std::endl; // Вывод пользовательского сообщения об ошибке
    if (printErrorMsg) {
        // В macOS для вывода системных сообщений об ошибках можно использовать perror
        std::cerr << "Системное сообщение об ошибке: " << rus_error << std::endl << std::endl;
    }
    // exit(exitCode); // Завершение программы с указанным кодом завершения
}

void TryOpenFile(const char* filename, const char* mode) {
    std::string full_path = PATH_FILES + filename;
    FILE* file = fopen(full_path.c_str(), mode);
    if (file == nullptr) {
        perror("Ошибка открытия файла через perror");
        ReportError("Ошибка открытия файла через ReportError", 1, true, "rus_error");
    } else {
        std::cout << "Файл успешно открыт: " << filename << std::endl;
        fclose(file);
    }
}


void TryOpenFile(const char* filename, const char* mode, std::string rus_error) {
    std::string full_path = PATH_FILES + filename;
    FILE* file = fopen(full_path.c_str(), mode);
    if (file == nullptr) {
        // perror("Ошибка открытия файла через perror");
        ReportError("Ошибка открытия файла через ReportError", 1, true, rus_error);
    } else {
        // std::cout << "Файл успешно открыт: " << filename << " - " << rus_error << std::endl;

        ReportError("Файл успешно открыт через ReportError:", 1, true, rus_error);
        fclose(file);
    }
}


void TryEditFile(const char* filename, const char* mode, std::string rus_error) {
    std::string full_path = PATH_FILES + filename;
    FILE* file = fopen(full_path.c_str(), mode);

    fprintf(file, "Это тестовая строка");
    perror("Ошибка открытия файла через perror");
    ReportError("Ошибка открытия файла через ReportError", 1, true, rus_error);

    fclose(file);
}