// This file is part of the Luau programming language and is licensed under MIT License; see LICENSE.txt for details
#pragma once

#include "Luau/DenseHash.h"
#include "Luau/FileResolver.h"
#include "Luau/Location.h"

#include <string>
#include <vector>

namespace Luau
{

class AstStat;
class AstExpr;
class AstStatBlock;
struct AstLocal;
struct SourceModule;

struct RequireTraceResult
{
    DenseHashMap<const AstExpr*, ModuleInfo> exprs{nullptr};

    std::vector<std::pair<ModuleName, Location>> requireList;
};

RequireTraceResult traceRequires(FileResolver* fileResolver, SourceModule *sourceModule, AstStatBlock* root, const ModuleName& currentModuleName);
RequireTraceResult traceRequires(FileResolver* fileResolver, AstStatBlock* root, const ModuleName& currentModuleName);

} // namespace Luau