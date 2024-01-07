#include "Gamos_Log.h"

#include "../common/FileUtils.h"
#include "../common/StringUtils.h"

vector<G4TrackTable> readG4TrackTables(string file, function<void(G4TrackRow *)> func) {
  string tableHeader = "Step#    X(mm)    Y(mm)    Z(mm) KinE(MeV)  dE(MeV) StepLeng TrackLeng  NextVolume ProcName";
  vector<G4TrackTable> output;
  bool inTable = false;
  forEachLine(file, [tableHeader, &inTable, func, &output](long lineIndex, string line) {
    if (line == tableHeader) {
      inTable = true;
      G4TrackTable new_table;
      output.push_back(new_table);
      return;
    }
    if (!inTable) {
      return;
    }
    G4TrackTable *table = &(output.back());

    vector<string> columns = splitStringBySpace(line);
    if (columns.size() != 10) {
      inTable = false;
      return;
    }

    G4TrackRow *row = table->readRow(line);
    if (row != NULL) {
      func(row);
    }
  });
  return output;
}