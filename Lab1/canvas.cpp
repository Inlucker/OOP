#include "canvas.h"
#include "entry_point.h"

Canvas::Canvas()
{
    setStyleSheet("background-color:white;");
    proection = create_proection();
}

Canvas::~Canvas()
{
    Action act;

    entry_point(proection, FREE, act);
}

void Canvas::paintEvent(QPaintEvent *event)
{
    painter.begin(this); //Захват контекста

    float x_center = width() / 2;
    float y_center = height() / 2;
    painter.translate(x_center, y_center);

    if (proection.edges.mas)
        for (int i = 0; i < proection.edges.edges_number; i++)
        {
            int p1_id = proection.edges.mas[i].p1;
            int p2_id = proection.edges.mas[i].p2;
            //std::cout << p1_id << " " << p2_id << endl;
            //std::cout << model.points.mas[p1_id].x << " " << model.points.mas[p1_id].y << " " << model.points.mas[p2_id].x << " " << model.points.mas[p2_id].y << endl;
            painter.drawLine(proection.points.mas[p1_id].x, -proection.points.mas[p1_id].y, proection.points.mas[p2_id].x, -proection.points.mas[p2_id].y);
        }

    painter.end(); //Освобождение контекста
}
