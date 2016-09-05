#ifndef BUGFEEDBACK_H
#define BUGFEEDBACK_H

#include <QDialog>
#include <QTextEdit>
#include<QPushButton>
#include<QHBoxLayout>
class BugFeedback : public QDialog
{
    Q_OBJECT
public:
    explicit BugFeedback(QDialog *parent = 0);

signals:

public slots:
private:
   QTextEdit *feedback_text;
   QPushButton *SubmitBtn,CancelBtn;
};

#endif // BUGFEEDBACK_H
