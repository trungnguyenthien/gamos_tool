#include <CLI/CLI.hpp>

#include "common/Model.h"
#include "common/StringUtils.h"
#include "function/Gamos_Log.h"
#include "function/WRLHelper.h"

int main(int argc, char **argv) {
  CLI::App app{"---"};
  std::string logFile = "";
  app.add_option("-f,--file", logFile, "Path to input log file");

  std::string outFile = "";
  app.add_option("-o,--out", outFile, "Path to output file");

  CLI11_PARSE(app, argc, argv);
  if (logFile.empty()) {
    return 0;
  }

  std::ofstream outputFile(outFile, std::ios::out);
  if (!outputFile.is_open()) {
    std::cerr << "Can not write out to file:" << outFile << std::endl;
    return 1;
  }
  readG4TrackTables(logFile, [](G4TrackRow *row) {
    // Print row
    // row->printDebugInfo();
    WrlShapeCubic cubic(row->ProcName, Point(row->Xmm, row->Ymm, row->Zmm), row->name());
    cout << cubic.print() << endl;
  });

  outputFile.close();
  return 1;
}