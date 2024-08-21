#include <fstream>
#include <iostream>
#include "json/json.h"
#include "tinyfiledialogs.h"


int main(int argc, char const *argv[])
{
    Json::Value root;
    std::ifstream ifs;

    ifs.open("./test.json");

    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;

    if(!parseFromStream(builder, ifs, &root, &errs)) {
        std::cout << errs << std::endl;
        return EXIT_FAILURE;
    }

    //Imprimiendo JSON
    std::cout << "Contenido del archivo JSON" << std::endl;
    std::cout << root << std::endl;

    //Imprimiendo solo un miembro
    std::cout << "Imprimiendo los datos de solamente una persona" << std::endl;
    std::cout << root["Anna"] << std::endl;
    std::cout << root["Anna"]["age"] << std::endl;
    return 0;
}