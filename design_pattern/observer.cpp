/**
* �۲���ģʽ������һ��һ�Զ��������ϵ�� �ö���۲��߶���ͬʱ����ĳһ���������
* ������������״̬�Ϸ����仯ʱ����֪ͨ���й۲��߶����������ܹ��Զ������Լ���
* �ڹ۲���ģʽ�У��г��������ɫ��Subject�������������ɫ��ConcreteSubject��,
* ����۲��߽�ɫ(Observer)������۲��߽�ɫ(ConcreteObserver).
* observer pattern
* @author Liang Cheng
* @date 11/28/2012
**/

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Subject; // abstract
class ConcreteSubject : public Subject;
class Observer; // interface
class ConcreteObserver : public Observer;


/**
 * abstract subject
 * @author Liang Cheng
 */
class Subject
{
private:
    list<Observer *> *_observers;
    list<Observer *>::iterator _it;

protected:
    Subject();

public:
    /**
     * @param observer
     */
    virtual ~Subject();

    virtual void AddObserver(Observer* ob)
    {
        _observers->push_back(ob);
    }

    virtual void RemoveObserver(Oberver* ob)
    {
        _observers->erase(ob);
    }

    virtual void NotifyObserver()
    {
        cout << " observer is notified.\n";
        for (_it= _observers.begin(); _it !=_observers.end(); _it++)
        {
            _it->Update(this);
        }
    }

};





class ConcreteSubject: public Subject
{
public:
    ConcreteSubject();
//    virtual int GetHour();
//    virtual int GetMinut();
//    virtual int GetSecond();

    void Tick();

}

void ConcreteSubject::Tick()
{
    //update internal time-keeping state
    NotifyObserver();
}


/**
*
**/
class Observer
{
public:
    virtual ~Observer();
    virtual void Update(Subject* the_changed_subject) = 0;

protected:
    Observer();

};


/**
*
**/
class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(ConcreteSubject *cs)
    {
        _cs = cs;
        _cs->Add_observer(this);
    }
    virtual ~ConcreteObserver()
    {
        _cs->Remove_observer(this);
    }


    virtual void Update(Subject *s)
    {
        if ( _cs == s)
            cout << "same subject, and draw()."<<str<<"\n";
    }

private:
    ConcreteSubject* _cs;
};





/**
*
**/
int main()
{
    ConcreteSubject  *sub = new ConcreteSubject;
    ConcreteObserver *ob1 = new ConcreteObserver(sub);
    ConcreteObserver *ob2 = new ConcreteObserver(sub);


    /**
     * register three observer
     **/
    sub->Notify_observer("Today is 11/29/2012.");

    //remove a observer;
    sub->Remove_observer(ob1);
    sub->Notify_observer("Today is not 11/29/2012.");


    delete ob1, ob2, sub;
    return 0;
}
