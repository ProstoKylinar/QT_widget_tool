#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QAudioOutput>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаем объекты QMediaPlayer и QMediaPlaylist
    QMediaPlayer mediaPlayer;
    QMediaPlaylist playlist;
    mediaPlayer.setPlaylist(&playlist);

    // Создаем виджеты
    QWidget window;
    QVBoxLayout layout(&window);

    QPushButton playButton("Play");
    layout.addWidget(&playButton);

    QPushButton fileButton("Select File");
    layout.addWidget(&fileButton);

    QLabel fileLabel("Selected File: ");
    layout.addWidget(&fileLabel);

    QString filePath;

    // Обработчик нажатия кнопки "Select File"
    QObject::connect(&fileButton, &QPushButton::clicked, [&]() {
        filePath = QFileDialog::getOpenFileName(&window, "Open Audio File", QDir::homePath(), "Audio Files (*.mp3 *.wav)");
        if (!filePath.isEmpty()) {
            // Очищаем плейлист и добавляем выбранный файл
            playlist.clear();
            playlist.addMedia(QUrl::fromLocalFile(filePath));
            playlist.setCurrentIndex(0);

            // Обновляем текст в QLabel
            fileLabel.setText("Selected File: " + filePath);

            // Разблокируем кнопку Play
            playButton.setEnabled(true);
        }
    });

    // Блокируем кнопку Play при старте программы
    playButton.setEnabled(false);

    // Обработчик нажатия кнопки "Play"
    QObject::connect(&playButton, &QPushButton::clicked, [&]() {
        if (!filePath.isEmpty()) {
            if (mediaPlayer.state() == QMediaPlayer::PlayingState) {
                mediaPlayer.pause();
                playButton.setText("Play");
            } else {
                mediaPlayer.play();
                playButton.setText("Pause");

                // Устанавливаем параметры звука для QAudioOutput
                QAudioFormat format;
                format.setSampleRate(44100);
                format.setChannelCount(2);
                format.setSampleSize(16);
                format.setCodec("audio/pcm");
                format.setByteOrder(QAudioFormat::LittleEndian);
                format.setSampleType(QAudioFormat::SignedInt);

                // Открываем файл для чтения
                QFile file(filePath);
                file.open(QIODevice::ReadOnly);

                // Применяем параметры к QAudioOutput
                QAudioOutput audioOutput(format, &window);

                // Устанавливаем устройство вывода
                audioOutput.start(&file);
            }
        }
    });

    window.show();

    return a.exec();
}
