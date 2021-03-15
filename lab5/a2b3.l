%{ 
%} 

%s A B C DEAD 
%option noyywrap
%% 
<INITIAL>a BEGIN A; 
<INITIAL>b BEGIN B; 
<INITIAL>[^ba\n] BEGIN DEAD; 
<INITIAL>\n BEGIN INITIAL; {printf("Not Accepted\n");} 

<A>a BEGIN INITIAL; 
<A>b BEGIN C; 
<A>[^ba\n] BEGIN DEAD; 
<A>\n BEGIN INITIAL; {printf("Not Accepted\n");} 

<B>a BEGIN C; 
<B>b BEGIN INITIAL; 
<B>[^ba\n] BEGIN DEAD; 
<B>\n BEGIN INITIAL; {printf("Accepted\n");} 

<C>a BEGIN B; 
<C>b BEGIN A; 
<C>[^ba\n] BEGIN DEAD; 
<C>\n BEGIN INITIAL; {printf("Not Accepted\n");} 


<DEAD>[^\n] BEGIN DEAD; 
<DEAD>\n BEGIN INITIAL; {printf("Invalid\n");} 

%% 

int main() 
{ 
	printf("Enter String\n"); 
	yylex(); 
	return 0; 
} 
