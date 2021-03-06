/**
  * This file is part of OVU.
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  *
  * Copyright (C) 2015 Mikhail Ivchenko <ematirov@gmail.com>
  *
  **/

#ifndef FEED_H
#define FEED_H

#include "FeedModel.h"

#include <QObject>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Feed : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString sourceText READ sourceText WRITE setSource
               NOTIFY sourceChanged)
    Q_PROPERTY(FeedModel *model READ model NOTIFY modelChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QUrl url READ url NOTIFY urlChanged)

public:
    explicit Feed(QObject *parent = 0);
    ~Feed();
    void setSource(const QString &sourceText, const QUrl &url=QUrl());
    QString sourceText() { return m_source; }

    FeedModel *model();

    QString title() const;
    void setTitle(const QString &title);

    Q_INVOKABLE void get(const QString &urlString);
    Q_INVOKABLE void get(const QUrl &url);
    Q_INVOKABLE void getNextPage();

    QUrl url() const;

Q_SIGNALS:
    void sourceChanged();
    void modelChanged();
    void titleChanged();
    void urlChanged();
    void errorHappened(QString message);
    void authRequired();
    void parsingFinished(bool hasError);

private slots:
    void parse(QNetworkReply *reply);

protected:
    void printError(const QXmlStreamReader &reader) const;
    QString m_source;
    FeedModel *m_model;
    QString m_title;
    QNetworkAccessManager *m_networkManager;
    QUrl m_url;
    QUrl m_nextPageUrl;
    bool m_isAddingNextPage;
};

#endif // FEED_H

