// Copyright (c) 2015-2016 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_TYPE_HH
#define TAOCPP_JSON_INCLUDE_TYPE_HH

#include <cstdint>

#include "external/operators.hpp"

namespace tao
{
   namespace json
   {
      enum class type : std::uint8_t
      {
         NULL_,
         BOOL,
         SIGNED,
         UNSIGNED,
         DOUBLE,
         STRING,
         ARRAY,
         OBJECT,
         POINTER
      };

      inline bool needs_destroy( const type t )
      {
         switch ( t ) {
            case type::STRING:
            case type::ARRAY:
            case type::OBJECT:
               return true;
            default:
               return false;
         }
      }

      inline const char * to_string( const type t )
      {
         switch ( t ) {
            case type::NULL_:
               return "null";
            case type::BOOL:
               return "bool";
            case type::SIGNED:
               return "signed";
            case type::UNSIGNED:
               return "unsigned";
            case type::DOUBLE:
               return "double";
            case type::STRING:
               return "string";
            case type::ARRAY:
               return "array";
            case type::OBJECT:
               return "object";
            case type::POINTER:
               return "pointer";
         }
         return "unknown";
      }

      struct null_t : operators::totally_ordered< null_t > {} constexpr null {};
      struct empty_array_t : operators::totally_ordered< empty_array_t > {} constexpr empty_array {};
      struct empty_object_t : operators::totally_ordered< empty_object_t > {} constexpr empty_object {};

      constexpr bool operator== ( const null_t &, const null_t & ) noexcept { return true; }
      constexpr bool operator< ( const null_t &, const null_t & ) noexcept { return false; }

      constexpr bool operator== ( const empty_array_t &, const empty_array_t & ) noexcept { return true; }
      constexpr bool operator< ( const empty_array_t &, const empty_array_t & ) noexcept { return false; }

      constexpr bool operator== ( const empty_object_t &, const empty_object_t & ) noexcept { return true; }
      constexpr bool operator< ( const empty_object_t &, const empty_object_t & ) noexcept { return false; }

   } // json

} // tao

#endif
