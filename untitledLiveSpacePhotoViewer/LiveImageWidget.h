#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMovie>
#include <QPushButton>
#include <QThread>
#include <atomic>
#include <condition_variable>
#include <mutex>

class LiveImageWidget : public QWidget {
    Q_OBJECT
public:
    LiveImageWidget(QWidget* parent = nullptr);
    ~LiveImageWidget();

private:
    QLabel* lblTitle;
    QLabel* lblImage;
    QLabel* loadingLabel;
    QMovie* loadingGif;
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    QPushButton* startBtn;
    QPushButton* pauseBtn;
    QPushButton* resumeBtn;

    class LiveImageThread : public QThread {
        Q_OBJECT
    public:
        LiveImageThread();
        ~LiveImageThread();

        void run() override;
        void startThread();
        void pauseThread();
        void resumeThread();
        void stopThread();

    signals:
        void imageUpdated(const QPixmap& pixmap, const QString& title);

    private:
        std::atomic<bool> runFlag;
        std::atomic<bool> terminateFlag;
        std::condition_variable cv;
        std::mutex cvMutex;
    };

    LiveImageThread* thread;
};
