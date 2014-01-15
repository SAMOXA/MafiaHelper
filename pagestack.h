#ifndef PAGESTACK_H
#define PAGESTACK_H

#include <QObject>
#include <QStringList>
#include <QVariant>
#include <QStack>

class PageStack : public QObject
{
    Q_OBJECT
public:
    explicit PageStack(QObject *parent = 0);
    Q_INVOKABLE QVariant getPageToSave();
    Q_INVOKABLE QVariant popPage();
    Q_INVOKABLE void pushPage(const QString& pageName);
    Q_INVOKABLE void resetStack(const QString& pageName);
    void addPageToSave(const QString& pageName);
    void setCurrentPage(const QString& pageName);
private:
    QStringList pageToSave;
    QStack <QString> stack;
    QString currentPage;
signals:

public slots:

};

#endif // PAGESTACK_H
