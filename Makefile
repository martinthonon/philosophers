.DELETE_ON_ERROR:
.SILENT:

COLOR_RESET = \033[0m
COLOR_GREEN = \033[32m

NAME:= philo

BUILD_DIR:= build
SRCS_DIR:= srcs
INC_DIR:= includes

SRCS_PHILO:= main \
				init/arg_init \
				init/container_init \
				init/list_init \
				init/mutex_init \
				init/thread_init \
				list/list_add_back \
				list/list_destroy \
				list/list_new \
				process/eat \
				process/process \
				process/routine \
				process/sleep \
				process/think \
				utils/free \
				utils/str_to_num

SRCS:=	${addprefix ${SRCS_DIR}/, ${addsuffix .c, ${SRCS_PHILO}}}

OBJS:=	${SRCS:%.c=${BUILD_DIR}/%.o}

DEPS:=	${OBJS:.o=.d}

CFLAGS:= -Wall -Wextra -Werror -Wuninitialized -Winit-self -Wshadow -Wdouble-promotion -Wundef -fno-common -Wconversion -Os -g3 -O3

SANITIZE:= -fsanitize=address -g3 -O3 -fno-omit-frame-pointer

CPPFLAGS:= ${addprefix -I,${INC_DIR}} -MMD -MP

RM:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${OBJS} ${SANITIZE} -o $@
	@printf "$(COLOR_GREEN)Compilation completed.$(COLOR_RESET)\n"

${BUILD_DIR}/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) ${CFLAGS} ${SANITIZE} -c $< -o $@

clean:
	${RM} ${BUILD_DIR}
	@printf "$(COLOR_GREEN)Objects cleaned.$(COLOR_RESET)\n"

fclean: clean
	${RM} ${NAME}
	@printf "$(COLOR_GREEN)executables cleaned.$(COLOR_RESET)\n"

re: fclean all

.PHONY:	all clean fclean re

-include ${DEPS}