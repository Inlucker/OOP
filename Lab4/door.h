#pragma once

#include <QObject>

#include <constants.h>


class Doors : public QObject
{
    Q_OBJECT

    enum doors_status
    {
        OPENNING,
        OPENED,
        CLOSING,
        CLOSED
    };

public:
    explicit Doors(QObject *parent = nullptr);

    //const doors_status &getDoorsStatus() const; // Можно ли так?

signals:
    void closedDoors();
    void openedDoors();

public slots:
    void startOpening();
    void startClosing();

private slots:
    void open();
    void close();

private:
    doors_status status;
    QTimer doors_open_timer;
    QTimer doors_close_timer;
    QTimer doors_stay_open_timer;
};
