#include "tokenize.h"

int is_ope(char c)
{
	if(c == '>' || c == '<' || c == '|')
		return 1;
	return 0;
}

int ope_continue(char *c)
{
	if (*c == '<' && *(c + 1) == '<')
		return 1;
	else if (*c == '>' && *(c + 1) == '>')
		return 1;
	return 0;
}

int is_space(char c)
{
    if(c < 33 || c > 127 )
        return 1;
    return 0;
}

int is_quote(char c)
{
    if(c == 34 || c == 39)
        return 1;
    return 0;
}