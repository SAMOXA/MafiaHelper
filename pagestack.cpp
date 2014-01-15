#include "pagestack.h"

PageStack::PageStack(QObject *parent) :
    QObject(parent)
{
    //currentPage = "";
}

void PageStack::addPageToSave(const QString& pageName)
{
    pageToSave << pageName;
}

void PageStack::setCurrentPage(const QString& pageName)
{
    currentPage = pageName;
}

QVariant PageStack::getPageToSave()
{
    return QVariant::fromValue(pageToSave);
}

void PageStack::pushPage(const QString& pageName)
{
    stack.push(pageName);
}

QVariant PageStack::popPage()
{
    if(stack.size()>0){
        currentPage = stack.pop();
    }
    return QVariant::fromValue(currentPage);
}

void PageStack::resetStack(const QString& pageName)
{
    stack.clear();
    stack.push(pageName);
}
