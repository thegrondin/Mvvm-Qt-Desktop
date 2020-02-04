#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H
#include <QObject>
#include <iostream>
#include "customermodel.h"

class MainViewModel: public QObject
{
    Q_OBJECT
private:
    CustomerModel customerModel_;
    Q_PROPERTY(QString firstname READ GetFirstname WRITE SetFirstname NOTIFY FirstnameChanged);
    Q_PROPERTY(QString lastname READ GetLastname WRITE SetLastname NOTIFY LastnameChanged);
    Q_PROPERTY(int age READ GetAge WRITE SetAge NOTIFY AgeChanged);
public:
    explicit MainViewModel(const CustomerModel& customer) {
        customerModel_ = customer;
    }
    virtual ~MainViewModel() { }
    QString GetFirstname() {
        return customerModel_.GetFirstname();
    }
    QString GetLastname() {
        return customerModel_.GetLastname();
    }
    int GetAge() {
        return customerModel_.GetAge();
    }
public slots:
    void SetFirstname(QString& arg) {
        if (customerModel_.GetFirstname() != arg) {
            customerModel_.SetFirstname(arg);
            FirstnameChanged(arg);
        }
    }
    void SetLastname(QString& arg) {
        if (customerModel_.GetLastname() != arg){
            customerModel_.SetLastname(arg);
            LastnameChanged(arg);
        }
    }
    void SetAge(int arg) {
        if (customerModel_.GetAge() != arg) {
            customerModel_.SetAge(arg);
            AgeChanged(arg);
        }
    }
    Q_INVOKABLE void executeBtn() // clear command
    {
        //std::cout << "Customer name is : " << customerModel_.GetFirstname().toUtf8().constData();
    }

signals:
    void FirstnameChanged(QString& arg);
    void LastnameChanged(QString& arg);
    void AgeChanged(int arg);
};

#endif // MAINVIEWMODEL_H


/*
 * #ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "../Model/MainModel.h"

class MainViewModel : public QObject
{
    Q_OBJECT

private:
    // main model
    MainModel _mainModel;

    // declaration of source property
    Q_PROPERTY (QString sourceValue READ GetSourceValue WRITE SetSourceValue NOTIFY SourceChangedEvent);

    // declaration of destination property
    Q_PROPERTY (QString destinationValue READ GetDestinationValue WRITE SetDestinationValue
                NOTIFY DestinationChangedEvent);

public:
    explicit MainViewModel(const MainModel& mainModel)
    {
        _mainModel = mainModel;
    }

    virtual ~MainViewModel()
    { }

    Q_INVOKABLE void clearCommand() // clear command
    {
        QString emptyString = "";
        SetSourceValue(emptyString);
    }

    QString GetSourceValue() const
    {
        return _mainModel.GetSourceValue();
    }

    QString GetDestinationValue() const
    {
        return _mainModel.GetDestinationValue();
    }

public slots:
    void SetSourceValue(QString& arg)
    {
        if (_mainModel.GetSourceValue() != arg) {
            _mainModel.SetSourceValue(arg);
            SourceChangedEvent(arg);
            SetDestinationValue(arg);
        }
    }

    void SetDestinationValue(QString& arg)
    {
        if (_mainModel.GetDestinationValue() != arg) {
            _mainModel.SetDestinationValue(arg);
            DestinationChangedEvent(arg);
        }
    }

signals:
    void SourceChangedEvent(QString& arg);
    void DestinationChangedEvent(QString& arg);
};

#endif // MAINVIEWMODEL_H
*/
