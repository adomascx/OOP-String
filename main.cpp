// Iš teksto sukuria tris failus:
//   1) word_count.txt       – žodžiai, pasikartojantys daugiau nei vieną kartą, su jų kiekiu
//   2) cross_reference.txt  – tų žodžių eilučių numeriai
//   3) urls.txt             – visos rastos URL nuorodos

// Naudojimas:  ./text_sort.exe  input.txt
// Jei argumentas nepateiktas, programa ieško „input.txt“ tame pačiame aplanke.

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <string>

using std::cerr;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::regex;
using std::set;
using std::sregex_iterator;
using std::string;

// Paverčia ASCII raides į mažąsias, o UTF-8 baitus palieka nepaliestus
string to_lower_ascii(string s)
{
    for (char &ch : s)
        if (ch < 128)
            ch = static_cast<unsigned char>(tolower(ch));
    return s;
}

// Raidės (anglų ir lietuvių)
const regex WORD_RX(
    R"(([[:alpha:]ĄČĘĖĮŠŲŪŽąčęėįšųūž]+))",
    regex::icase | regex::optimize);

// http://pavyzdys, https://pavyzdys, www.pavyzdys, pavyzdys.lt/…
const regex URL_RX(
    R"(((?:https?://)?(?:www\.)?[A-Za-z0-9\-_]+\.[A-Za-z]{2,}(?:\.[A-Za-z0-9\-_]+)*(?:[A-Za-z0-9\-/._~%?#=&+]*)?))",
    regex::icase | regex::optimize);

int main(int argc, char *argv[])
{
    const string in_name = (argc > 1) ? argv[1] : "input.txt";
    const string out_cnt = "txt/word_count.txt";
    const string out_xref = "txt/cross_reference.txt";
    const string out_url = "txt/urls.txt";

    ifstream in_file(in_name);
    if (!in_file)
    {
        cerr << "Cannot open " << in_name << '\n';
        return 1;
    }

    ofstream cnt_file(out_cnt);
    ofstream xref_file(out_xref);
    ofstream url_file(out_url);
    if (!cnt_file || !xref_file || !url_file)
    {
        cerr << "Cannot create output files\n";
        return 1;
    }

    // map'ai raktus laiko surikiuotus -> gražesnė išvestis
    std::map<string, size_t> word_count;
    std::map<string, set<int>> word_lines;
    set<string> urls;

    string line;
    int line_no = 0;

    while (getline(in_file, line))
    {
        ++line_no;

        // ieškome žodžių
        for (sregex_iterator it(line.begin(), line.end(), WORD_RX), end; it != end; ++it)
        {
            const string w = to_lower_ascii(it->str());
            ++word_count[w];
            word_lines[w].insert(line_no);
        }

        // ieškome URL
        for (sregex_iterator it(line.begin(), line.end(), URL_RX), end; it != end; ++it)
            urls.insert(it->str());
    }
}