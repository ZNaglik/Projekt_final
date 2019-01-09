#ifndef WYKRESLINIOWY_H
#define WYKRESLINIOWY_H

#include <QDialog>
#include <QtCharts>
#include <QtWidgets>
#include <QLineSeries>
#include <algorithm>
#include "globals.h"


namespace Ui {
class wykresliniowy;
}

class wykresliniowy : public QDialog
{
    Q_OBJECT

public:
    explicit wykresliniowy(QWidget *parent = nullptr);
    ~wykresliniowy();

private slots:
    void exportPDF0();
    void exportPDF1();
    void exportPDF2();

private:
    int m;
    double min0, max0, min1, max1, min2, max2;
    double a1, a2, a3;

    QPushButton *eksportPDF0, *eksportPDF1, *eksportPDF2;

    QCategoryAxis *axisX_0;
    QValueAxis *axisY_0;
    QCategoryAxis *axisX_1;
    QValueAxis *axisY_1;
    QCategoryAxis *axisX_2;
    QValueAxis *axisY_2;

    QScatterSeries *series0, *series1, *series2;

    QChart *chart_0;
    QChart *chart_1;
    QChart *chart_2;

    QGridLayout *mainLayout;

    QChartView *chartView_0;
    QChartView *chartView_1;
    QChartView *chartView_2;

    QStringList categories;

    Ui::wykresliniowy *ui;
};

#endif // WYKRESLINIOWY_H
