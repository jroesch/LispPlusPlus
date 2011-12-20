lisp: LispInterpreter.o LispToken.o
	g++ Lisp.cpp LispInterpreter.o LispToken.o -o lisp
	
LispInterpreter.o: 
	g++ LispInterpreter.cpp -c
	
LispToken.o:
	g++ LispToken.cpp -c

clean:
	rm *.o