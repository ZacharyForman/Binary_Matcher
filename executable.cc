#include "executable.h"
#include "file.h"

#include <elf.h>
#include <stdint.h>

const char *const Executable::filename() const
{
  return binary_.filename();
}

Executable::Type Executable::GetType() const
{
  return Type::kUnknown;
}

Executable::Executable(const File &file) : binary_(file) { }

Executable::Type Executable::GetExecutableType(const File &file)
{
  const uint8_t *const buf = (file.buffer());
  if (file.size() >= 0x04
      && buf[EI_MAG0] == ELFMAG0
      && buf[EI_MAG1] == ELFMAG1
      && buf[EI_MAG2] == ELFMAG2
      && buf[EI_MAG3] == ELFMAG3) {
    return Executable::Type::kElf;
  }
  if (file.size() >= 0x42
      && buf[0x00] == 'M'
      && buf[0x01] == 'Z'
      && buf[0x40] == 'P'
      && buf[0x41] == 'E') {
    return Executable::Type::kPexe;
  }
  if (file.size() >= 0x04
      && buf[0] == 0XFE
      && buf[1] == 0xED
      && buf[2] == 0xFA
      && buf[3] == 0xCE) {
    return Executable::Type::kMach;
  }
  return Executable::Type::kUnknown;
}
