#ifndef SEARCHOPTIONSRADIOGROUPBOX_H
#define SEARCHOPTIONSRADIOGROUPBOX_H

#include "logic/search/isearchoptionsmediator.h"
#include "logic/search/searchparameters.h"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QRadioButton>

class SearchOptionsRadioGroupBox : public QGroupBox
{
Q_OBJECT
public:
    SearchOptionsRadioGroupBox(ISearchOptionsMediator *mediator, QWidget *parent = nullptr);

private:
    void notifyMediator();

    ISearchOptionsMediator *_mediator;

    QHBoxLayout *_layout;

    QRadioButton *_simplifiedButton;
    QRadioButton *_traditionalButton;
    QRadioButton *_jyutpingButton;
    QRadioButton *_pinyinButton;
    QRadioButton *_englishButton;
};

#endif // SEARCHOPTIONSRADIOGROUPBOX_H
