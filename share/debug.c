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

// void print_nodeinfo(t_node *node)
// {
//     t_narg *current;

//     if(node->type == ND_COMMAND)
//     {
//         printf("ND_COMMAND:");
//         if(node->red.type)
//         {
//             printf("[redirect:%i filename:%s] ", node->red.type, node->red.filename);
//         }
//         current = node->args;
//         while(current)
// 	    {
//             printf("%s(quotation_state: %i, flag=%i) ", current->val, current->q_state, current->flag_cat);
// 		    current = current->next;
// 	    }
//         printf("\n");
//     }
// }

void print_nodeinfo(t_node *node)
{
    t_narg *current;

    if(node->type == ND_COMMAND)
    {
        printf("ND_COMMAND:\n");
        if(node->red)
            print_red_info(node->red);
        current = node->args;
        printf("-----------Command Info-----------\n");
        while(current)
	    {
            printf("%s(quotation_state: %i, flag=%i) ", current->val, current->q_state, current->flag_cat);
		    current = current->next;
	    }
        printf("\n");
    }
}

void print_red_info(t_nred *head)
{
    t_nred *tmp;
    t_narg *arg_tmp;

    tmp = head;
    printf("----------Redirection Info----------\n");
    while(tmp)
    {
        if(tmp->type == ND_HEREDOC)
        {
            arg_tmp = tmp->delimiter;
            while(arg_tmp)
            {
                printf("Here_Doc: %s is delimiter\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
            if(tmp->infile_head)
                print_heredoc(tmp->infile_head);
        }
        else if (tmp->type == ND_INPUT)
        {
            arg_tmp = tmp->filename;
            while(arg_tmp)
            {
                printf("Input: %s is infline_name\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
        }
        else if (tmp->type == ND_OUTPUT)
        {
            arg_tmp = tmp->filename;
            while(arg_tmp)
            {
                printf("Output: %s is outfline_name\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
        }
        else 
        {
            arg_tmp = tmp->filename;
            while(arg_tmp)
            {
                printf("Append: %s is outfline_name\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
        }
        tmp = tmp->next;
    }
}

void print_heredoc(t_narg *head)
{
    t_narg *tmp;

    tmp = head;
    printf("-----------Here_Doc-----------\n");
    while(tmp)
    {
        printf("%s(quotation_state: %i, flag=%i) \n", tmp->val, tmp->q_state, tmp->flag_cat);
        tmp = tmp->next;
    }
    printf("--------------END--------------\n");
}

void print_final_state(t_node *tree)
{
    if(tree->type == ND_PIPE)
        printf("ND_PIPE\n{\n");
    if(tree->lhs)
		print_final_state(tree->lhs);
    print_final_info(tree);
	if(tree->rhs)
		print_final_state(tree->rhs);
    if(tree->type == ND_PIPE)
        printf("}\n");
}

void print_final_info(t_node *node)
{
    int i;

    if(node->type == ND_COMMAND)
    {
        printf("ND_COMMAND:\n");
        if(node->red)
            print_red_info_final(node->red);
        printf("-----------Command Info-----------\n");
        i = 0;
        while(node->argument && node->argument[i])
	    {
            printf("%s", node->argument[i]);
		    printf(" ");
            i++;
	    }
        printf("\n");
    }
}

void print_red_info_final(t_nred *head)
{
    t_nred *tmp;
    t_narg *arg_tmp;
    int i;

    tmp = head;
    printf("----------Redirection Info----------\n");
    while(tmp)
    {
        if(tmp->type == ND_HEREDOC)
        {
            arg_tmp = tmp->delimiter;
            while(arg_tmp)
            {
                printf("Here_Doc: %s is delimiter\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
            if(tmp->here_doc)
            {
                i = 0;
                printf("-----------Here_Doc-----------\n");
                while(tmp->here_doc && tmp->here_doc[i])
	            {
                    printf("%s\n", tmp->here_doc[i]);
                    i++;
	            }
                printf("--------------END--------------\n");
            }
                
        }
        else if (tmp->type == ND_INPUT)
        {
            arg_tmp = tmp->filename;
            while(arg_tmp)
            {
                printf("Input: %s is infline_name\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
        }
        else if (tmp->type == ND_OUTPUT)
        {
            arg_tmp = tmp->filename;
            while(arg_tmp)
            {
                printf("Output: %s is outfline_name\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
        }
        else 
        {
            arg_tmp = tmp->filename;
            while(arg_tmp)
            {
                printf("Append: %s is outfline_name\n", arg_tmp->val);
                arg_tmp = arg_tmp->next;
            }
        }
        tmp = tmp->next;
    }
}