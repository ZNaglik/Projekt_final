#ifndef WYKRESKOLOWY_H
#define WYKRESKOLOWY_H

#include <QDialog>
#include <QtCharts>
#include <QtWidgets>
#include "globals.h"

namespace Ui {
class wykresKolowy;
}

class wykresKolowy : public QDialog
{
    Q_OBJECT

public:
    explicit wykresKolowy(QWidget *parent = nullptr);
    ~wykresKolowy();

private slots:
        void exportPDF0();
        void exportPDF1();
        void exportPDF2();

private:
    int m;


    //void createNewChart(QChart *, QPieSeries *, QChartView *, int);

    QPushButton *eksportPDF0, *eksportPDF1, *eksportPDF2;
    QGridLayout *mainLayout;
    QChartView *chartView0, *chartView1, *chartView2;
    QPieSeries *series0, *series1, *series2;
    QPieSlice *slice;
    QChart *chart;
    Ui::wykresKolowy *ui;
};

#endif // WYKRESKOLOWY_H
