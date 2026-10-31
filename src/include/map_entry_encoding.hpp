//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// map_entry_encoding.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include <cstddef>

// The generated conversion tables in src/generated/*_map.cpp take up almost all of the compile time of this
// extension, but they never change. They include this header instead of duckdb/function/encoding_function.hpp, so
// that they don't depend on any DuckDB header and compiler caches such as ccache can reuse them across DuckDB
// versions. This definition must stay identical to the one in duckdb/function/encoding_function.hpp, so that both
// define the same type. RegisterGeneratedEncoding in generated_encoded_functions.cpp checks that the layout still
// matches. Never include this header together with DuckDB headers, that results in a redefinition error.
namespace duckdb {

//! Encoding Map Entry Struct used for byte replacement
typedef struct {
	size_t key_len;
	const char *key;
	size_t value_len;
	const char *value;
} map_entry_encoding;

} // namespace duckdb
