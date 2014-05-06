#include "String.h"
const int MAX_STRING_SIZE=2048;

//Regular String Constructor  - for String of length N this is O(N)
String::String(const char* s){
    if(s=="") head=NULL;
    else{
        head = new ListNode(s[0]);
        ListNode * temp = head;
        for(int i=1; s[i]!='\0'; i++){
            temp->next = new ListNode(s[i]);
            temp=temp->next;
        }
    }
}
//Deep-Copy String Constructor - for String of length N this is O(N)
String::String(const String &s){
    head = new ListNode(s.head->info);
    ListNode * temp1 = head;
    ListNode * temp2 = s.head->next;
    while(temp2){
        temp1->next = new ListNode(temp2->info);
        temp1=temp1->next;
        temp2=temp2->next;
    }
}
//Deep-Assignment String Operator  - for String of length N this is O(N)
String String::operator= (const String &s){
    String *  assignment = new String(s);
    delete head;
    head = assignment->head;
    return *this;
}
//+ Operator override for String - returns a new string that has this string concatenated with s - for String of length N this is O(N)
String String::operator + (const String &s) const{
    ListNode * temp1 = head;
    ListNode * temp2 = s.head;
    char myStr[length() + s.length()+1];
    myStr[length() + s.length()]='\0';
    int i=0;
    while(temp1){
        myStr[i]=temp1->info;
        i++;
        temp1=temp1->next;
    }
    while(temp2){
        myStr[i]=temp2->info;
        i++;
        temp2=temp2->next;
    }
    return String(myStr);
}
//+= Operator override for String - concatenates s onto this String  - for String of length N this is O(N)
String String::operator += (const String &s){
    String plusEquals = (*this + s);
    return *this = plusEquals;
}

//Length String method returns an int - for a String w/ N characters, length has O(N)
int String::length() const{
    int ans = 0;
    ListNode * temp = head;
    while(temp){
        ans++;
        temp=temp->next;
    }
    return ans;
}
//[] Operator override for String - returns char at the index - for String of length N this is O(N)
char & String::operator [] (const int index){
    if(index>=length()) error("ERROR - INDEX OUT OF BOUNDS");
    else{
        ListNode * temp = head;
        for(int i=0; i<index; i++) temp=temp->next;
        return temp->info;
    }
}
//== Operator override for String - returns true if all chars are in the same positions - for String of length N this is O(N)
bool String::operator == (const String &s) const{
    if(length()!=s.length()) return false;
    ListNode * temp1 = head;
    ListNode * temp2 = s.head;
    while(temp1){
        if(temp1->info!=temp2->info) return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}
//Returns the index of char c if it is in the String; else returns -1; - for String of length N this is O(N)
int String::indexOf(char c) const{
    int ans = 0;
    ListNode * temp = head;
    while(temp){
        if(temp->info==c) return ans;
        else{
            ans++;
            temp=temp->next;
        }
    }
    return -1;
}
//String Destructor (recursive deletion of nodes implemented via ListNode destructor) - For a String with N letters this is an O(N)
String::~String(){
    delete head;
}
//Error method - O(1)
void String::error(const char *s)
{
     cerr << "Error: " << s << endl;
     throw 0;
}
//For a word with N letters this is O(N)
void String::print(ostream & out) const{
    ListNode * temp = head;
    while(temp){
        out << temp->info;
        temp=temp->next;
    }
}
//Takes the next char * input from the input istream and sets this String to that new string. For word input of size N this is O(N)
void String::read(istream& in){
    delete head;
    char * newBuf = new char[MAX_STRING_SIZE];
    in.getline(newBuf, MAX_STRING_SIZE);
    *this = String(newBuf);
}
//Override << operator to print out String str - For String of string length N the big O is O(N)
ostream & operator << ( ostream & out, String str )
{
     str.print(out);
     return out;
}
//Override >> operator to set String str to the input - For String of string length N the big O is O(N)
istream & operator >> ( istream & in, String & str )
{
     str.read(in);
     return in;
}
/**
int main(){
    String s("Hello");
    String t("There");
    cout << s << endl;
    cout << t << endl;
    cout << s+t << endl;
    s = s + t;  // assignment 1
    cout << "Finally... " << s << endl;
    s += t;     // assignment 2
    cout << s << endl;
}
**/