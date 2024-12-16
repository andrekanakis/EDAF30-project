# Project - Djiktras Algorithm 📈

Projekt i kursen EDAF30, Programmering i C++

André Kanakis och Lucas Månsson

## Installationsguide

Mappstrukturen är följande:

Alla source-filer och header-filer ligger löst i huvudmappen. Input-filen graph.txt ligger också i huvudmappen.

Test-filer finns i `/test`-mappen.

Bygg programmet med CMAKE och make!

Instruktioner:

1. Skapa en mapp som heter `build` och flytta in i den mappen, kan göras med kommandot `mkdir build && cd build`
2. Kör CMAKE, kan använda flaggor för debug. `cmake -DCMAKE_BUILD_TYPE=Debug ..`
3. När CMAKE är klart så kör du make `make`. 
4. Du kan nu köra de olika programmen och testprogrammer i build-mappen. `./main` för att köra huvudprogrammet.
