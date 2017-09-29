#ifndef SOUNDAPPLET_H
#define SOUNDAPPLET_H

#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QGSettings>
#include <dimagebutton.h>

class DBusAudio;
class DBusSink;

namespace dtb {

namespace widgets {
class FontLabel;
}

namespace sound {
class VolumeSlider;
class SoundApplet : public QScrollArea
{
    Q_OBJECT

public:
    explicit SoundApplet(QWidget *parent = 0);

    int volumeValue() const;
    VolumeSlider *mainSlider();

    void showAni();
    void hideAni();

signals:
    void volumeChanged(const int value) const;
    void defaultSinkChanged(DBusSink *sink) const;
    void requestHidePopup() const;

private slots:
    void defaultSinkChanged();
    void onVolumeChanged();
    void volumeSliderValueChanged();
    void sinkInputsChanged();
    void toggleMute();
    void delayLoad();
    void onPlaySoundEffect();

protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;

private:
    QWidget *m_centralWidget;
    QWidget *m_applicationTitle;
    widgets::FontLabel *m_volumeBtn;
    VolumeSlider *m_volumeSlider;
    QVBoxLayout *m_centralLayout;

    DBusAudio *m_audioInter;
    DBusSink *m_defSinkInter;
    QGSettings *m_gsetting;
};
}
}


#endif // SOUNDAPPLET_H
