# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergio <sergio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 21:22:01 by sergio            #+#    #+#              #
#    Updated: 2024/02/09 14:27:07 by sergio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#******************************************************************************#
#********************************* C MAKEFILE *********************************#
#******************************************************************************#
#------------------------------------------------------------------------------#

# Nombre del ejecutable a crear (sin espacios)
NAME = pipex
# Compilador a utilizar (gcc, clang, etc)
CC = gcc
# Flags de compilacion (agregar los que se necesiten)
CFLAGS = -g3 -Wall -Wextra -Werror
# Directorio de los archivos objeto (no tocar)
OBJDIR = objects
# Archivos fuente (agregar los que se necesiten)
SRCS =	main.c

#------------------------------------------------------------------------------#

# Archivos objeto (no tocar)
OBJS = $(SRCS:.c=.o)
# Directorio de las libft. Si no se usa, comentar la linea
LIBFT_DIR = ./libft
# Librerias a utilizar. Si no se usa, comentar la linea
LIBFT = $(LIBFT_DIR)/libft.a

#------------------------------------------------------------------------------#

# Colores para el make
RESET = \033[0m
GREEN = \033[92m
CYAN = \033[96m
RED = \033[91m
BOLD_GREEN = \033[1;32m
BOLD_RED = \033[1;31m

#------------------------------------------------------------------------------#

# Reglas del make (no tocar)

# $@ -> nombre del objetivo (en este caso, el nombre del ejecutable)
all: libft $(NAME)
	@echo "$(BOLD_GREEN)(⌐■_■) ¡¡¡$(NAME) compilado con exito!!! (⌐■_■)$(RESET)"

# La regla $(NAME) compila el ejecutable con los archivos objeto creados 
$(NAME): $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)Objetos creados!$(RESET)"
	@echo "$(CYAN)Compilando $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

# La regla %.o compila los archivos objeto
$(OBJDIR)/%.o : %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# La regla $(OBJDIR) crea el directorio de los archivos objeto
$(OBJDIR):
	@echo "$(CYAN)Creando directorio de objetos de $(NAME)...$(RESET)"
	mkdir $(OBJDIR)
	@echo "$(GREEN)Directorio de objetos de $(NAME) creado!$(RESET)"
	@echo "$(CYAN)Creando objetos de $(NAME)...$(RESET)"

# La regla libft compila la libft
libft:
	@make -C $(LIBFT_DIR)

# La regla libft_clean elimina los archivos objeto de la libft y el ejecutable
libft_fclean:
	@make -C $(LIBFT_DIR) fclean

# La regla clean elimina todos los archivos objeto y el directorio
clean: libft_fclean
	@echo "$(RED)Eliminando archivos objeto de $(NAME)...$(RESET)"
	rm -rf $(addprefix $(OBJDIR)/, $(OBJS))
	@echo "$(GREEN)Todos los archivos objeto de $(NAME) han sido eliminados!$(RESET)"
	@echo "$(RED)Eliminando directorio de objetos de $(NAME)...$(RESET)"
	rm -rf $(OBJDIR)
	@echo "$(GREEN)Directorio de objetos de $(NAME) eliminado!$(RESET)"

# La regla fclean elimina todos los archivos objeto y el ejecutable
fclean: clean libft_fclean
	@echo "$(RED)Eliminando $(NAME)...$(RESET)"
	rm -rf $(NAME)
	@echo "$(GREEN)$(NAME) ha sido eliminado!$(RESET)"

# La regla re elimina todo y compila nuevamente
re: fclean all

# La regla git agrega, hace commit y hace push
git: fclean
	rm -rf infile outfile
	git add .
	git status
	@read -p "Quieres continuar? [y/n]: " answer; \
	if [ "$$answer" = "y" ]; then \
		read -p "Mensaje para el commit: " message; \
		git commit -m "$$message"; \
		git push; \
		@echo "$(BOLD_GREEN)(⌐■_■) ¡¡¡Git push realizado!!! (⌐■_■)$(RESET)"; \
	else \
		echo "$(BOLD_RED)(҂◡_◡) ¡¡¡Git push no realizado!!! (҂◡_◡)!!!$(RESET)"; \
	fi

run: re
	./$(NAME) file1.txt "ls -l" "wc -l" file2.txt

# La regla .PHONY indica que no hay un archivo llamado all, clean, fclean o re
.PHONY: all clean fclean re git libft
#------------------------------------------------------------------------------#