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
    t_narg *current;

    if(node->type == ND_COMMAND)
    {
        printf("ND_COMMAND:");
        if(node->red.type)
        {
            printf("[redirect:%i filename:%s] ", node->red.type, node->red.filename);
        }
        current = node->args;
        while(current)
	    {
            printf("%s(quotation_state: %i, flag=%i) ", current->val, current->q_state, current->flag_cat);
		    current = current->next;
	    }
        printf("\n");
    }
}