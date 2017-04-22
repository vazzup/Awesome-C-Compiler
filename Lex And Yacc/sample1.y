%{
#include "stdio.h"
#include "math.h"
int result=0;
void yyerror(const char *str)
{
fprintf(stderr, "error:%s\n",str);
}

int yywrap(void)
{
return 1;
}

int raise_to(int a, int b) {
	int ans = 1;
	while(b--) {
		ans*=a;
	}
	return ans;
}
%}
%token number plus minus multiply divide modulo power
%left plus minus
%left multiply divide modulo
%right power
%nonassoc UMINUS

%%
ae: exp	{result=$1;}
	;
exp: number {	$$ = $1;}
   | exp minus exp {$$ = $1 - $3;}
   | exp plus exp {$$ = $1 + $3;}
   | exp multiply exp {$$ = $1 * $3;}
   | exp divide exp { if ( $3 == 0 ) yyerror("divide by zero"); else $$ = $1 / $3;}
   | minus exp %prec UMINUS {$$ = -$2; }
   | exp modulo exp { $$ = $1 % $3;} 
   | exp power exp { $$ = raise_to($1, $3);} 
   ;
%%
#include "math.h"
int main(void)
{
yyparse();
printf("=%d",result);
return 0;
} 
