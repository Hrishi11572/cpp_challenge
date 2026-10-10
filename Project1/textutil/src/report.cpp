#include "textutil/report.hpp"
#include<fstream>
#include<iostream>
#include "textutil/file_io.hpp"
#include "textutil/stats.hpp"


void write_report(
    const std::string& output_path,
    const std::string& input_path
) {
    const std::string contents = read_file_contents(input_path);
    FileStats stats;

    stats.calculate_file_stats(contents);

    std::ofstream output(output_path);

    if (!output) {
        throw std::runtime_error("Could not create report: " + output_path);
    }

    output << "================================\n";
    output << "        TEXTUTIL REPORT\n";
    output << "================================\n\n";

    output << "Input file: " << input_path << '\n';
    output << "STATISTICS\n";
    output << "----------\n";
    output << "Lines: " << stats.get_line_counts() << '\n';
    output << "Words: " << stats.get_word_counts() << '\n';
    output << "Bytes: " << stats.get_byte_counts() << '\n';

    output << "\n================================\n";
    output << "        REPORT END\n";
    output << "================================\n";
}
