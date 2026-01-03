# MiniShell

MiniShell is a simple command-line shell written in C.
It supports basic shell commands and can run programs like a normal terminal.

make        # To build

./minishell # to run  

Available commands inside MiniShell:
ls          # list files and directories
pwd         # print current working directory
cd <dir>    # change directory
echo <text> # print text
env         # display environment variables
export VAR=value # set environment variable
unset VAR   # remove environment variable
exit        # exit the shell

You can also run any external programs available in your system, like cat, grep, date, etc.

Clean:
make clean   # remove object files
make fclean  # remove object files and executable
make re      # rebuild everything

