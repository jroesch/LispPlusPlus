#include <iostream>
#include <list>
#include <cstring>
#include <istream>
#include "LispInterpreter.h"
using namespace std;

int main() {
	char input[512];
	cin.getline(input, 511);
	list<LispToken*> t = LispInterpreter::lex(input);
	LispInterpreter::printTokens(t);
}

