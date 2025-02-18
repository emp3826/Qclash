#pragma once
#include "QvAutoCompleteTextEdit.hpp"
#include "base/QvBase.hpp"
#include "ui_RouteSettingsMatrix.h"

#include <QMenu>
#include <QWidget>
#include <optional>

class RouteSettingsMatrixWidget
    : public QWidget
    , private Ui::RouteSettingsMatrix
{
    Q_OBJECT

  public:
    RouteSettingsMatrixWidget(const QString &assetsDirPath, QWidget *parent = nullptr);
    void SetRouteConfig(const QvConfig_Route &conf);
    QvConfig_Route GetRouteConfig() const;
    ~RouteSettingsMatrixWidget();

  private:
    std::optional<QString> openFileDialog();
    std::optional<QString> saveFileDialog();
    QList<QAction *> getBuiltInSchemes();
    QAction *schemeToAction(const QString &name, const QvConfig_Route &scheme);

  private:
    QMenu *builtInSchemesMenu;

  private slots:
    void on_importSchemeBtn_clicked();
    void on_exportSchemeBtn_clicked();

  private:
    const QString &assetsDirPath;

  private:
    Qvmessocket::ui::widgets::AutoCompleteTextEdit *directDomainTxt;
    Qvmessocket::ui::widgets::AutoCompleteTextEdit *proxyDomainTxt;
    Qvmessocket::ui::widgets::AutoCompleteTextEdit *blockDomainTxt;
    //
    Qvmessocket::ui::widgets::AutoCompleteTextEdit *directIPTxt;
    Qvmessocket::ui::widgets::AutoCompleteTextEdit *blockIPTxt;
    Qvmessocket::ui::widgets::AutoCompleteTextEdit *proxyIPTxt;
};
