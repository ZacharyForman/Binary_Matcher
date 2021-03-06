#ifndef BINARY_MATCHER_ELF_BINARY_SYMBOL_H
#define BINARY_MATCHER_ELF_BINARY_SYMBOL_H

#include "elf/elf_binary.h"

#include <stdint.h>
#include <string>

struct ElfBinary::Symbol {
  const uint32_t kName;
  const char *const kStringName;
  const uint64_t kValue;
  const uint64_t kSize;
  const uint8_t kInfo;
  const uint8_t kOther;
  const uint16_t kSectionHeaderIndex;

  // Constructs a string representation of the symbol
  // that contains all of the information in the above fields.
  std::string ToString() const;
};

#endif // BINARY_MATCHER_ELF_BINARY_SYMBOL_H
