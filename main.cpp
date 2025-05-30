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