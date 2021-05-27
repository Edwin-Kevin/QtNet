#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QNetworkInterface>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void GetLocalIPAddress();
    QByteArray HexStringToByteArray(QString HexString);

    void FrameProc(QString &str);

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpClient;
    QTcpServer *tcpServer;
    QList<QTcpSocket*> lstClient;
    QTcpSocket *currentClient;

private slots:
    void ReadData();
    void ReadError(QAbstractSocket::SocketError);

    void NewConnectionSlot();
    void disconnectedSlot();
    void ServerReadData();

    void on_BtnConn_clicked();
    void on_BtnClearRecv_clicked();
    void on_BtnSend_clicked();
    void on_radioClient_clicked();
    void on_radioServer_clicked();
    void on_btn_readpara_clicked();
    void on_btn_setpara_clicked();
    void on_btn_openup_clicked();
    void on_btn_stopup_clicked();
};

#endif // MAINWINDOW_H
