//===- IPDBInjectedSource.h - base class for PDB injected file --*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_DEBUGINFO_PDB_IPDBINJECTEDSOURCE_H
#define LLVM_DEBUGINFO_PDB_IPDBINJECTEDSOURCE_H

#include "PDBTypes.h"
#include "llvm/Support/raw_ostream.h"
#include <memory>
#include <string>

namespace llvm {
class raw_ostream;

namespace pdb {

/// IPDBInjectedSource defines an interface used to represent source files
/// which were injected directly into the PDB file during the compilation
/// process.  This is used, for example, to add natvis files to a PDB, but
/// in theory could be used to add arbitrary source code.
class IPDBInjectedSource {
public:
  virtual ~IPDBInjectedSource();

  virtual uint32_t getCrc32() const = 0;
  virtual uint64_t getCodeByteSize() const = 0;
  virtual std::string getFileName() const = 0;
  virtual std::string getObjectFileName() const = 0;
  virtual std::string getVirtualFileName() const = 0;
  virtual PDB_SourceCompression getCompression() const = 0;
  virtual std::string getCode() const = 0;
};
} // namespace pdb
} // namespace llvm

#endif // LLVM_DEBUGINFO_PDB_IPDBINJECTEDSOURCE_H
