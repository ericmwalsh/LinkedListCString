//String.h
#include <iostream>
#include <fstream> // for doing file I/O
using namespace std;


#ifndef string
#define string

class String{

private:
    bool inBounds(int i){
        return i>=0 && i<length();
    }
    struct ListNode{
        char info;
        ListNode * next;
        ListNode(char newInfo)
            : info( newInfo ), next( NULL )
        {
        }
        ListNode(char newInfo, ListNode * newNext)
            : info( newInfo ), next( newNext )
        {
        }
        ~ListNode(){
            delete next;
        }

    };
    ListNode * head;
public:
    String(const char *s = "");
    String(const String &s);
    String operator = (const String &s);
    char & operator [] (const int index);
    int length() const;
    int indexOf(char c) const;
    bool operator == (const String &s) const;
    String operator + (const String &s) const;
    String operator += (const String &s);
    void error(const char *s);
    void print(ostream & out) const;
    void read(istream & in);
    ~String();
};
ostream & operator << ( ostream & out, String str );
istream & operator >> ( istream & in, String & str );

#endif // string