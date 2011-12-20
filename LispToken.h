#pragma once
#include <iostream>
using namespace std;
#define ZERO 48
#define NINE 57
#define DOUBLEQUOTE '"'
#define SINGLEQUOTE '\''
#define LOWER_CASE_A 'a'
#define LOWER_CASE_Z 'z'
#define UPPER_CASE_A 'A'
#define UPPER_CASE_Z 'Z'

class LispToken {
public:
	LispToken();
	LispToken(const LispToken& other);
	LispToken operator=(const LispToken& other);
	static LispToken* newToken(string token);
	string getType() const;
	string getToken() const ;
	virtual void print();
protected:
	string type, token;
};

class SymbolToken: public LispToken {
public:
	//static const string TYPE;
	SymbolToken(string token);
	void print();
};

//const string SymbolToken::TYPE = "SYMBOL";

class StringToken: public LispToken {
public:
	//static const string TYPE;
	StringToken(string token);
	void print();
};

//const string StringToken::TYPE = "STRING";

class NumericToken: public LispToken {
public:
    	//static const string TYPE;
	NumericToken(string token);
	void print();
};

//const string NumericToken::TYPE = "NUMERIC";

class CharacterToken: public LispToken {
public:
    	//static const string TYPE;
	CharacterToken(string token);
	void print();
};

//const string CharacterToken::TYPE = "CHARACTER";

class ParenToken: public LispToken {
public:
	//static const string TYPE;
	ParenToken(string token);
	void print();
};

//const string ParenToken::TYPE = "PAREN";
