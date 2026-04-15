#include "minishell.h"

void debug_parser(t_node *tree)
{
    if(tree->type == ND_PIPE)
        printf("ND_PIPE\n{\n");
    if(tree->lhs)
		debug_parser(tree->lhs);
    print_nodeinfo(tree);
	if(tree->rhs)
		debug_parser(tree->rhs);
    if(tree->type == ND_PIPE)
        printf("}\n");
}

void print_tokeninfo(t_token *tokens)
{
	int i;
    
    i = 1;
    while (tokens)
	{
        printf("TOKEN %i: type=%d qupte=%d flag=%d, value=%s\n", i, tokens->type, tokens->quote, tokens->flag_cat, tokens->value);
        i++;
		tokens = tokens->next;
	}
    printf("\n");
}

void print_nodeinfo(t_node *node)
{
    if(node->type == ND_COMMAND)
    {
        printf("ND_COMMAND:");
        if(node->red.type)
        {
            printf("[redirect:%i filename:%s] ", node->red.type, node->red.filename);
        }
        while(node->args)
	    {
            printf("%s(quotation_state: %i, flag=%i) ", node->args->val, node->args->q_state, node->args->flag_cat);
		    node->args = node->args->next;
	    }
        printf("\n");
    }
}