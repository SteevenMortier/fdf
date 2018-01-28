cmake_minimum_required(VERSION 3.9)
project(fdf)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(minilibx)
include_directories(minilibx/test)

add_executable(fdf
        minilibx/test/main.c
        minilibx/test/new_win.c
        minilibx/mlx.h
        minilibx/mlx_clear_window.c
        minilibx/mlx_destroy_image.c
        minilibx/mlx_destroy_window.c
        minilibx/mlx_expose_hook.c
        minilibx/mlx_flush_event.c
        minilibx/mlx_get_color_value.c
        minilibx/mlx_get_data_addr.c
        minilibx/mlx_hook.c
        minilibx/mlx_init.c
        minilibx/mlx_int.h
        minilibx/mlx_int_anti_resize_win.c
        minilibx/mlx_int_do_nothing.c
        minilibx/mlx_int_get_visual.c
        minilibx/mlx_int_param_event.c
        minilibx/mlx_int_set_win_event_mask.c
        minilibx/mlx_int_str_to_wordtab.c
        minilibx/mlx_int_wait_first_expose.c
        minilibx/mlx_key_hook.c
        minilibx/mlx_lib_xpm.c
        minilibx/mlx_loop.c
        minilibx/mlx_loop_hook.c
        minilibx/mlx_mouse_hook.c
        minilibx/mlx_new_image.c
        minilibx/mlx_new_window.c
        minilibx/mlx_pixel_put.c
        minilibx/mlx_put_image_to_window.c
        minilibx/mlx_rgb.c
        minilibx/mlx_string_put.c
        minilibx/mlx_xpm.c)
