// This example shows how to deal with ports when type is not std::string (default port type)
#pragma once

#include "behaviortree_cpp/json_export.h"

// Want to use this type for port
struct Position2D
{
  double x;
  double y;
};

// Template specialization to convert a string to Position2D
namespace BT
{
  template <> inline Position2D convertFromString(StringView str)
  {
    printf("Converting string: \"%s\"\n", str.data());
    
    // Real numbers are expected to be separated by semicolons
    auto parts = splitString(str, ';');
    if (parts.size() !=2) {
      throw RuntimeError("invalid input");
    }
    else {
      Position2D output;
      output.x = convertFromString<double>(parts[0]);
      output.y = convertFromString<double>(parts[1]);
      return output;
    }
  }
} // namespace BT
