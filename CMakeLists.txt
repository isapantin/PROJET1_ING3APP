cmake_minimum_required(VERSION 3.20)
project(PROJET1_ING3APP C)

set(CMAKE_C_STANDARD 99)

set(ALLEGRO_DIR ${CMAKE_SOURCE_DIR}/allegro)
include_directories(${ALLEGRO_DIR}/include)
link_directories(${ALLEGRO_DIR}/lib)

add_executable(PROJET1_ING3APP main.c)

target_link_libraries(PROJET1_ING3APP
        allegro
        allegro_main
        allegro_font
        allegro_ttf
        allegro_primitives
        allegro_image
        allegro_audio
        allegro_acodec
)

add_custom_command(TARGET PROJET1_ING3APP POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${ALLEGRO_DIR}/bin $<TARGET_FILE_DIR:PROJET1_ING3APP>)