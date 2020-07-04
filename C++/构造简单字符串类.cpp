#include <iostream>
#include <cstdlib>
#include <cstring>
#ifndef _MSC_VER
#define strcpy_s(DST,SIZE,SRC) strcpy((DST),(SRC))
#endif
using namespace std;

struct String
{
private:
    size_t length;
    char* buffer;

public:
    String() : length{ 0 },  buffer{ new char [1]{'\0'} }
    {
    }

    String(const char* theBuffer) : length{ strlen(theBuffer) }, buffer{ new char[length + 1]}
    {
        strcpy_s(buffer, length + 1, theBuffer);     
    }

    String(const String& theString) : length{ theString.length }, buffer{ new char[theString.length + 1] }
    {
        strcpy_s(buffer, length + 1, theString.buffer);
    }

    ~String()
    {
        delete[] buffer;
    }

    String& operator=(const String& theString)
    {
        if (this != &theString)
        {
            delete[] buffer;
            length = theString.length;
            buffer = new char[length + 1];
            strcpy_s(buffer, length + 1, theString.buffer);
        }
        return *this;
    }

    const char* GetBuffer()const
    {
        return buffer;
    }

    size_t GetLength()const
    {
        return length;
    }
};

#define JSK_ASSERT(EXPRESSION) if(!(EXPRESSION)) throw 0;

int main()
{
    {
        String s;
        JSK_ASSERT(s.GetBuffer() != nullptr);
        JSK_ASSERT(s.GetBuffer()[0] == '\0');
        JSK_ASSERT(s.GetLength() == 0);
    }
    {
        String s = "This is a string!";
        JSK_ASSERT(s.GetBuffer() != nullptr);
        JSK_ASSERT(strcmp(s.GetBuffer(), "This is a string!") == 0);
        JSK_ASSERT(s.GetBuffer()[17] == '\0');
        JSK_ASSERT(s.GetLength() == 17);
    }
    {
        String s = "This is a string!";
        String t = s;
        JSK_ASSERT(t.GetBuffer() != nullptr);
        JSK_ASSERT(s.GetBuffer() != t.GetBuffer());
        JSK_ASSERT(s.GetLength() == t.GetLength());
        JSK_ASSERT(strcmp(s.GetBuffer(), t.GetBuffer()) == 0);
    }
    {
        String s = "This is a string!";
        s = s;
        JSK_ASSERT(s.GetBuffer() != nullptr);
        JSK_ASSERT(strcmp(s.GetBuffer(), "This is a string!") == 0);
        JSK_ASSERT(s.GetBuffer()[17] == '\0');
        JSK_ASSERT(s.GetLength() == 17);
    }
    {
        String s = "This is a string!";
        String t;
        t = s;
        JSK_ASSERT(t.GetBuffer() != nullptr);
        JSK_ASSERT(s.GetBuffer() != t.GetBuffer());
        JSK_ASSERT(s.GetLength() == t.GetLength());
        JSK_ASSERT(strcmp(s.GetBuffer(), t.GetBuffer()) == 0);
    }
    return 0;
}