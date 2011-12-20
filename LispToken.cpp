#include "LispToken.h"

LispToken::LispToken() {
	token = "";
	type = "";
}

LispToken::LispToken(const LispToken& other ) {
    token = other.getToken();
    type = other.getType();
}

LispToken LispToken::operator=(const LispToken& other) {
    this->token = other.getToken();
    this->type = other.getType();
    return *this;
}

LispToken* LispToken::newToken(string token) {
	//cout << "TOKEN:" << token << endl;
    long last = token.size() - 1;
    if(((LOWER_CASE_A <= token[0]) && (token[0] <= LOWER_CASE_Z)) || 
       ((UPPER_CASE_A <= token[0]) && (token[0] <= UPPER_CASE_Z))) {
		   return new SymbolToken(token);
    } else if(token[0] == DOUBLEQUOTE ) { //string literal
        if(token[last] == DOUBLEQUOTE) {
			//slices over the "" from the string literal
            return new StringToken(token.substr(1,token.size()-2));
        } else 
            throw "Malformed String";
    } else if((ZERO <= token[0]) && (token[0] <= NINE)) { //numeric literal
        if((ZERO <= token[last]) && (token[last] <= NINE)) {
            return new NumericToken(token);
        } else
            throw "Malformed Numeric";
    } else if(token[0]  == SINGLEQUOTE) {
		//num of characters in a char literal 'g'
        if(token[last] == SINGLEQUOTE  && token.size() == 3) { 
            return new CharacterToken(token);
        } else
            throw "Malformed Character";
	} else {
        return new ParenToken(token);
	}
}

/* General Implementation, Should be Overriden */
void LispToken::print() {
	cout << '[' << this->type << ": " << this->token << ']';
}

string LispToken::getType() const {
	return this->type;
}

string LispToken::getToken() const {
	return this->token;
} 

/* SymbolToken */
SymbolToken::SymbolToken(string token) {
    this->token = token;
    this->type = "SYMBOL";
}

void SymbolToken::print() {
    cout << '[' << this->type << ": " << this->token << ']';
}
/* SymbolToken End */

/* StringToken */
StringToken::StringToken(string token) {
    this->token = token;
    this->type = "STRING";
}

void StringToken::print() {
    cout << '[' << this->type << ": " << '"' << this->token << '"' << ']';
}
/* StringToken End */

/* NumericToken */
NumericToken::NumericToken(string token) {
    this->token = token;
    this->type = "NUMERIC";
}

void NumericToken::print() {
    cout << '[' << this->type << ": " << this->token << ']';
}
/* NumericToken End */

/* CharacterToken */
CharacterToken::CharacterToken(string token) {
    this->token = token;
    this->type = "CHARACTER";
}

void CharacterToken::print() {
    cout << '[' << this->type << ":" << "'" << this->token << "'" << ']';
}
/* CharacterToken End */

/* ParenToken */
ParenToken::ParenToken(string token) {
	this->token = token;
	this->type = "PAREN";
}

void ParenToken::print() {
	cout << '[' << this->type << ":" << this->token << ']';
}
/* ParenToken End */

