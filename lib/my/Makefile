##
## EPITECH PROJECT, 2020
## my_defender
## File description:
## Makefile
##

CC			=	gcc
CFLAGS		=	-W -Wall -Wextra
CPPFLAGS		=	-I../../include/

SRC			=	$(wildcard strings/*.c)
OBJ			=	$(SRC:.c=.o)

LIBNAME		=	my
TARGET		=	lib$(LIBNAME).a

all			:	$(TARGET)

$(TARGET)	:	$(OBJ)
			@$(AR) rsc $@ $^
			@cp $(TARGET) ../../$(TARGET)

clean		:
			$(RM) $(OBJ)
			$(RM) $(TARGET)

fclean		:	clean
			$(RM) ../../$(TARGET)

re			:	fclean all
