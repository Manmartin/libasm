# Compilation variables
CC              =   gcc
CFLAGS          =   -Wall -Wextra -Werror -no-pie -I $(LIBASM_FOLDER) -Dtest_path=\"./$(TESTS_FOLDER)logs/\"

NASM            =   nasm
NASMFLAGS       =   -f elf64 -p $(SYSCALL_FILE)

AR              =   ar
ARFLAGS         =   rc

RM              =   rm -rf

# Folders
SRCS_FOLDER             =   srcs/
TESTS_FOLDER            =   $(addprefix $(SRCS_FOLDER), tests/)
TESTS_LOGS_FOLDER       =   $(addprefix $(TESTS_FOLDER), logs/)
LIBASM_FOLDER           =   $(addprefix $(SRCS_FOLDER), libasm/)

# Library
NAME            =   libasm.a
LIBASM_FILES    =   ft_write.s \
                    ft_read.s
SYSCALL_FILE    =   $(addprefix $(LIBASM_FOLDER), syscalls.inc)
SRCS            =   $(addprefix $(LIBASM_FOLDER), $(LIBASM_FILES))
OBJS            =   $(SRCS:.s=.o)

# Tests
TESTS_NAME          	=   tests
TESTS_FILES         	=   tester.c \
					    	test_write.c
TESTS_CASES_FILES		=	$(addprefix $(TESTS_LOGS_FOLDER), bad_permission)
TESTS_SRCS      		=   $(addprefix $(TESTS_FOLDER), $(TESTS_FILES))
TESTS_OBJS      		=   $(TESTS_SRCS:.c=.o)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all: $(NAME)
test: $(TESTS_NAME)
	./$(TESTS_NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(TESTS_CASES_FILES):
	mkdir -p $(TESTS_LOGS_FOLDER)
	touch $(TESTS_CASES_FILES)
	chmod 333 $(TESTS_CASES_FILES)

$(TESTS_NAME): $(NAME) $(TESTS_OBJS) $(TESTS_CASES_FILES)
	$(CC) $(CFLAGS) $(TESTS_OBJS) $(NAME) -o $@


clean:
	$(RM) $(OBJS) $(TESTS_OBJS) $(TESTS_NAME) $(TESTS_LOGS_FOLDER)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
