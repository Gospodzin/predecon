#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "settings.h"
#include "clustering.h"
#include "computationthread.h"
#include "datastatsthread.h"
#include "pcathread.h"
#include "samplethread.h"
#include "normalizethread.h"
#include "loaddatathread.h"
#include "guilogger.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_computeButton_clicked();
    void on_browseButton_clicked();
    void on_loadButton_clicked();
    void on_refreshButton_clicked();
    void on_algorithmSelect_currentTextChanged(const QString &arg1);

    void update();
    void dataLoaded();
    void statsComputed();
    void pcaComputed();
    void sampleComputed();
    void normalizationComputed();
    void log(QString msg, int depth);
    void plotClick(QMouseEvent* mouseEvent);

    void on_terminateButton_clicked();

    void on_clearLogButton_clicked();

    void on_selectRefPointButton_clicked();

    void on_dataInfoTable_sectionDoubleClicked(int logicalIndex);

    void on_dataStructureSelect_currentTextChanged(const QString &arg1);

    void on_browseOutputButton_clicked();

    void on_outputFileCheckBox_toggled(bool checked);

    void on_pcaButton_clicked();

    void on_undoPcaButton_clicked();


    void on_maxPcaButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_maxDepthSpinBox_valueChanged(const QString &arg1);

    void on_maxSampleButton_clicked();

    void on_sampleButton_clicked();

    void on_normalize_clicked();

    void on_dimnormalize_clicked();

    void on_removenoise_clicked();

private:
    ComputationThread compThread;
    LoadDataThread loadThread;
    DataStatsThread statsThread;
    PcaThread pcaThread;
    SampleThread sampleThread;
    NormalizeThread normalizeThread;

    GuiLogger logger;
    bool loggingEnabled = true;
    int maxLoggingDepth = 5;
    std::map<std::string, Subspace> stringToSubspace;

    bool selectRefPoint = false;
    bool refPointSelected = false;
    Point refPoint;

    Point* selectedPoint = NULL;
    QCPScatterStyle oldScatterStyle;

    DrawSettings lastDrawSets;

    Ui::MainWindow *ui;

    Settings collectSettings();
    DrawSettings collectDrawSettings();

    void draw(std::vector<Point>& data, DrawSettings sets);
    void fillStatsTable(std::vector<int> dims);
    void updateDataBySubspace(Subspace subspace);
    void updateSubspaceSelect();
    void updateDimensionSelects();
    void updateSelectedPointView();
    void updateSelectedClusterView();
    void selectPoint(QMouseEvent* mouseEvent);
    void updateStats();
    void keyPressEvent(QKeyEvent* e);
};

#endif // MAINWINDOW_H
