#include "minishell.h"

int main(int ac, char **av, char **env)
{
    t_list shell;
    shell.env_var = copy_env(env);
    while(1)
    {
        display_prompt(shell);
    }
    
}