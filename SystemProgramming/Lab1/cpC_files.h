//
// Created by Dmitry Galkin on 02.02.2024.
//

#ifndef CPC_FILES_H
#define CPC_FILES_H
#include <string>
#include <fstream>

namespace Lab1 {
    class File {
    public:
        std::string read_file();
        void write_file(std::string data);
        std::string read_file(std::string nameFile);
        void write_file(std::string data, std::string nameFile);
        static long long getCurrentTimeMillis();
    private:
       const std::string IN_PATH_FILE = "../Lab1/resources/";
       const std::string OUT_PATH_FILE = "../Lab1/resources/";
    };
}

#endif //CPC_FILES_H
