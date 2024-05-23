# Compilation variables
CC              =	gcc 
CFLAGS          =   -Wall -Wextra -Werror -std=c2x -no-pie -I $(LIBASM_FOLDER) -Dtest_path=\"./$(TESTS_FOLDER)logs/\"

NASM            =   nasm
NASMFLAGS       =   -f elf64 -p $(SYSCALL_FILE)

AR              =   ar
ARFLAGS         =   rc

RM              =   rm -rf

# MANDATORY
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

# BONUS
# Folders
NAME_BONUS 			= 	.bonus
LIBASM_FOLDER_BONUS	=	$(addprefix $(LIBASM_FOLDER), bonus/)
TESTS_FOLDER_BONUS	=   $(addprefix $(TESTS_FOLDER), bonus/)

# Library
LIBASM_FILES_BONUS	=	ft_atoi_base_bonus.s \
						ft_list_push_front_bonus.s \
						ft_list_size_bonus.s \
						ft_list_sort_bonus.s
SRCS_BONUS          =	$(addprefix $(LIBASM_FOLDER_BONUS), $(LIBASM_FILES_BONUS))
OBJS_BONUS			=	$(SRCS_BONUS:.s=.o)

# Tests
TESTS_NAME_BONUS        =   tests_bonus
TESTS_FILES_BONUS       =   tester_bonus.c \
                            tester_aux_bonus.c \
							test_atoi_base_bonus.c \
							test_list_push_front_bonus.c \
							test_list_size_bonus.c \
							test_list_sort_bonus.c
TESTS_SRCS_BONUS      	=   $(addprefix $(TESTS_FOLDER_BONUS), $(TESTS_FILES_BONUS))
TESTS_OBJS_BONUS      	=   $(TESTS_SRCS_BONUS:.c=.o)

%.o: %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all: $(NAME)
bonus: $(NAME_BONUS)

test: $(TESTS_NAME)
	./$(TESTS_NAME) 2> $(TESTS_LOGS_FOLDER)log

testb: $(TESTS_NAME_BONUS)
	./$(TESTS_NAME_BONUS) 2> $(TESTS_LOGS_FOLDER)log

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(NAME_BONUS): $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $(NAME_BONUS)

$(TESTS_LOGS_FOLDER):
	@ mkdir -p $(TESTS_LOGS_FOLDER)

	@ echo Works! > $(TESTS_LOGS_FOLDER)/good_permission_read
	@ chmod 700 $(TESTS_LOGS_FOLDER)/good_permission_read

	@ touch $(TESTS_LOGS_FOLDER)/bad_permission_read
	@ chmod 333 $(TESTS_LOGS_FOLDER)/bad_permission_read

$(TESTS_NAME): $(NAME) $(TESTS_OBJS) $(TESTS_LOGS_FOLDER)
	$(CC) $(CFLAGS) $(TESTS_OBJS) $(NAME) -o $@

$(TESTS_NAME_BONUS): $(NAME_BONUS) $(TESTS_OBJS_BONUS) $(TESTS_LOGS_FOLDER)
	$(CC) $(CFLAGS) $(TESTS_OBJS_BONUS) $(NAME) -o $@

clean:
	$(RM) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(TESTS_OBJS) $(TESTS_OBJS_BONUS) $(TESTS_NAME) $(TESTS_NAME_BONUS) $(TESTS_LOGS_FOLDER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re test testb
