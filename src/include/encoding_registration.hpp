//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// encoding_registration.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include <cstddef>

// This header is included by the generated conversion tables, so it must not include any DuckDB header (see
// map_entry_encoding.hpp). map_entry_encoding has to be defined before including it: by map_entry_encoding.hpp in
// the generated tables, or by duckdb/function/encoding_function.hpp everywhere else.
namespace duckdb {

struct DBConfig;

namespace duckdb_encodings {

//! Registers a generated conversion table under its name and all of its aliases. This is the only part of an
//! encoding's registration that needs DuckDB's headers, so it's defined once in generated_encoded_functions.cpp
//! instead of in every generated table.
void RegisterGeneratedEncoding(const DBConfig &config, const char *name, size_t max_bytes_per_byte, size_t lookup_bytes,
                               const map_entry_encoding *map, size_t map_size, const char *const *aliases = nullptr,
                               size_t alias_count = 0);

} // namespace duckdb_encodings
} // namespace duckdb
