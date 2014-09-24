// encoder.cpp : test encoder functionality
// Use Poco::TextEncoding/TextConverter to convert utf8<->various 8 bit encodings
// Use http://utfcpp.sourceforge.net/ for conversion utf8<->utf16

#include "encoder.h"
#include <iostream>
#include <fstream>

//Encoder::Encoder() : encoding(Poco::UTF8Encoding) {}

Encoder::Encoder(Poco::TextEncoding& enc) : encoding(enc) {}

const char* Encoder::toBytes(const std::string& s) {
    return s.data();
 }

std::string Encoder::fromBytes(const char* buf) {
    return std::string(buf);
}

std::string Encoder::fromBytes(const char* buf, Poco::TextEncoding& srcEncoding) {
    Poco::TextConverter converter(srcEncoding, encoding);
    std::string res;
    converter.convert(std::string(buf), res);
    return res;
}

// Demo: play with content of a UTF-8 file
void Encoder::readUtf8File(const char* filename)
{
  // Open the test file (contains UTF-8 encoded text)
  std::ifstream fs8(filename);
  if (!fs8.is_open()) {
	std::cout << "Could not open " << filename << std::endl;
    return;
  }
  unsigned line_count = 1;
  std::string line;
  // Play with all the lines in the file - this reads line by line
  while (getline(fs8, line)) {
     // check for invalid utf-8 - because some byte sequence might be illegal utf-8 encodings
	 std::string::iterator end_it = utf8::find_invalid(line.begin(), line.end());
     if (end_it != line.end()) {
		std::cout << "Invalid UTF-8 encoding detected at line " << line_count << std::endl;
		std::cout << "This part is fine: " << std::string(line.begin(), end_it) << std::endl;
     }

     // Get the line length (at least for the valid part)
	 int length = (int)utf8::distance(line.begin(), end_it);
	 std::cout << "Length of line " << line_count << " is " << length << std::endl;

	 // Convert to a utf-16 string
	 std::wstring utf16s;
	 utf8::utf8to16(line.begin(), end_it, std::back_inserter(utf16s));

     // And back to utf-8
	 std::string utf8line; 
	 utf8::utf16to8(utf16s.begin(), utf16s.end(), std::back_inserter(utf8line));

     // Confirm that the conversion went OK:
	 if (utf8line != std::string(line.begin(), end_it))
		 std::cout << "Error in UTF-16 conversion at line: " << line_count << std::endl;

     line_count++;
  }
}

// Print a UTF-16 string to a file
void Encoder::writeUtf16File(const char* filename, const utf16string& s)
{
  // Open the test file (will contain UTF-16 encoded text)
  // Because of conversions of newlines you cannot use wofstream - use an ofstream in binary mode.
  std::ofstream outFile(filename, std::ios::out | std::ios::binary);
  outFile.write((char *)s.c_str(), (std::streamsize)(s.length() * sizeof(utf8::uint16_t)));
  outFile.close();
}

void Encoder::writeUtf8File(const char* filename, const std::string& s)
{
  // Open the test file (will contain UTF-8 encoded text)
  // Because of conversions of newlines you cannot use wofstream - use an ofstream in binary mode.
  std::ofstream outFile(filename, std::ios::out | std::ios::binary);
  outFile.write((char *)s.c_str(), (std::streamsize)(s.length() * sizeof(utf8::uint8_t)));
  outFile.close();
}

