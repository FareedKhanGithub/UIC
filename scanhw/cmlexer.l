
/**********************/
/* C header files */
/**********************/

%{
#include "globals.h" //dont change  local directories this is the first 
#include "cmparser.tab.h"   //dont change
 
char tokenString[TOKENMAX];      //wasnt CHar supposed to ignored
int printoutScan = 1;

%}

/**********************/
/* start your regular definitions  here this is the Second part */
/*TRY TO CLASSIFY WHAT EACH ABILITY CAN DO THEN NAME THEM IN THE NEXT STAGE*/



/**********************/
NUMBER		[0-9][0-9]*
ELSE            else
IF              if
INT             int
RETURN          return
VOID            void
WHILE           while
PARENTHESISL    [(]
PARENTHESISR    [)]
BRACEL          [{]
BRACER          [}]
SQUAREBRACKL    [[]
SQUAREBRACKR    []]
SEMICOLON       [;]
COMMA           [,]
ASSIGN          [=]
GREATERTHAN     [>]
LESSERTHAN      [<]
EQUAL           ==
GREATEREQUAL    >=
LESSEREQUAL     <=
NOTEQUAL        !=
PLUS            [+]
MINUS           [-]
MULT            [*]
DIV             [/]
ERROR           break|case|char|const|continue|default|do|for|goto|long|short|register|switch|byte|double|float
ERRORS          [?,!,:,~,&,|,^,<<,>>,>>>,+=,-=,*=,/=,&=,|=,^=,++,%=,<<=,>>=,>>>=]+
WHITESPACE      [ \t\n]
IDENTIFIER      [a-zA-Z_$][a-zA-Z0-9_$]*
COMMENT         "/*"((\*+[^/*])|([^*]))*\**"*/" 


/* start your token specifications here */
/* Token names must come from cmparser.tab.h */
%%
{NUMBER}           { return TOK_NUM; }
{ELSE}             { return TOK_ELSE; }
{IF}               { return TOK_IF;}
{INT}              { return TOK_INT;}
{RETURN}           { return TOK_RETURN;}
{VOID}             { return TOK_VOID;}
{WHILE}            { return TOK_WHILE;}
{PARENTHESISL}     { return TOK_LPAREN;}
{PARENTHESISR}     { return TOK_RPAREN;}
{BRACEL}           { return TOK_LBRACE;}
{BRACER}           { return TOK_RBRACE;} 
{SQUAREBRACKL}     { return TOK_LSQ;}
{SQUAREBRACKR}     { return TOK_RSQ;}
{SEMICOLON}        { return TOK_SEMI;}
{COMMA}            { return TOK_COMMA;}
{ASSIGN}           { return TOK_ASSIGN;}
{GREATERTHAN}      { return TOK_GT;}
{LESSERTHAN}       { return TOK_LT;}
{EQUAL}            { return TOK_EQ;}
{GREATEREQUAL}     { return TOK_GE;}
{LESSEREQUAL}      { return TOK_LE;}
{NOTEQUAL}         { return TOK_NE;}
{PLUS}             { return TOK_PLUS;}
{MINUS}            { return TOK_MINUS;}
{MULT}             { return TOK_MULT;} 
{DIV}              { return TOK_DIV;}
{ERROR}            { return TOK_ERROR;}
{ERRORS}           { return TOK_ERROR;}
{WHITESPACE}       { return TOK_ID;}
{IDENTIFIER}       { return TOK_ID;}
{COMMENT}          { return TOK_ID; }





%%
/**********************/
/* C support functions   THis is the THird */
/**********************/





void printToken(int token, char *str)
{
/* Print the line number, token name and matched lexeme
   -- one per line without any additional characters exactly as below */ 
/* Example  13:TOK_INT: 37*/

    switch(token)
        {
            case TOK_NUM:
                fprintf(yyout,"%d:TOK_NUM: %s\n",yylineno++,str);
                break;
            case TOK_ELSE:
                fprintf(yyout,"%d:TOK_ELSE: %s\n",yylineno++,str);
                break;
            case TOK_IF:
                fprintf(yyout,"%d:TOK_IF: %s\n",yylineno++,str);
                break;
            case TOK_INT:
                fprintf(yyout,"%d:TOK_INT: %s\n",yylineno++,str);
                break;
            case TOK_RETURN:
                fprintf(yyout,"%d:TOK_RETURN: %s\n",yylineno++,str);
                break;
             case TOK_VOID:
                fprintf(yyout,"%d:TOK_VOID: %s\n",yylineno++,str);
                break;
             case TOK_WHILE:
                fprintf(yyout,"%d:TOK_WHILE: %s\n",yylineno++,str);
                break;
            case TOK_LPAREN:
                fprintf(yyout,"%d:TOK_LPAREN: %s\n",yylineno++,str);
                break;
             case TOK_RPAREN:
                fprintf(yyout,"%d:TOK_RPAREN: %s\n",yylineno++,str);
                break;
            case TOK_LBRACE:
                fprintf(yyout,"%d:TOK_LBRACE: %s\n",yylineno++,str);
                break;
            case TOK_RBRACE:
                fprintf(yyout,"%d:TOK_RBRACE: %s\n",yylineno++,str);
                break;      
            case TOK_LSQ:
                fprintf(yyout,"%d:TOK_LSQ: %s\n",yylineno++,str);
                break;
            case TOK_RSQ:
                fprintf(yyout,"%d:TOK_RSQ: %s\n",yylineno++,str);
                break;
            case TOK_SEMI:
                fprintf(yyout,"%d:TOK_SEMI: %s\n",yylineno++,str);
                break;
            case TOK_COMMA:
                fprintf(yyout,"%d:TOK_COMMA: %s\n",yylineno++,str);
                break;
            case TOK_ASSIGN:
                fprintf(yyout,"%d:TOK_ASSIGN: %s\n",yylineno++,str);
                break; 
            case TOK_GT:
                fprintf(yyout,"%d:TOK_GT: %s\n",yylineno++,str);
                break;
            case TOK_LT:
                fprintf(yyout,"%d:TOK_LT: %s\n",yylineno++,str);
                break;
            case TOK_EQ:
                fprintf(yyout,"%d:TOK_EQ: %s\n",yylineno++,str);
                break;
            case TOK_GE:
                fprintf(yyout,"%d:TOK_GE: %s\n",yylineno++,str);
                break;
            case TOK_LE:
                fprintf(yyout,"%d:TOK_LE: %s\n",yylineno++,str);
                break;
            case TOK_NE:
                fprintf(yyout,"%d:TOK_NE: %s\n",yylineno++,str);
                break;
             case TOK_PLUS:
                fprintf(yyout,"%d:TOK_PLUS: %s\n",yylineno++,str);
                break;
             case TOK_MINUS:
                fprintf(yyout,"%d:TOK_MINUS: %s\n",yylineno++,str);
                break;
             case TOK_MULT:
                fprintf(yyout,"%d:TOK_MULT: %s\n",yylineno++,str);
                break;
            case TOK_DIV:
                fprintf(yyout,"%d:TOK_DIV: %s\n",yylineno++,str);
                break;
            case TOK_ERROR:
                fprintf(yyout,"%d:TOK_ERROR: %s\n",yylineno++,str);
                break;
            case TOK_ID:
                break;  
        
        }
}































int gettok(void){
    int currentToken;
    
    currentToken=yylex();
    if (currentToken == 0) { // means EOF}
            return 0;
    }
    strncpy(tokenString, yytext, TOKENMAX);
    if (printoutScan) {
        printToken(currentToken,tokenString);
    }

    return currentToken;
}

int main(int argc, char **argv){

    
   if ( argc > 1 )
       yyin = fopen( argv[1], "r" );
   else
    yyin = stdin;

   while (gettok() !=0); //gettok returns 0 on EOF
    return;
} 
