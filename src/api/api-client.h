#ifndef SEAFILE_API_CLIENT_H
#define SEAFILE_API_CLIENT_H

#include <QString>
#include <QObject>

#include "account.h"
#include "server-repo.h"

class QNetworkAccessManager;
class QByteArray;
class QNetworkReply;
class QSslError;

/**
 * SeafileApiClient handles the underlying api mechanism
 */
class SeafileApiClient : public QObject {
    Q_OBJECT

public:
    SeafileApiClient();
    ~SeafileApiClient();
    void setToken(const QString& token) { token_ = token; };
    void get(const QUrl& url);
    void post(const QUrl& url, const QByteArray& encodedParams);

signals:
    void requestSuccess(QNetworkReply& reply);
    void requestFailed(int code);
    void sslErrors(QNetworkReply *, const QList<QSslError>&);

private slots:
    void httpRequestFinished();
    void onSslErrors(const QList<QSslError>& errors);

private:
    Q_DISABLE_COPY(SeafileApiClient)

    static QNetworkAccessManager *na_mgr_;

    QString token_;

    QNetworkReply *reply_;
};

#endif  // SEAFILE_API_CLIENT_H
