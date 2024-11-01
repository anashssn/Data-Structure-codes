#include <iostream>
#include <stack>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int check(char c){
	switch(c){
	case '^':
	return 5;
	break;
	case '*':
	return 4;	
	break;
	
case '/':
	return 4;	
	break;
	
	case '+':
	
		
		return 3;
		break;
	
	
	case '-':
	return 3;
		break;
	
	default: 
	
	return 0;
	break;
}
	
}
int main(int argc, char** argv) {
	
	char infix[10];
char 	postfix[10];
	stack <int> s;
	
	infix[0]='a';
	 infix[1]='+';
	 infix[2]='b';
	int j=0;
	for (int i=0;i<11;i++){
		
		if (infix[i]=='\o'){
			cout<<"No value found";
			break;
			
		}
	else if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!=')' && infix[i]!='('){
			postfix[j]=infix[i];
			j++;
			continue;
		}
		else{
			
			if (s.empty() == true){
				s.push(infix[i]);
			}
			else if (check(s.top())>check(infix[i])){
				
				s.push(infix[i]);
				
			}
			
			else {
				
				postfix[j]=s.top();
			s.pop();
			j++;
			}
		}
	}
	
	
	while(s.empty()!=true)
	{
	postfix[j]=s.top();
	s.pop();
	j++;
}
	
	for (int i=0; i<5; i++){
		if (postfix[i] != '\o')
		cout<<postfix[i]<<"\n";

else break;

	}
	return 0;
	
	
}
