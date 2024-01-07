#include <CLI/CLI.hpp>

#include "common/StringUtils.h"
#include "function/Gamos_Log.h"

int main(int argc, char **argv) {
  CLI::App app{"---"};
  std::string logFile = "";
  app.add_option("-f,--file", logFile, "Path to input log file");

  std::string outFile = "";
  app.add_option("-o,--out", outFile, "Path to output file");

  //   float targetValue = 1;
  //   app.add_option("-v,--value", targetValue, "Value should change to 1");

  CLI11_PARSE(app, argc, argv);
  if (logFile.empty()) {
    return 0;
  }
  //   string outputFilePath = filename + "." + to_string(int(targetValue)) + ".out";
  std::ofstream outputFile(outFile, std::ios::out);
  if (!outputFile.is_open()) {
    std::cerr << "Can not write out to file:" << outFile << std::endl;
    return 1;
  }
  readG4TrackTables(logFile, [](G4TrackRow *row) {
    // Print row
    row->printDebugInfo();
  });
  //   G4DCM *g4dcm = new G4DCM();
  //   g4dcm->readInfoWithMaterial(logFile);
  //   vector<int> numberInLine;
  //   numberInLine.clear();
  //   g4dcm->forEachMatrix(2, [g4dcm, targetValue, &numberInLine, &outputFile](float value, int xi, int yi, int zi) {
  //     int convert = value == targetValue ? 1 : 0;
  //     numberInLine.push_back(convert);
  //     if (xi == g4dcm->nx - 1) {
  //       string outline = joinVector(numberInLine, " ");
  //       outputFile << outline << std::endl;
  //       numberInLine.clear();
  //     }
  //   });
  outputFile.close();
  return 1;
}