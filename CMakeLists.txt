cmake_minimum_required(VERSION 3.9)
project(gnl_v2 C)

set(CMAKE_C_STANDARD 90)

add_executable(gnl_v2 main.c get_next_line.c get_next_line.h strings_functions.c Libft/header.h Libft/ft_strlen.c Libft/ft_strcpy.c Libft/ft_strjoin.c Libft/ft_strnjoin.c Libft/ft_strunjoin.c Libft/ft_strcpyfromn.c)