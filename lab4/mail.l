%option noyywrap
/* scanner for a valid mail ids  */

%{
/* need this for the call to atof() below */
#include <math.h>
%}

DIGIT    [0-9]
ID       [A-Za-z]
TT       [A-Za-z0-9]

%%

{ID}{TT}*"@"{ID}+"."{ID}+   {
            printf( "mail id  %s \n", yytext);
            }

{DIGIT}+"."{DIGIT}+        {
            printf( "A float: %s (%g)\n", yytext,
                    atof( yytext ) );
            }



.           printf( "Unrecognized character: %s\n", yytext );

%%

main( argc, argv )
int argc;
char **argv;
    {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
    }



