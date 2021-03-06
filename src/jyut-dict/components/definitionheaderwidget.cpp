#include "definitionheaderwidget.h"

DefinitionHeaderWidget::DefinitionHeaderWidget(QWidget *parent)
    : QWidget(parent)
{
    _layout = new QVBoxLayout(this);
    _layout->setContentsMargins(0, 0, 0, 0);
    _layout->setSpacing(5);

    _titleLabel = new QLabel(this);
    _divider = new QFrame(this);
    _divider->setFrameShape(QFrame::HLine);
    _divider->setFrameShadow(QFrame::Raised);

    _layout->addWidget(_titleLabel);
    _layout->addWidget(_divider);

    setLayout(_layout);
}

DefinitionHeaderWidget::DefinitionHeaderWidget(std::string title, QWidget *parent)
    : DefinitionHeaderWidget(parent)
{
    setSectionTitle(title);
}

void DefinitionHeaderWidget::setSectionTitle(std::string title)
{
    std::string formattedTitle = formatTitle(title);
    _titleLabel->setText(formattedTitle.c_str());
    _titleLabel->setFixedHeight(_titleLabel->fontMetrics().boundingRect(title.c_str()).height());
}

std::string DefinitionHeaderWidget::formatTitle(std::string title)
{
    return "<font color=#6f6f6f>" + title + "</font>";
}

DefinitionHeaderWidget::~DefinitionHeaderWidget()
{
    delete _layout;
    delete _titleLabel;
    delete _divider;
}
