#ifndef MYDESIGNERPLUGINPLUGIN_H
#define MYDESIGNERPLUGINPLUGIN_H

// #include <QDesignerCustomWidgetInterface>
#include <QtUiPlugin/customwidget.h>

class MyDesignerPluginPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT

    Q_INTERFACES(QDesignerCustomWidgetInterface)

#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
#endif // QT_VERSION >= 0x050000

public:
    MyDesignerPluginPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool m_initialized;
};

#endif // MYDESIGNERPLUGINPLUGIN_H
