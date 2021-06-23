#include "canvas.h"

#include "graphicsolution.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    //mainPen = QPen(Qt::black);

    GraphicSolution solution;
    solution.registration(1, &FactoryCreator::createQtFactory);

    shared_ptr<AbstractFactory> cr(solution.create(1));
    drawer = cr->createDrawer();
    //canvas = cr->createCanvas();
    qtPixmap = shared_ptr<QPixmap>(new QPixmap(2000, 2000));
    qtPixmap->fill(QColor(0, 0, 0, 0));
    canvas = unique_ptr<BaseCanvas>(new QtCanvas(qtPixmap));
    //qtCanvas = dynamic_pointer_cast<QtCanvas>(canvas);

    //qtCanvas = shared_ptr<QtCanvas>(new QtCanvas());
    //drawer->setCanvas(canvas);

    setStyleSheet("background-color:white;");

    clean();
}

Canvas::~Canvas()
{
    //delete painter;
    //delete canvasPixmap;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter pixmap_painter(this);

    //shared_ptr<QtCanvas> qtCanvas = dynamic_pointer_cast<QtCanvas>(canvas);
    pixmap_painter.drawPixmap(0, 0, *qtPixmap);
    //pixmap_painter.drawPixmap(0, 0, *canvasPixmap);
}

void Canvas::clean()
{
    //shared_ptr<QtCanvas> qtCanvas = dynamic_pointer_cast<QtCanvas>(canvas);
    qtPixmap->fill(QColor(0, 0, 0, 0));

    update();
}
