#include <string>
#include <boost/locale.hpp>
#include "utf8.h"

// sizeof(wchar_t) is 4 bytes in Linux
// sizeof(wchar_t) is 2 bytes in Windows
// To avoid ambiguity, define a utf16 string instead of using wstring.
typedef std::basic_string<utf8::uint16_t> utf16string;
typedef std::basic_string<utf8::uint8_t> utf8string;

class Encoder {
private:

public:
  // In C++, there is no "byte" type - so we use "char"
  const char* toBytes(const std::string& s);
 
  // Assume the bytes in buf are encoded in our encoding
  std::string fromBytes(const char* buf);
 
  // Assume the bytes in buf are encoded in a different charset
  // We must convert to our encoding.
  utf16string fromUtf8ToUtf16(const std::string& source) throw(boost::locale::conv::conversion_error);
  
  // Assume the bytes in buf are encoded in a different charset
  // We must convert to our encoding.
  std::string fromUtf8ToAscii(const std::string& source) throw(boost::locale::conv::conversion_error);
  
  void readUtf8File(const char* filename);
  void writeUtf16File(const char* filename, const utf16string& s);
  void writeUtf8File(const char* filename, const std::string& s);
 };
