#include <iostream>
#include <fstream>

int main() {
	using namespace std;

	// Open the input file stream for reading
	wifstream qXoaXFile;
	qXoaXFile.open("XoaX.txt");

	if (qXoaXFile.is_open()) {
		// Read from the file
		wcout << L"Read from file: " << qXoaXFile.rdbuf() << endl;
		qXoaXFile.close();
	} else {
		cout << "\"XoaX.txt\" failed to open" << endl;
		return -1;
	}

	// Keep the window open
	cin.get();
	return 0;
}


size_t GetSizeOfFile(const std::wstring& path)
{
    struct _stat fileinfo;
    _wstat(path.c_str(), &fileinfo);
    return fileinfo.st_size;
}

std::wstring LoadUtf8FileToString(const std::wstring& filename)
{
    std::wstring buffer;            // stores file contents
    FILE* f = _wfopen(filename.c_str(), L"rtS, ccs=UTF-8");

    // Failed to open file
    if (f == NULL)
    {
        // ...handle some error...
        return buffer;
    }

    size_t filesize = GetSizeOfFile(filename);

    // Read entire file contents in to memory
    if (filesize > 0)
    {
        buffer.resize(filesize);
        size_t wchars_read = fread(&(buffer.front()), sizeof(wchar_t), filesize, f);
        buffer.resize(wchars_read);
        buffer.shrink_to_fit();
    }

    fclose(f);

    return buffer;
}            
            
