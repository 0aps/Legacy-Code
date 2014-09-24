// pocoClient.cpp
//
#include <stdlib.h>
#include <cstring>
#include "connectionHandler.h"
#include "../encoder/encoder.h"
#include "../encoder/utf8.h"

/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl;
        return -1;
    }
    std::string host = argv[1];
    short port = atoi(argv[2]);
    
    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }
	
	// We will send now  A Greek string encoded in UTF-8 to the server and get it back. We will play with this string a little:
	Poco::UTF8Encoding utf8Encoding;
	Encoder encoder(utf8Encoding);
	// A Greek string encoded in UTF-8		
	// 20 = space                   = 0020 
	// ce ba = kappa                = 03ba
	// e1 bd b9 = omicron with oxia = 1f79
	// cf 83 = sigma                = 03c3
	// ce bc = mu                   = 03bc
	// ce b5 = epsilon              = 03b5 
	unsigned char greek[] = {0x20, 0xce, 0xba, 0xe1, 0xbd, 0xb9, 0xcf, 
								 0x83, 0xce, 0xbc, 0xce, 0xb5, 0x20, 0x0a, 0x00};
	std::string utf8g = encoder.fromBytes((const char*)greek);
	
	// This will not print nicely in your console because consoles do not like UTF-8
	// But if you redirect to a file and open it in a text editor in UTF-8 - it will show nicely
	// for example, in Notepad it shows nicely in Greek.
	std::cout << "Greek string " << utf8g << std::endl;
	
	// This conversion will fail because there are no ASCII characters that 
	// correspond to Greek ones.  It will print '?' for each unknown character.
	Poco::ASCIIEncoding target;
	std::cout << "confused greek string " 
				<< encoder.fromBytes((const char*)greek, target) 
				<< std::endl;

	// Get the string length in number of character (counts the UTF-8 characters in the string and not the bytes)
	int lg = (int)utf8::distance(utf8g.begin(), utf8g.end());
	std::cout << "Length of greek is " << lg << " UTF-8 chars in " << strlen(utf8g.c_str()) << " bytes" << std::endl;
	
	//send the string to the server:
	if (!connectionHandler.sendBytes(utf8g.c_str(),strlen(utf8g.c_str()))) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			return 1;
	}
	//get the echo back from the server as simple bytes:
	char greekEcho[256];
	if (!connectionHandler.getBytes(greekEcho, strlen(utf8g.c_str()))) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			return 1;
	}
	
	// A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
	// we filled up to the \n char - we must make sure now that a 0 char is also present. So we replace \n with 0.
	// strlen(answer) counts the chars until the 0 char is found.
	greekEcho[strlen(utf8g.c_str())]='\0';
	// This will not print nicely in your console because consoles do not like UTF-8
	// But if you redirect to a file and open it in a text editor in UTF-8 - it will show nicely
	// for example, in Notepad it shows nicely in Greek.
	std::cout << "Greek echo string " << greekEcho << std::endl;
	
	std::string utf8gEcho = encoder.fromBytes((const char*)greekEcho);
	// This conversion will fail because there are no ASCII characters that 
	// correspond to Greek ones.  It will print '?' for each unknown character.
	std::cout << "confused greek echo string " 
				<< encoder.fromBytes((const char*)greekEcho, target) 
				<< std::endl;

	// Get the string length in number of character (counts the UTF-8 characters in the string and not the bytes)
	lg = (int)utf8::distance(utf8gEcho.begin(), utf8gEcho.end());
	std::cout << "Length of greek echo is " << lg << " UTF-8 chars in " << strlen(utf8gEcho.c_str()) << " bytes" << std::endl;
	
	
	
	// Convert utf8 string to a utf-16 string
	utf16string utf16gEcho;
	utf8::utf8to16(utf8gEcho.begin(), utf8gEcho.end(), std::back_inserter(utf16gEcho));
	// Output the utf-16 to a file so that we can check it in a text editor
	encoder.writeUtf16File("output-utf16.txt", utf16gEcho);
	encoder.writeUtf8File("output-utf8.txt", utf8gEcho);
	//now you can open these files and see that you can read the Greek letters, and that both files are the same (except for the encoding of course).
	
	
	std::cout << "This is the end of the utf8 test. From now on - Standard echo client\n";
	//From here we will see the rest of the ehco client implementation:
    while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
		std::string line(buf);
		int len=line.length();
        if (!connectionHandler.sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        std::cout << "Sent " << len << " bytes to server" << std::endl;

 
        // We can use one of three options to read data from the server:
        // 1. Read a fixed number of characters
        // 2. Read a line (up to the newline character using the getline() buffered reader
        // 3. Read up to the null character
        std::string answer;
        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
        
		// A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
		// we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len);
        std::cout << "Reply: " << answer << " " << answer.length() << " bytes " << std::endl;
        if (answer == "bye") {
            std::cout << "Exiting...\n" << std::endl;
            break;
        }
    }
    return 0;
}
