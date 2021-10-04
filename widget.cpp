#include "widget.h"
#include <QLayout>
#include <QMetaEnum>
#include <QPushButton>
#include <QStyle>
#include <iostream>

Widget::Widget(QWidget* parent)
    : QWidget(parent)
{
    auto layout = new QGridLayout;
    setLayout(layout);

    constexpr int cols = 6;
    const auto meta_enum = QMetaEnum::fromType<QStyle::StandardPixmap>();
    for (int i = 0; i < 78; ++i) {
        auto btn = new QPushButton(tr("%1").arg(i, 2));
        auto icon = this->style()->standardIcon(QStyle::StandardPixmap(i));
        btn->setIcon(icon);
        QString name = meta_enum.valueToKey(i);
        connect(btn, &QPushButton::clicked, [name, i]() {
            std::cout << i << ": " << name.toStdString() << std::endl;
        });
        layout->addWidget(btn, i / cols, i % cols);
    }
}

Widget::~Widget()
{
}
