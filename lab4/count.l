%{

int charcount=0,linecount=0;
%}
%%
. charcount++;
\n {linecount++; charcount++;}
%%
int main(void)
{
yylex();
printf("There were %d characters in %d lines\n",charcount,linecount);

 return 0;
}

        int yywrap()
        {
              return 1;
        }