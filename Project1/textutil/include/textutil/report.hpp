#pragma once

#include <string>

struct FileStats;

void write_report(
    const std::string& output_path,
    const std::string& input_path
);