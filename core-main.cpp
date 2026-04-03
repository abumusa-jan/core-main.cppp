
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>

using namespace std;

extern "C" long long get_cpu_cycles();
extern "C" long long add_numbers(long long, long long);

// function: list files
void list_files() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            cout << dir->d_name << endl;
        }
        closedir(d);
    }
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "Usage: ./core [command]" << endl;
        return 0;
    }

    string cmd = argv[1];

    if (cmd == "cpu") {
        cout << "CPU Cycles: " << get_cpu_cycles() << endl;
    }

    else if (cmd == "hello") {
        cout << "Hello from C++ core!" << endl;
    }

    else if (cmd == "add") {
        if (argc < 4) {
            cout << "Usage: add num1 num2" << endl;
        } else {
            long long a = stoll(argv[2]);
            long long b = stoll(argv[3]);
            cout << "Result: " << add_numbers(a, b) << endl;
        }
    }

    else if (cmd == "ls") {
        list_files();
    }

    else {
        cout << "Unknown command" << endl;
    }

    return 0;
}
