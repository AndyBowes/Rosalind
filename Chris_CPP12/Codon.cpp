#include "Common.h"
#include "Codon.h"

Codon::Codon()
{
    std::string codons = R"(UUU F      CUU L      AUU I      GUU V
        UUC F      CUC L      AUC I      GUC V
        UUA L      CUA L      AUA I      GUA V
        UUG L      CUG L      AUG M      GUG V
        UCU S      CCU P      ACU T      GCU A
        UCC S      CCC P      ACC T      GCC A
        UCA S      CCA P      ACA T      GCA A
        UCG S      CCG P      ACG T      GCG A
        UAU Y      CAU H      AAU N      GAU D
        UAC Y      CAC H      AAC N      GAC D
        UAA Stop   CAA Q      AAA K      GAA E
        UAG Stop   CAG Q      AAG K      GAG E
        UGU C      CGU R      AGU S      GGU G
        UGC C      CGC R      AGC S      GGC G
        UGA Stop   CGA R      AGA R      GGA G
        UGG W      CGG R      AGG R      GGG G)";

    auto codonEntries = Split(codons,' ');

    auto itrEntries = codonEntries.begin();
    while (itrEntries != codonEntries.end())
    {
        if ((*itrEntries).empty())
        {
            itrEntries = codonEntries.erase(itrEntries);
            continue;
        }
        itrEntries++;
    }

    auto itrFirst = codonEntries.begin();
    while (itrFirst != codonEntries.end())
    {
        auto itrSecond = itrFirst + 1;
        if (itrSecond != codonEntries.end())
        {
            if (*itrSecond != "Stop")
            {
                _entries[*itrFirst] = *itrSecond;
            }
        }

        itrFirst = ++itrSecond;
    };
}

std::string Codon::Map(const std::string& str) const
{
    auto itr = _entries.find(str);
    if (itr == _entries.end())
    {
        return "";
    }
    return itr->second;
}