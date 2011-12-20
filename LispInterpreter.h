#pragma once
#include <iostream>
#include <list>
#include <map>
#include "LispToken.h"

using namespace std;
class LispInterpreter {
public:
	static list<LispToken*> lex(char* input);
	static void printTokens(list<LispToken*>);
};
