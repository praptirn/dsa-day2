#include <bits/stdc++.h>
using namespace std;

class IExportStrategy {
public:
    virtual void exportData(string data) = 0;
};

class PDFExporter : public IExportStrategy {
public:
    void exportData(string data) {
        cout << "Exporting PDF: " << data << endl;
    }
};

class CSVExporter : public IExportStrategy {
public:
    void exportData(string data) {
        cout << "Exporting CSV: " << data << endl;
    }
};

class JSONExporter : public IExportStrategy {
public:
    void exportData(string data) {
        cout << "Exporting JSON: " << data << endl;
    }
};

int main() {
    string type, data;
    cin >> type >> data;

    IExportStrategy* exporter;

    if (type == "PDF") exporter = new PDFExporter();
    else if (type == "CSV") exporter = new CSVExporter();
    else exporter = new JSONExporter();

    exporter->exportData(data);

    return 0;
}
