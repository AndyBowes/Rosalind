#include "Common.h"

using namespace std;

std::vector<char> Nucleotides{ 'A', 'C', 'G', 'T' };

MAKE_PROBLEM(DNA)
{
    std::string text = ReadInput();

    // Init
    std::map<char, int> mapCount;
    for (auto tide : Nucleotides)
    {
        mapCount[tide] = 0;
    }

    for (auto& ch : text)
    {
        mapCount[ch]++;
    }

    std::ostringstream strOut;
    for (auto tide : Nucleotides)
    {
        strOut << mapCount[tide] << " ";
    }

    WriteOutput(RTrim(strOut.str()));
}


