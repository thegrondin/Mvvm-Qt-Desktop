#ifndef CUSTOMERMODEL_H
#define CUSTOMERMODEL_H

#include <QString>

class CustomerModel
{
private:
    QString firstname;
    QString lastname;
    int age;
public:
    CustomerModel() {
        firstname = "Thomas";
        lastname = "Dion-Grondin";
        age = 19;
    }
    virtual ~CustomerModel() {}
    QString GetFirstname() const {
        return firstname;
    }
    QString GetLastname() const {
        return lastname;
    }
    int GetAge() const {
        return age;
    }

    void SetFirstname(const QString& value) {
        firstname = value;
    }

    void SetLastname(const QString& value) {
        lastname = value;
    }

    void SetAge(const int& value) {
        age = value;
    }
};

#endif // CUSTOMERMODEL_H


/*
 *
 *  virtual ~MainModel()
    { }

    QString GetSourceValue() const
    {
        return _sourceValue;
    }

    void SetSourceValue(const QString& value)
    {
        _sourceValue = value;
    }

    QString GetDestinationValue() const
    {
        return _destinationValue;
    }

    void SetDestinationValue(const QString& value)
    {
        if (!value.isEmpty()) {
            _destinationValue = HashValue(value);
        }
        else {
            _destinationValue = value;
        }
    }

private:
    QString HashValue(const QString& value)
    {
        return QString(QCryptographicHash::hash(value.toUtf8(), QCryptographicHash::Md5).toHex());
    }
};
*/
