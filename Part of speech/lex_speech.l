%option noyywrap
%{


/* This first section, the definition section. In section header files of c program */


%}
%%        /* The %% marks the end of this section. */




[\t ]+                    /* ignore whitespace */ ;
is |
am |
are |
were |
was |
be |
being |
been |
do |
does |
did |
will |
would |
should |
can |
could |
has |
have |
had |
go       { printf("%s: is a verb\n", yytext); }

very |
simply |
gently |
quietly |
calmly |
angrily   { printf("%s: is an adverb\n", yytext); }

to |
from |
behind |
above |
below |
between |
below     { printf("%s: is a preposition\n", yytext); }

if |
then |
and |
but |
or       { printf("%s: is a conjunction\n", yytext); }

their |
my |
your |
his |
her |
its      { printf("%s: is a adjective\n", yytext); }

I |
you |
he |
she  |
we  |
they       { printf("%s: is a pronoun\n", yytext); }


[a-zA-Z]+ {
       printf("%s:  don't recognize, might be a noun\n", yytext);
      }
.|\n        { ECHO;/* normal default anyway */ }





%%     /* The end of the rules section is delimited by another %%. */


/* The final section is the user subroutines section, which can consist of any legal C code.  */

main()
{
     yylex();
     
     /* The lexer produced by lex is a C routine called yylex(), 
     so we call it.[2] Unless the actions contain explicit return statements, 
     yylex() won�t return until it has processed the entire input. */
}