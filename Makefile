.DELETE_ON_ERROR:
.SILENT:

COLOR_RESET = \033[0m
COLOR_GREEN = \033[32m

NAME:= philo

BUILD_DIR:= build
SRCS_DIR:= srcs

SRCS_PHILO:= main \
				init/container_init \
				init/philo_init \
				list/list_add_back \
				list/list_destroy \
				list/list_new \
				utils/str_to_num

SRCS:=	${addprefix ${SRCS_DIR}/, ${addsuffix .c, ${SRCS_PHILO}}}

OBJS:=	${SRCS:%.c=${BUILD_DIR}/%.o}

DEPS:=	${OBJS:.o=.d}

LIBFT:=	libs/libft/libft.a

CFLAGS:= -Wall -Wextra -Werror -Wuninitialized -Winit-self -Wshadow -Wdouble-promotion -Wundef -fno-common -Wconversion -Os -g3 -O3 -fsanitize=address -g3 -O3 -fno-omit-frame-pointer

INC_DIRS:= includes libs/libft

CPPFLAGS:= ${addprefix -I,${INC_DIRS}} -MMD -MP

LIB_DIR:= libs/libft
LDFLAGS:= ${addprefix -L,${LIB_DIR}}
LDLIBS:= -lft

RM:=	rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${LDFLAGS} -fsanitize=address -g3 -O3 -fno-omit-frame-pointer ${OBJS} ${LDLIBS} -o $@
	@printf "$(COLOR_GREEN)Compilation completed.$(COLOR_RESET)\n"


${LIBFT}:
	${MAKE} -C ${dir ${LIBFT}}

${BUILD_DIR}/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	${MAKE} clean -C ${dir ${LIBFT}}
	${RM} ${BUILD_DIR}
	@printf "$(COLOR_GREEN)Objects cleaned.$(COLOR_RESET)\n"

fclean: clean
	${RM} ${LIBFT}
	${RM} ${NAME}
	@printf "$(COLOR_GREEN)executables cleaned.$(COLOR_RESET)\n"

re: fclean all

.PHONY:	all clean fclean re

-include ${DEPS}