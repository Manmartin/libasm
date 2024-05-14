# Compilation variables
CC              =   gcc
CFLAGS          =   -g3 -Wall -Wextra -Werror -no-pie -I $(LIBASM_FOLDER) -Dtest_path=\"./$(TESTS_FOLDER)logs/\"

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
LIBASM_FILES    =   ft_strlen.s \
                    ft_strcpy.s \
                    ft_strcmp.s \
                    ft_write.s \
                    ft_read.s \
					ft_strdup.s
SYSCALL_FILE    =   $(addprefix $(LIBASM_FOLDER), syscalls.inc)
SRCS            =   $(addprefix $(LIBASM_FOLDER), $(LIBASM_FILES))
OBJS            =   $(SRCS:.s=.o)

# Tests
TESTS_NAME          	=   tests
TESTS_FILES         	=   tester.c \
                            tester_aux.c \
							test_strlen.c \
                            test_strcpy.c \
                            test_strcmp.c \
					    	test_write.c \
							test_read.c \
							test_strdup.c
TESTS_SRCS      		=   $(addprefix $(TESTS_FOLDER), $(TESTS_FILES))
TESTS_OBJS      		=   $(TESTS_SRCS:.c=.o)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all: $(NAME)
test: $(TESTS_NAME)
	./$(TESTS_NAME) 2> $(TESTS_LOGS_FOLDER)log

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(TESTS_LOGS_FOLDER):
	@ mkdir -p $(TESTS_LOGS_FOLDER)

	@ echo Works! > $(TESTS_LOGS_FOLDER)/good_permission_read
	@ chmod 700 $(TESTS_LOGS_FOLDER)/good_permission_read

	@ touch $(TESTS_LOGS_FOLDER)/bad_permission_read
	@ chmod 333 $(TESTS_LOGS_FOLDER)/bad_permission_read

$(TESTS_NAME): $(NAME) $(TESTS_OBJS) $(TESTS_LOGS_FOLDER)
	$(CC) $(CFLAGS) $(TESTS_OBJS) $(NAME) -o $@


clean:
	$(RM) $(OBJS) $(TESTS_OBJS) $(TESTS_NAME) $(TESTS_LOGS_FOLDER)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
