%option noyywrap
%{
/*
 * We now build a lexical analyzer to be used by a higher-level parser.
 */

/* #include "y.tab.h"  */   /* token codes from the parser */

#define   LOOKUP 0   /* default - not a defined word type. */



enum {
            VERB,
      ADJECTIVE,
      ADVERB,
      NOUN,
      PREPOSITION,
      PRONOUN,
      CONJUNCTION
};



int state;

%}

%%

\n    { state = LOOKUP; }

\.\n  {     state = LOOKUP;
            return 0;  /* end of sentence */
      }

^verb { state = VERB; }
^adj  { state = ADJECTIVE; }
^adv  { state = ADVERB; }
^noun { state = NOUN; }
^prep { state = PREPOSITION; }
^pron { state = PRONOUN; }
^conj { state = CONJUNCTION; }

[a-zA-Z]+ {
           if(state != LOOKUP) {
            add_word(state, yytext);
           } else {
            switch(lookup_word(yytext)) {
            case VERB:
              return(VERB);
            case ADJECTIVE:
              return(ADJECTIVE);
            case ADVERB:
              return(ADVERB);
            case NOUN:
              return(NOUN);
            case PREPOSITION:
              return(PREPOSITION);
            case PRONOUN:
              return(PRONOUN);
            case CONJUNCTION:
              return(CONJUNCTION);
            default:
              printf("%s: don't recognize\n", yytext);
              /* don't return, just ignore it */
            }
            }
          }
.    ;

%%