#include "wykreskolowy.h"
#include "mainwindow.h"
#include "ui_wykreskolowy.h"

wykresKolowy::wykresKolowy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wykresKolowy)
{
    ui->setupUi(this);

     mainLayout = new QGridLayout;




     series0 = new QPieSeries();
     series1 = new QPieSeries();
     series2 = new QPieSeries();

     for(int j = 0; j < presentRows ; j++)
     {
        series0->append(dataVector[j+1], dataVector[j+1+(presentRows)].toDouble());
        series1->append(dataVector[j+1], dataVector[j+1+(2*presentRows)].toDouble());
        series2->append(dataVector[j+1], dataVector[j+1+(3*presentRows)].toDouble());
     }

     m = 1;

    if(col2Avl)
    {



        eksportPDF0 = new QPushButton("Eksportuj wykres " + dataVector[m*presentRows] + " do PDF", this);

        chart = new QChart();
        chart->addSeries(series0);
        chart->setTitle("Wykres " + dataVector[presentRows]);
        chart->legend()->show();

        chartView0 = new QChartView(chart);
        chartView0->setRenderHint(QPainter::Antialiasing);

        mainLayout->addWidget(chartView0, 0, m);
        mainLayout->addWidget(eksportPDF0, 1, m);

        connect(eksportPDF0, SIGNAL(clicked()), this, SLOT(exportPDF0()));
        //createNewChart(chart, series0, chartView0, m);
    }

    if(col3Avl)
    {
        ++m;

        eksportPDF1 = new QPushButton("Eksportuj wykres " + dataVector[m*presentRows] + " do PDF", this);

        chart = new QChart();
        chart->addSeries(series1);
        chart->setTitle("Wykres " + dataVector[2*presentRows]);
        chart->legend()->show();

        chartView1 = new QChartView(chart);
        chartView1->setRenderHint(QPainter::Antialiasing);

        mainLayout->addWidget(chartView1, 0, m);
        mainLayout->addWidget(eksportPDF1, 1, m);

        connect(eksportPDF1, SIGNAL(clicked()), this, SLOT(exportPDF1()));
       // createNewChart(chart, series1, chartView1, m);
    }

    if(col4Avl)
    {
        ++m;

        eksportPDF2 = new QPushButton("Eksportuj wykres " + dataVector[m*presentRows] + " do PDF", this);

        chart = new QChart();
        chart->addSeries(series2);
        chart->setTitle("Wykres " + dataVector[3*presentRows]);
        chart->legend()->show();

        chartView2 = new QChartView(chart);
        chartView2->setRenderHint(QPainter::Antialiasing);

        mainLayout->addWidget(chartView2, 0, m);
        mainLayout->addWidget(eksportPDF2, 1, m);

        connect(eksportPDF2, SIGNAL(clicked()), this, SLOT(exportPDF2()));
        //createNewChart(chart, series2, chartView2, m);
    }


     setLayout(mainLayout);

     QString title = "Wykres kolowy - " + dataVector[0];
     setWindowTitle(tr(title.toStdString().c_str()));
}

wykresKolowy::~wykresKolowy()
{
    delete ui;
}

void wykresKolowy::exportPDF0()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export PDF", QString(), "*.pdf");

    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPdfWriter writer(fileName);
    writer.setPageSize(QPagedPaintDevice::A4);
    QPainter painter(&writer);

    chartView0->render(&painter);


    painter.end();
}


void wykresKolowy::exportPDF1()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export PDF", QString(), "*.pdf");

    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPdfWriter writer(fileName);
    writer.setPageSize(QPagedPaintDevice::A4);
    QPainter painter(&writer);

    chartView1->render(&painter);


    painter.end();
}

void wykresKolowy::exportPDF2()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export PDF", QString(), "*.pdf");

    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPdfWriter writer(fileName);
    writer.setPageSize(QPagedPaintDevice::A4);
    QPainter painter(&writer);

    chartView2->render(&painter);


    painter.end();
}

/*
void wykresKolowy::createNewChart(QChart *chart, QPieSeries *series, QChartView *chartView, int counter)
{
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Wykres " + dataVector[m*presentRows]);
    chart->legend()->show();

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView0, 0, counter);
}
*/
