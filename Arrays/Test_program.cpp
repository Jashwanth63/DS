#include <iostream>
#include <cstring>
#include <string>  
using namespace std;


char *mystrtok(char *s, char delim){
	static char* input = NULL;
	if(s!=NULL){
		input = s;
	}
	if(input == NULL){
		return NULL;
	}
	char *output = new char[strlen(input)+1];
	int i=0;
	for( ;input[i]!='\0'; i++){
		if(input[i] != delim){
			output[i] = input[i];
		}

		else{
			output[i] = '\0';
			input = input+i+1;		
			return output;
			
		}

	}

	input = NULL;
	if(input==NULL){
		output[i] = '\0';
	}

	return output;
}


int main(){
	char s[100] = "This is a string";

	char *ptr = mystrtok(s, ' ');
	cout<<ptr<<endl;
	cout<<s<<endl;
	while(ptr!=NULL){
		ptr = mystrtok(NULL, ' ');
		cout<<ptr<<endl;
		cout<<s<<endl;
	}


	return 0;
}