#include<iostream>
#include<stack>
using namespace std;

int typeOf(char c){
	if(c == '(' || c == ')') return 0;
	if(c == '[' || c == ']') return 1;
	return 2;
}

bool validParenthesis(string s){
	stack<char> S;
	for(int i=0; i<s.size(); i++)
		if(s[i]=='(' || s[i]=='[' || s[i]=='{')
			S.push(s[i]);
		else
			if(!S.empty() && typeOf(S.top()) == typeOf(s[i]))
				S.pop();

	return S.empty();

}

int main(){
	string s;
	cin>>s;
	bool a = validParenthesis(s);
	if(a==true)
		cout<<"This is a valid parenthesis";
	else
		cout<<"This is not a valid parenthesis";

	return 0;
}