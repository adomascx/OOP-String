# OOP-String

Ši programa analizuoja pasirinktą (>1000 žodžių) tekstą: suskaičiuoja žodžių, kurie kartojasi daugiau nei vieną kartą, dažnį; sukuria kryžminės nuorodos lentelę su eilučių numeriais, kur tie žodžiai pasirodo; ištraukia visus URL adresus (pilna ar sutrumpinta forma). Visi rezultatai išsaugomi atskiruose failuose. Realizacijoje naudojami C++ asociatyvūs konteineriai (`std::map`, `std::unordered_map`) siekiant efektyvaus duomenų kaupimo.

## Instaliacija

Projekto įdiegimui pateikiami du scenarijai: surinkimas iš išeities kodo naudojant *Makefile* ir diegimas per paruoštą *Setup.exe* diegiklį.

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

4. Vykdomasis failas bus sukurtas kataloge `bin/` (pvz. `bin/oop-string`). Paleidimui:

   ```bash
   ./bin/oop-string
   ```

### Instaliacija naudojant Setup.exe

1. Atsisiųskite **Setup.exe** iš projekto skilties **Releases**.
2. Dukart spustelėkite *Setup.exe* ir sekite diegimo vedlio nurodymus.
3. Numatytoji diegimo vieta – `C:\Program Files\VU\Adomas-Lukosevicius\` (galima keisti).
4. Programą paleiskite per meniu **Start** arba per darbalaukio nuorodą.
