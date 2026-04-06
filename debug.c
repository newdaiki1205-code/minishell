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
	while (tokens)
	{
        printf("Type: %d\n", tokens->type);
		printf("Quote: %d\n", tokens->quote);
		printf("Value: %s\n", tokens->value);
		printf("\n");
		tokens = tokens->next;
	}
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
            printf("%s(quotation_state: %i) ", node->args->val, node->args->q_state);
		    node->args = node->args->next;
	    }
        printf("\n");
    }
}