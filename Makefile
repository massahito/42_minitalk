CLIENT			=	client
SERVER			=	server
S_SRCS			=	server.c
C_SRCS			=	client.c
CURRENT_DIR		=	$(PWD)
LIBFT			=	./libft/libft.a
S_OBJS			=	${S_SRCS:.c=.o}
C_OBJS			=	${C_SRCS:.c=.o}

CC	 	=	cc
CFLAGS	=	-Wall -Wextra -Werror
all: ${CLIENT} ${SERVER} 
${LIBFT}:
	make -C ./libft
$(SERVER):$(S_OBJS) ${LIBFT}
	${CC} ${CFLAGS} -o ${SERVER} ${S_OBJS} ${LIBFT}
${CLIENT}:${C_OBJS} ${LIBFT}
	${CC} ${CFLAGS} -o ${CLIENT} ${C_OBJS} ${LIBFT}

clean:
	rm -f ${S_OBJS} ${C_OBJS}
	make clean -C ./libft

fclean:clean
	rm -f ${CLIENT} ${SERVER}
	make fclean -C ./libft

re:fclean all

.PHONY:
	all clean fclean re bonus
