cmake_minimum_required(VERSION 3.15)
project(DNASequence)

set(CMAKE_CXX_STANDARD 98)

add_executable(DNA_design Src/main.cpp Src/DNA/DnaSequence.cpp Src/DNA/DnaSequence.h Src/Test/TestDnaSequence.cpp Src/Test/TestDnaSequence.h Src/Reader/IReader.h Src/Reader/FileReader.cpp Src/Reader/FileReader.h Src/Writer/IWriter.h Src/Writer/FileWriter.cpp Src/Writer/FileWriter.h Src/Exeptions/OpenFileError.h
        Src/DNA/Status.cpp Src/DNA/Status.h)
