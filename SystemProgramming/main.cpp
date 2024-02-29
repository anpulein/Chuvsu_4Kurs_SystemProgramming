#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <sys/termios.h>

// #include "Lab1/cpC_files.h"
#include "Lab2/console_utils.h"
#include "Lab3/error_utils.h"
#include "Lab4/write_utils.h"
#include "Lab5/ascii_conver_utils.h"
#include "Lab6/file_systems_utils.h"
#include "Lab7/text_utils.h"

using namespace std;

// void start_lab1();
// void start_lab2();
// void start_lab3();
// // Аргументы: -s file1.txt file2.txt
// void start_lab4(int argc, char* argv[]);
// // Аргументы: ../Lab5/resources/file1.txt ../Lab5/resources/file2.txt (-i ../Lab5/resources/file1.txt ../Lab5/resources/file2.txt)
bool start_lab5(int argc, char* argv[]);
// Аргументы: /?
bool start_lab6(int argc, char* argv[]);
// Аргументы: text.txt 10
bool start_lab7(int argc, char* argv[]);

int main(int argc, char* argv[]) {

    // start_lab1();
    // start_lab2();
    // start_lab3();
    // start_lab4(argc, argv);
    if(start_lab5(argc, argv))
        return 1;
    // start_lab6(argc, argv);
    // start_lab7(argc, argv);

    return 0;
}


// void start_lab1() {
//
//     vector<std::string> files = {"10K_file", "100K_file", "1M_file", "10M_file", "100M_file"};
//     vector<long long> times;
//
//     auto *file = new Lab1::File();
//
//     for (const auto &name_file : files) {
//         string sourcePath = name_file; // Укажите путь к исходному файлу
//         string destinationPath = name_file + "_copy"; // Путь к файлу назначения
//
//
//         long long startTime = Lab1::File::getCurrentTimeMillis();
//         string data = file->read_file(name_file);
//         file->write_file(data, destinationPath);
//         long long endTime = Lab1::File::getCurrentTimeMillis();;
//
//         times.push_back(endTime - startTime);
//     }
//
//     // Вывод результатов в виде таблицы
//     std::cout << "File Size\tTime (ms)\n";
//     for (size_t i = 0; i < files.size(); ++i) {
//         std::cout << files[i] << "\t" << times[i] << "\n";
//     }
// }
//
// void start_lab2() {
//     PrintMsg(std::cout, "Тестирование PrintMsg\n");
//     PrintStrings(std::cout, "PrintStrings ", "с ", "проверкой ", "ошибок\n", nullptr);
//
//     std::string response;
//     if (ConsolePrompt("Введите что-нибудь (с эхо): ", response, 256, true)) {
//         PrintMsg(std::cout, "Вы ввели: " + response);
//     } else {
//         PrintMsg(std::cout, "Ошибка ввода.");
//     }
//
//     if (ConsolePrompt("Введите пароль (без эхо): ", response, 256, false)) {
//         PrintMsg(std::cout, "\nПароль успешно введен: " + response);
//     } else {
//         PrintMsg(std::cout, "Ошибка ввода.");
//     }
//
// }
//
// void start_lab3() {
//     // 1. Открытие несуществующего файла
//     // std::cout << "1. Открытие несуществующего файла" << std::endl;
//     TryOpenFile("empty.txt", "r", "Нет такого файла или каталога");
//
//     // 2. Открытие файла, используемого другой программой на чтение, для записи
//     // std::cout << "2. Открытие файла, используемого другой программой на чтение, для записи" << std::endl;
//     TryOpenFile("test2.txt", "r", "Файл успешно открыт, т.к в Unix системе доступ к файлу, который уже занят, моя программа все равно имеет.");
//
//     // 3. Открытие файла с атрибутом "только для чтения" на запись
//     // std::cout << "3. Открытие файла с атрибутом 'только для чтения' на запись" << std::endl;
//     TryOpenFile("test3.txt", "w", "В разрешении отказано");
//
//     // 4. Запись в файл, открытый только для чтения
//     // std::cout << "4. Запись в файл, открытый только для чтения" << std::endl;
//     TryEditFile("test4.txt", "r", "Неверный файловый дескриптор");
//
//     // 5. Запись в файл, редактируемой другим приложением
//     // std::cout << "5. Запись в файл, редактируемой другим приложением" << std::endl;
//     TryOpenFile("test2.txt", "r", "Файл успешно открыт, т.к в Unix системе доступ к файлу, который уже занят, моя программа все равно имеет.");
//
//     // 6. Чтение из файла, редактируемого другой программой
//     // std::cout << "6. Чтение из файла, редактируемого другой программой" << std::endl;
//     TryOpenFile("test2.txt", "r", "Файл успешно открыт, т.к в Unix системе доступ к файлу, который уже занят, моя программа все равно имеет.");
//
//     // // 7. Закрытие файла, используемого другой программой
//     // std::cout << "7. Закрытие файла, используемого другой программой" << std::endl;
//     TryOpenFile("test2.txt", "r", "Файл успешно закрыт, т.к в Unix системе доступ к файлу, который уже занят, моя программа все равно имеет.");
// }
//
// void start_lab4(int argc, char* argv[]) {
//     bool sFlag;
//     int fileIndex = Options(argc, argv, "s", sFlag);
//
//     if (argc == fileIndex) { // Если файлы не указаны, читать стандартный ввод
//         CatFile(STDIN_FILENO, STDOUT_FILENO);
//     } else {
//         for (int i = fileIndex; i < argc; ++i) {
//             std::string full_path = PATH_FILES_lAB4 + argv[i];
//             int inFile = open(full_path.c_str(), O_RDONLY);
//             if (inFile < 0) {
//                 if (!sFlag) {
//                     std::cerr << "Невозможно открыть файл: " << argv[i] << std::endl;
//                 }
//                 continue;
//             }
//
//             CatFile(inFile, STDOUT_FILENO);
//             close(inFile);
//         }
//     }
// }
//
//
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
    if (!Asc2Un(fileIn, fileOut, ignoreIfExists)) {
        std::cerr << "Error converting file from ASCII to UNICODE.\n";
        return true;
    }

    std::cout << "File converted successfully.\n";

    return false;
}

bool start_lab6(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "/?") {
        printHelp();
        // return 0;
    }

    while (true) {
        printHelp();
        std::cout << "Выберите пункт меню: ";
        int choice;
        std::cin >> choice;
        std::string name1, name2;

        switch (choice) {
            case 1:
                std::cout << "Введите имя файла или каталога для создания: ";
            std::cin >> name1;
            create(name1);
            break;
            case 2:
                std::cout << "Введите имя файла или каталога для удаления: ";
            std::cin >> name1;
            remove(name1);
            break;
            case 3:
                std::cout << "Введите исходное имя и целевое имя для копирования: ";
            std::cin >> name1 >> name2;
            copy(name1, name2);
            break;
            case 4:
                std::cout << "Введите старое и новое имя для переименования: ";
            std::cin >> name1 >> name2;
            rename(name1, name2);
            break;
            case 5:
                std::cout << "Выход из программы.\n";
            return 0;
            default:
                std::cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    // return 0;
}

bool start_lab7(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Использование: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }
    else if (argc < 4 && argc > 2) {
        std::cerr << "Usage: " << argv[0] << " <filename> <startLine> <numLines>" << std::endl;
        return 1;
    }

    if (argc == 2)
        tail(argv[1]);
    else if (argc == 4) {
        const std::string filename = argv[1];
        int startLine = std::atoi(argv[2]); // Преобразуем строку в число
        int numLines = std::atoi(argv[3]); // Преобразуем строку в число

        // Проверяем, что номера строк и количество строк являются положительными числами
        if (startLine < 1 || numLines < 1) {
            std::cerr << "Start line and number of lines must be greater than 0." << std::endl;
            return 1;
        }

        getLines(filename, startLine, numLines);
    }
    return 0;
}