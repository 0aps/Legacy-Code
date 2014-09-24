// echoClientC.cpp
#include "connectionHandler.h"
 
using Poco::Net::StreamSocket;
using Poco::Net::SocketStream;
using Poco::Net::SocketAddress;
using Poco::Exception;
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
 
ConnectionHandler::ConnectionHandler(string host, short port):  sa_(host, port), sock_(), stream_(sock_), port_(port), host_(host){
}
    
ConnectionHandler::~ConnectionHandler() {
    close();
}
 
bool ConnectionHandler::connect() {
    // Initiate blocking connection with server.
    std::cout << "Starting connect to " 
        << sa_.host().toString() << ":" << sa_.port() << std::endl;
    try {
        sock_.connect(sa_);
    }
    catch (Exception error) {
        std::cout << "Connection failed (Error: " << error.displayText() << ')' << std::endl;
        return false;
    }
    return true;
}
 
bool ConnectionHandler::getBytes(char bytes[], int bytesToRead) {
    int tmp = 0;
    try {
        while ( bytesToRead > tmp ) {
            tmp += sock_.receiveBytes(bytes + tmp, bytesToRead - tmp);
        }
    } catch (Exception error) {
        std::cout << "recv failed (Error: " << error.displayText() << ')' << std::endl;
        return false;
    }
    return true;
}

bool ConnectionHandler::sendBytes(const char bytes[], int bytesToWrite) {
    int tmp = 0;
    try {
        while ( bytesToWrite > tmp ) {
            tmp += sock_.sendBytes(bytes + tmp, bytesToWrite - tmp);
        }
    } catch (Exception error) {
        std::cout << "recv failed (Error: " << error.displayText() << ')' << std::endl;
        return false;
    }
    return true;
}
 
bool ConnectionHandler::getLine(std::string& line) {
    return getFrameAscii(line, '\n');
}

bool ConnectionHandler::sendLine(std::string& line) {
    return sendFrameAscii(line, '\n');
}
 
bool ConnectionHandler::getFrameAscii(std::string& frame, char delimiter) {
    char ch;
    // Stop when we encounter the null character. 
    // Notice that the null character is not appended to the frame string.
    try {
		do{
			sock_.receiveBytes(&ch, 1);
            frame.append(1, ch);
        }while (delimiter != ch);
    } catch (Exception error) {
        std::cout << "recv failed (Error: " << error.displayText() << ')' << std::endl;
        return false;
    }
    return true;
}
 
bool ConnectionHandler::sendFrameAscii(const std::string& frame, char delimiter) {
	bool result=sendBytes(frame.c_str(),frame.length());
	if(!result) return false;
	return sendBytes(&delimiter,1);
}
 
// Close down the connection properly.
void ConnectionHandler::close() {
    try{
        sock_.shutdown();
    } catch (...) {
        std::cout << "closing failed: connection already closed" << std::endl;
    }
}