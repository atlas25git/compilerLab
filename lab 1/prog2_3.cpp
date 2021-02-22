#include <stdio.h> 
#include <string.h> 

// dfa tells the number associated 
// string end in which state. 
int dfa = 0; 

// This function is for 
// the starting state (Q0)of DFA 
void start(char c) 
{ 
	if (c == 'a') { 
		dfa = 1; 
	} 
	else if (c == 'b') { 
		dfa = 2; 
	} 

	// -1 is used to check for any invalid symbol 
	else { 
		dfa = -1; 
	} 
} 

// This function is for the first state (Q1) of DFA 
void state1(char c) 
{ 
	if (c == 'a') { 
		dfa = 1; 
	} 
	else if (c == 'b') { 
		dfa = 3; 
	} 
	else { 
		dfa = -1; 
	} 
} 

// This function is for the second state (Q2) of DFA 
void state2(char c) 
{ 
	if (c == 'b') { 
		dfa = 2; 
	} 
	else if (c == 'a') { 
		dfa = 1; 
	} 
	else { 
		dfa = -1; 
	} 
} 

// This function is for the third state (Q3)of DFA 
void state3(char c) 
{ 
	if (c == 'b') { 
		dfa = 4; 
	} 
	else if (c == 'a') { 
		dfa = 1; 
	} 
	else { 
		dfa = -1; 
	} 
} 

// This function is for the fourth state (Q4) of DFA 
void state4(char c) 
{ 
	if (c == 'b') { 
		dfa = 2; 
	} 
	else if (c == 'a') { 
		dfa = 1; 
	} 
	else { 
		 dfa = -1;
	} 
} 

int isAccepted(char str[]) 
{ 
	// store length of string 
	int i, len = strlen(str); 

	for (i = 0; i < len; i++) { 
		if (dfa == 0) 
			start(str[i]); 

		else if (dfa == 1) 
			state1(str[i]); 

		else if (dfa == 2) 
			state2(str[i]); 

		else if (dfa == 3) 
			state3(str[i]); 

		else if (dfa == 4) 
			state4(str[i]); 
		else
			return 0; 
	} 
	if (dfa == 4) 
		return 1; 
	else
		return 0; 
} 

// driver code 
int main() 
{ 
	char str[] = "aabaaba"; 
	if (isAccepted(str)) 
		printf("ACCEPTED"); 
	else
		printf("NOT ACCEPTED"); 
	return 0; 
} 

