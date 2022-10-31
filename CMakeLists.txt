cmake_minimum_required(VERSION 3.23)
project(Belajar_CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Belajar_CPP
        ALGORITHM/1.cpp
        "PEMDAS/TUGAS 4/1.cpp"
        "PEMDAS/TUGAS 4/2.cpp"
        "PEMDAS/TUGAS 4/3.cpp"
        "PEMDAS/TUGAS 4/4.cpp"
        "PEMDAS/TUGAS 4/5.cpp"
        "PEMDAS/TUGAS 4/6.cpp"
        "PEMDAS/TUGAS 4/7.cpp"
        "PEMDAS/TUGAS 4/8.cpp"
        "PEMDAS/TUGAS 4/9.cpp"
        "PEMDAS/TUGAS 4/LKM4.cpp"
        "PEMDAS/TUGAS 4/LKM5.cpp"
        "PEMDAS/TUGAS 4/loginpage.cpp"
        "PEMDAS/TUGAS 4/loginpagesimple.cpp"
        "PEMDAS/TUGAS 5/1.cpp"
        "PEMDAS/TUGAS 5/2.cpp"
        "PEMDAS/TUGAS 5/3.cpp"
        "PEMDAS/TUGAS 5/4.cpp"
        "PEMDAS/TUGAS 5/5.cpp"
        "PEMDAS/TUGAS 5/pd6.cpp"
        "PEMDAS/TUGAS 5/pd7.cpp"
        PEMDAS/bSearch.cpp
        PEMDAS/komputasiitb.cpp
        PEMDAS/Laba.cpp
        PEMDAS/LKM2.cpp
        PEMDAS/soal_1.cpp
        PEMDAS/soal_2.cpp
        PEMDAS/soal_3.cpp
        PEMDAS/soalkonversi.cpp
        PEMDAS/tempCodeRunnerFile.cpp
        PEMDAS/test.cpp
        Toki/dengklekderetindah.cpp
        Toki/ganeshkereta.cpp
        Toki/HapusSatu.cpp
        Toki/kupon.cpp
        Toki/masterblangkonngoding.cpp
        Toki/pakdengklekmauujian.cpp
        Toki/pakdengklekoperasi.cpp
        Toki/pasarrakyat.cpp
        Toki/Pecahan.cpp
        Toki/prime.cpp
        Toki/tempCodeRunnerFile.cpp
        Toki/while.cpp
        cinemasitting.cpp
        waterlooproblem_domino.cpp)

add_executable(linearsearch Toki/linearsearch.cpp)
add_executable(djowenbisniskue Toki/djowenbisniskue.cpp)
add_executable(EXECUTIONFILE_EXE Toki/djadjawadaw.cpp)
set_target_properties(EXECUTIONFILE_EXE PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
