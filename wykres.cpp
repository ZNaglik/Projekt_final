#include "wykres.h"
#include "ui_wykres.h"

wykres::wykres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wykres)
{
    ui->setupUi(this);

    series = new QHorizontalPercentBarSeries();
    mainLayout = new QGridLayout;
    chart = new QChart();
    axis = new QBarCategoryAxis();
    chartView = new QChartView(chart);

    QBarSet *set0 = new QBarSet(dataVector[presentRows]);
    QBarSet *set1 = new QBarSet(dataVector[2*presentRows]);
    QBarSet *set2 = new QBarSet(dataVector[3*presentRows]);

    for(int j = 0; j < presentRows; j++)
    {
        *set0 << dataVector[j+1+presentRows].toDouble();
        *set1 << dataVector[j+1+(2*presentRows)].toDouble();
        *set2 << dataVector[j+1+(3*presentRows)].toDouble();
    }

    for(int j = 0; j < presentRows; j++)
    {
        categories << dataVector[j+1];
    }

    if(col2Avl) series->append(set0);
    if(col3Avl) series->append(set1);
    if(col4Avl) series->append(set2);


    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisY(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chartView->setRenderHint(QPainter::Antialiasing);

    eksportPDF = new QPushButton("Eksportuj wykres do PDF", this);

    mainLayout->addWidget(chartView, 0, 0);
    mainLayout->addWidget(eksportPDF, 1, 0);
    setLayout(mainLayout);
    connect(eksportPDF, SIGNAL(clicked()), this, SLOT(exportPDF()));

    QString title = "Wykres slupkowy - " + dataVector[0];
    setWindowTitle(tr(title.toStdString().c_str()));
}

wykres::~wykres()
{
    delete ui;
}

void wykres::exportPDF()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export PDF", QString(), "*.pdf");

    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPdfWriter writer(fileName);
    writer.setPageSize(QPagedPaintDevice::A4);
    QPainter painter(&writer);

    chartView->render(&painter);


    painter.end();
}

