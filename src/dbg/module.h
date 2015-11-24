#pragma once

#include "_global.h"

struct MODSECTIONINFO
{
    duint addr;      // Virtual address
    duint size;      // Virtual size
    char name[MAX_SECTION_SIZE * 5];  // Escaped section name
};

struct MODINFO
{
    duint base;  // Module base
    duint size;  // Module size
    duint hash;  // Full module name hash
    duint entry; // Entry point

    char name[MAX_MODULE_SIZE];         // Module name (without extension)
    char extension[MAX_MODULE_SIZE];    // File extension
    char path[MAX_PATH];                // File path (in UTF8)

    std::vector<MODSECTIONINFO> sections;
};

bool ModLoad(duint Base, duint Size, const char* FullPath);
bool ModUnload(duint Base);
void ModClear();
MODINFO* ModInfoFromAddr(duint Address);
bool ModNameFromAddr(duint Address, char* Name, bool Extension);
duint ModBaseFromAddr(duint Address);
duint ModHashFromAddr(duint Address);
duint ModHashFromName(const char* Module);
duint ModBaseFromName(const char* Module);
duint ModSizeFromAddr(duint Address);
bool ModSectionsFromAddr(duint Address, std::vector<MODSECTIONINFO>* Sections);
duint ModEntryFromAddr(duint Address);
int ModPathFromAddr(duint Address, char* Path, int Size);
int ModPathFromName(const char* Module, char* Path, int Size);
void ModGetList(std::vector<MODINFO> & list);