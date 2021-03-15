%{


%}
%%
[aA][a-zA-Z]*[aA] {printf("Valid");}
. {printf("Invalid");}
%%
int main(void)
{
yylex();


 return 0;
}

        int yywrap()
        {
              return 1;
        }