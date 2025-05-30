# OOP-String

Ši programa analizuoja pasirinktą tekstą (input.txt faile): suskaičiuoja žodžių, kurie kartojasi daugiau nei vieną kartą, dažnį; sukuria kryžminės nuorodos lentelę su eilučių numeriais, kur tie žodžiai pasirodo; ištraukia visus URL adresus (pilna ar sutrumpinta forma). Visi rezultatai išsaugomi atskiruose failuose. Realizacijoje naudojami C++ asociatyvūs konteineriai (`std::map`, `std::unordered_map`) siekiant efektyvaus duomenų kaupimo.

## Instaliacija

### Surinkimas iš source failų per Makefile

1. Įsitikinkite, kad sistemoje įdiegti C++ kompiliatorius (GCC arba Clang, C++17 palaikymas) ir **GNU Make**.
2. Nuklonuokite repozitoriją:

   ```bash
   git clone github.com/adomascx/OOP-String
   cd OOP-String
   ```

3. Sukompiliuokite projektą:

   ```bash
   make
   ```

4. Paleiskite programą su norimu tekstiniu failu:

   ```bash
    ./build/text_sort.exe tekstas.txt
    ```
