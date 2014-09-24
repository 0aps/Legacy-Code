#include <string>
#include "Poco/TextEncoding.h"
#include "Poco/TextConverter.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/ASCIIEncoding.h"
#include "utf8.h"

// Known POCO encodings:
// UTF-8, ASCII, Latin1, Latin9, Windows1252

// sizeof(wchar_t) is 4 bytes in Linux
// sizeof(wchar_t) is 2 bytes in Windows
// To avoid ambiguity, define a utf16 string instead of using wstring.
typedef std::basic_string<utf8::uint16_t> utf16string;
typedef std::basic_string<utf8::uint8_t> utf8string;

class Encoder {
private:
  Poco::TextEncoding& encoding;

public:
  //Encoder();
  Encoder(Poco::TextEncoding& enc);
  virtual ~Encoder() { }

  // In C++, there is no "byte" type - so we use "char"
  const char* toBytes(const std::string& s);
 
  // Assume the bytes in buf are encoded in our encoding
  std::string fromBytes(const char* buf);
 
  // Assume the bytes in buf are encoded in a different charset
  // We must convert to our encoding.
  std::string fromBytes(const char* buf, Poco::TextEncoding& srcEncoding);
  
  void readUtf8File(const char* filename);
  void writeUtf16File(const char* filename, const utf16string& s);
  void writeUtf8File(const char* filename, const std::string& s);
 };
