// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

using std::cin; using std::cout;
using ull = unsigned long long;
using pii = std::pair<int, int>;
const int INF = std::numeric_limits<int>::max();

enum {VAR, PLUS, MINUS, MUL, DIV, LPAREN, RPAREN, NONE};
struct Token
{
	int type;
	char var;
};
class Lexer
{
public:
	Lexer () : pos(0), currChar(0) { this->exp = std::string(); }
	Lexer(const std::string &str)
	{
		this->exp = str;
		this->pos = 0;
		this->currChar = this->exp[pos];
	}
	char getChar() { return this->currChar; }
	int getPos() { return this->pos; }

	void advance()
	{
		++pos;
		if(pos > exp.length()-1) currChar = '\0';
		else currChar = exp[pos];
	}
	Token getNext()
	{
		char ch = currChar;
		advance();
		if(isVar(ch)) return {VAR,ch};
		else if(ch == '+') return {PLUS,ch};
		else if(ch == '-') return {MINUS,ch};
		else if(ch == '*') return {MUL,ch};
		else if(ch == '/') return {DIV,ch};
		else if(ch == '(') return {LPAREN,ch};
		else if(ch == ')') return {RPAREN,ch};
		return {NONE,ch};
	}
private:
	std::string exp;
	int pos;
	char currChar;

	bool isVar(char ch) { return 'A'<=ch && ch<='Z'; }
};
class Parser
{
public:
	Parser() {}
	Parser(const Lexer &lex)
	{
		this->lex = lex;
		token = this->lex.getNext();
	}

	void eat()
	{
		token = lex.getNext(); 
	}
	void factor()
	{
		char var = token.var;
		if(token.type == VAR)
		{
			eat();
			cout << var;
		}
		else if(token.type == LPAREN)
		{
			eat();
			expr();
			eat();
		}
	}
	void term()
	{
		factor();
		while(token.type == MUL || token.type == DIV)
		{
			char var = token.var;
			if(token.type == MUL)
			{
				eat();
				factor();
				cout << var;
			}
			else if(token.type == DIV)
			{
				eat();
				factor();
				cout << var;
			}
		}
	}
	void expr()
	{
		term();
		while(token.type == PLUS || token.type == MINUS)
		{
			char var = token.var;
			if(token.type == PLUS)
			{
				eat();
				term();
				cout << var;
			}
			else if(token.type == MINUS)
			{
				eat();
				term();
				cout << var;
			}
		}
	}
private:
	Lexer lex;
	Token token;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	std::string str; cin >> str;
	Lexer lex(str);
	Parser parse(lex);
	parse.expr();
}//g++ -o a -std=c++11 *.cpp