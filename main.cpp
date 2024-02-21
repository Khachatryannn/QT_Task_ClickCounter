#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>


class CounterApplication : public QWidget {
public:
    CounterApplication(QWidget *parent = nullptr) : QWidget(parent), counter(0) {
        initUI();
    }

private:
    void initUI() {
        setWindowTitle("Counter Application");
        setGeometry(200, 200, 400, 400);

        button = new QPushButton("Click here to increment the count", this);
        label = new QLabel("Count: 0", this);

        QFont Font = button->font();
        Font.setPointSize(25);
        button->setFont(Font);
        button->setStyleSheet("color: blue");
        button->show();


        QFont font = label->font();
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet("color: yellow");
        label->setAlignment(Qt::AlignCenter);

        label->show();


        QVBoxLayout *layout = new QVBoxLayout(this);
        layout-> addWidget(button);
        layout-> addWidget(label);

        connect(button, &QPushButton::clicked, this, &CounterApplication::incrementTheCounter);
    }

    void incrementTheCounter() {
        counter++;
        label->setText("Count: " + QString::number(counter));
    }


    QPushButton *button;
    QLabel *label;
    int counter;
};

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    CounterApplication window;
    window.show();


    return app.exec();
}
