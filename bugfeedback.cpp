#include "bugfeedback.h"
#include<QLabel>
#include<QPlaceContactDetail>
#include<QPlace>
BugFeedback::BugFeedback(QDialog *parent) : QDialog(parent)
{
  setWindowTitle (tr("Bug Feedback"));
  feedback_text = new QTextEdit;
  QLabel *nameLabel = new QLabel(tr("Bug FeedBack"),this);
  QLabel *emailLabel = new QLabel(tr("Email:hnlyxacj@sina.com"),this);

  QLabel *gitaddrLabel = new QLabel(tr("git:https://github.com/tujidanerhao/SME"),this);
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addWidget (nameLabel);
  mainLayout->addWidget (emailLabel);
  mainLayout->addWidget (gitaddrLabel);
  //mainLayout->addWidget (feedback_text);

}
