all: testLinkedString handle_signals my_shell
EXES = testLinkedString handle_signals my_shell
OBJECTS = testLinkedString String.o handle_signals my_shell

my_shell: myShell.cc
	g++ myShell.cc -o my_shell -w

handle_signals: handleSignals.cc
	g++ handleSignals.cc -o handle_signals -w

testLinkedString: String.o testLinkedString.cpp
	g++ String.o testLinkedString.cpp -o testLinkedString -w

String.o: String.cpp String.h
	g++ -c String.cpp -w

clean:
	rm $(OBJECTS)

strip:
	strip $(EXES)