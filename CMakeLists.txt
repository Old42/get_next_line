cmake_minimum_required(VERSION 3.9)
project(gnl_v2 C)

set(CMAKE_C_STANDARD 90)

add_executable(gnl_v2 main.c get_next_line.c get_next_line.h strings_functions.c libft/header.h libft/ft_strlen.c libft/ft_strcpy.c libft/ft_strjoin.c libft/ft_strnjoin.c libft/ft_strunjoin.c libft/ft_strcpyfromn.c)