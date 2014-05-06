//testLinkedString.cpp
#include "String.h"

int main(){
    cout << "Input a string: ";
    String s;
    cin >> s;
    cout << "Here is your string: " << s << endl;
    cout << "Now input another one: ";
    String t;
    cin >> t;
    cout << "Here is your second string: " << t << endl;
    cout << "Now we will temporarily add them together (demonstrating the + operator): " << s+t << endl;
    cout << "Now I'm going to permanently modify the second string by concatenating (+=) the first one to the end of it..." << endl;
    t+=s;
    cout << "Here is string 't': " << t << " ... and here is the unchanged string 's': "<< s << endl;
    String u(t);
    cout << "Now I've made a copy of that string (demonstrating the String copy constructor)... Here it is: " << u << endl;
    cout << "We will now refer to this copied string as 'u'" << endl;
    cout << endl << "I will now modify and compare (using the boolean operators) these two strings." << endl;
    t = "cat";
    u = "catz";
    cout << "Here is 't' now: " << t << endl;
    cout << "And here is 'u' now: " << u << endl;
    cout << "Example of == Operator - 't' should not be equal to 'u' : " << (t==u) << endl;
    cout << "Now 't' is also equal to 'catz' (using the = assignment operator)." << endl;
    t=u;
    cout << "Example of == Operator - 't' and 'u' should be equal now: " << (t==u) << endl;

    cout << endl << "Now we will make 't' become 'warmachine' and 'u' become 'mach'." << endl;
    t="warmachine";
    u="mach";
    cout << "What is the index of the letter r in 't' (warmachine)? It should be 2... : " << t.indexOf('r') << endl;
    cout << "Here is an example of the [] operator - the char at index 2 in 't' should be the letter r: " << t[2] << endl;
    cout << "What is the index of the letter h in 'u' (mach)?  It should be 3... : " << u.indexOf('h') << endl;
    cout << "What is the index of the letter z in 't' (warmachine)?  It should return -1 because there is none: " << t.indexOf('z') << endl;
    cout << "What is the index of null character in 'u' (mach)?  It should return -1 because there is none: " << u.indexOf(NULL) << endl;
    cout << "How many letters are there in 'warmachine' (t) ? It should be 10! : " << t.length() << endl;

    cout << endl << "Last but not least, let's intialize an empty string." << endl;
    String x("");
    cout << "Here is x, the empty string: " << endl;
    cout << "x has a length of : " << x.length() << endl;
    cout << "If we try to find the index of the letter 'a' in the string 'x' it should return -1 because it is an empty string!: " << x.indexOf('a') << endl;
    cout << "If we add the 'hippo' to x, it becomes... : ";
    String y("hippo");
    x+=y;
    cout << x << " and it has a length of " << x.length() << endl;
    cout << "Here is x.indexOf(128) - it should return -1 since there is no Ç in it: " << x.indexOf(128) << endl;
    cout << "That's it!" << endl;
}
