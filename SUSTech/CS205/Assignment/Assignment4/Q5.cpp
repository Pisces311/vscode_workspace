#include <iostream>
#include <vector>
using namespace std;

enum CODE { START, STOP, RESTART, RELOAD, STATUS, EXIT };
vector<string> commands = {"start",  "stop",   "restart",
                           "reload", "status", "exit"};

int search(string cmd) {
    int ret = -1;
    for (int i = 0; i < commands.size(); i++)
        if (commands[i] == cmd) ret = i;
    return ret;
}

int main() {
    string cmd;
    bool execute = true;
    while (execute) {
        cout << "> ";
        cin >> cmd;
        int id = search(cmd);
        switch (id) {
            case START:
                cout << "command start recognized" << endl;
                break;
            case STOP:
                cout << "command stop recognized" << endl;
                break;
            case RESTART:
                cout << "command restart recognized" << endl;
                break;
            case RELOAD:
                cout << "command reload recognized" << endl;
                break;
            case STATUS:
                cout << "command status recognized" << endl;
                break;
            case EXIT:
                execute = false;
                break;
            default:
                cout << "Invalid command" << endl;
        }
    }
    return 0;
}