# Compilation variables
CC              =   gcc
CFLAGS          =   -Wall -Wextra -Werror -no-pie -I $(LIBASM_FOLDER) -Dtest_path=\"./$(TESTS_FOLDER)logs/\"

NASM            =   nasm
NASMFLAGS       =   -f elf64 -p $(SYSCALL_FILE)

AR              =   ar
ARFLAGS         =   rc

RM              =   rm -rf

# Folders
SRCS_FOLDER     =   srcs/
TESTS_FOLDER    =   $(addprefix $(SRCS_FOLDER), tests/)
LIBASM_FOLDER   =   $(addprefix $(SRCS_FOLDER), libasm/)

# Library
NAME            =   libasm.a
LIBASM_FILES    =   ft_write.s
SYSCALL_FILE    =   $(addprefix $(LIBASM_FOLDER), syscalls.inc)
SRCS            =   $(addprefix $(LIBASM_FOLDER), $(LIBASM_FILES))
OBJS            =   $(SRCS:.s=.o)

# Tests
TESTS_NAME      =   tests
TESTS_FILES     =   tester.c \
					test_write.c
TESTS_SRCS      =   $(addprefix $(TESTS_FOLDER), $(TESTS_FILES))
TESTS_OBJS      =   $(TESTS_SRCS:.c=.o)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all: $(NAME)
test: $(TESTS_NAME)
	./$(TESTS_NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(TESTS_NAME): $(NAME) $(TESTS_OBJS)
	$(CC) $(CFLAGS) $(TESTS_OBJS) $(NAME) -o $@


clean:
	$(RM) $(OBJS) $(TESTS_OBJS) $(TESTS_NAME)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
