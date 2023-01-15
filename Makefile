CLIENT			=	client
SERVER			=	server
S_SRCS			=	server.c
C_SRCS			=	client.c
CURRENT_DIR		=	$(PWD)
LIBFT			=	$(CURRENT_DIR)/libft/libft.a
S_OBJS			=	${S_SRCS:.c=.o}
C_OBJS			=	${C_SRCS:.c=.o}

CC	 	=	cc
CFLAGS	=	-Wall -Wextra -Werror
all: ${LIBFT} ${CLIENT} ${SERVER} 
${LIBFT}:
	cd ${CURRENT_DIR}/libft && make && cd ${CURRENT_DIR}
$(SERVER):$(S_OBJS)
	${CC} ${CFLAGS} -o ${SERVER} ${S_OBJS} ${LIBFT}
${CLIENT}:${C_OBJS}
	${CC} ${CFLAGS} -o ${CLIENT} ${C_OBJS} ${LIBFT}

onlyserver: $(LIBFT) $(SERVER)
$(SERVER):${S_OBJS}

onlyclient: $(LIBFT) $(CLIENT)
${CLIENT}:${C_OBJS}

clean:
	rm -f ${S_OBJS} ${C_OBJS}
	cd ${CURRENT_DIR}/libft && make clean && cd ${CURRENT_DIR}

fclean:clean
	rm -f ${CLIENT} ${SERVER}
	cd ${CURRENT_DIR}/libft && make fclean && cd ${CURRENT_DIR}

re:fclean all

.PHONY:
	all clean fclean re bonus
