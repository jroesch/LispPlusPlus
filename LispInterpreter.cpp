#include "LispInterpreter.h"

list<LispToken*> LispInterpreter::lex(char* input) {
	list<LispToken*> tokens;
	long len = strlen(input);
	string accumulator = "";
	bool inString = false;
	bool inChar = false;
	/* Loop through all input */
	for(int i = 0;i <= len;i++) {
		/* Catches Open Parens */
		if(input[i] == '(' ) {
			LispToken* paren = LispToken::newToken(string(input + i, 1));
			tokens.push_back(paren);
		/* Catches Close Parens */
		} else if(input[i] == ')') {
			if(accumulator.size()) {
				LispToken *token =  LispToken::newToken(accumulator);
				tokens.push_back(token);
				accumulator = "";
			}
			LispToken* paren = LispToken::newToken(string(input + i, 1));
			tokens.push_back(paren);
		/* Special Case for Strings */
		} else if(input[i] == '"') {
			if(inString) {
				accumulator += input[i]; 
				LispToken *token =  LispToken::newToken(accumulator);
				tokens.push_back(token);
				accumulator = "";
				inString = false;
			} else {
				inString = true;
				accumulator += input[i];
			}
		} else if(inString) {
			accumulator += input[i];	
		/* Special Case for Characters */
		} else if(input[i] == 39) {
			if(inChar) {
				accumulator += input[i];
				LispToken *token = LispToken::newToken(accumulator);
				tokens.push_back(token);
				accumulator = "";
				inChar = false;
			} else if(!inString){
				inChar = true;
				accumulator += input[i];
			}
		} else if(inChar) {
			accumulator += input[i];
		/* General case for symbols and numbers */
		} else {
			/* if it is a space && the accumlator is filled create new token */
			if (input[i] == ' ') {
				if(accumulator.size()) {
					LispToken *token = LispToken::newToken(accumulator);
					tokens.push_back(token);
					accumulator = "";
				}
			 /* otherwise just append to the char to the accum */
			} else {
				accumulator += input[i];
			}
		}
	}
	return tokens;
}
/* Development Utility prints out all tokens from list of Tokens */
void LispInterpreter::printTokens(list<LispToken*> t) {
	list<LispToken*>::iterator i;
	for(i = t.begin();i != t.end();i++) {
		(**i).print();
	}
	cout << endl; 	
}