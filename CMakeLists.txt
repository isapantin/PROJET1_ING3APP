cmake_minimum_required(VERSION 3.10)

project(PROJET1_ING3APP C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET1_ING3APP
        main.c
        jeu.c
        jeu.h
        Variable.h
        joueur.h
        joueur.c
        ecranAcceuil.c
        ecranReglage.c

        # AJOUT
        ecranAcceuil.h
)

if(WIN32)
    target_link_libraries(PROJET1_ING3APP
            -lmingw32
            -lallegro-5.0.10-monolith-md-debug
    )
endif()