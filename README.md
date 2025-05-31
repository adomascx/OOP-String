# OOP-String

Ši programa analizuoja pasirinktą tekstą (įvedimo failas – `input.txt`) ir atlieka šiuos veiksmus:

- Suskaičiuoja žodžių dažnį, įskaitant tik tuos žodžius, kurie pasikartoja daugiau nei vieną kartą.
- Sukuria kryžminės nuorodos lentelę, kurioje pateikiama, kuriuose eilučių numeriuose žodis pasirodo.
- Atrenka visus tekstuose rastus URL (visi URL, tiek pilni, tiek sutrumpinti).

Visi rezultatai įrašomi į atskirus failus:

- Išvedimo failų keliai:
  - `txt/word_count.txt` – žodžiai, kurie pasikartoja daugiau nei vieną kartą, su jų kiekiu.
  - `txt/cross_reference.txt` – atitinkamų žodžių eilučių numeriai.
  - `txt/urls.txt` – atrinkti URL.

## Surinkimas ir paleidimas

### Reikalavimai

- C++ kompiliatorius (GCC arba Clang) su C++17 palaikymu.
- **GNU Make**

### Instrukcijos

1. Nuklonuokite repozitoriją:

   ```bash
   git clone github.com/adomascx/OOP-String
   cd OOP-String
   ```

2. Sukompiliuokite projektą:

   ```bash
   make
   ```

3. Paleiskite programą. Jei nebus nurodytas įvesties failas, numatytasis failas yra `input.txt` tame pačiame aplanke:

   ```bash
   ./build/text_sort.exe input.txt
   ```

   Arba:

   ```bash
   ./build/text_sort.exe
   ```

Programa sukurs ir įrašys rezultatus į:

- `txt/word_count.txt`
- `txt/cross_reference.txt`
- `txt/urls.txt`

Po vykdymo terminale bus išvesta statistika apie apdorotus žodžius ir URL.
