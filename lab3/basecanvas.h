#ifndef BASECANVAS_H
#define BASECANVAS_H

class BaseCanvas
{
public:
    BaseCanvas() = default;
    virtual ~BaseCanvas() = 0;

    //virtual void drawLine(double x1, double y1, double x2, double y2) = 0;
    virtual void clear() = 0;
};

class TestCanvas : public BaseCanvas
{
public:
    TestCanvas();
    ~TestCanvas() = default;

    //virtual void drawLine(double x1, double y1, double x2, double y2) override;
    virtual void clear() override;

};

#endif // BASECANVAS_H
