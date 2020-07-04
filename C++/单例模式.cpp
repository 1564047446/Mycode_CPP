/*************************************************************************
	> File Name: 单例模式.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31日 星期六 16时02分51秒
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Server {
public :    
    static Server *get_instance() {
        if (Server::single) {
            return Server::single;
        }
        Server::single = new Server(2, 3);
        return Server::single;
    }
private :
    static Server *single;
    Server(int x, int y) : x(x), y(y) {

    }
    ~Server() {

    }
    Server(Server &S) {

    }
    Server &operator=(Server &S) {
        return *this;
    }
    int x, y;
};

Server *Server::single = nullptr;

int main() {
    //Server s;
    return 0;
}
