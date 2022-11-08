// Programmer: Will Weidler
// Section: 101
// Assignment: HW 3

#include <iostream>

using namespace std;

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
    delete m_head;
    m_head = NULL;
    return;
}

template <typename T>
const LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    if (this == &rhs)
        return *this;
    while (!isEmpty())
    {
        clear();
    }
    LLNode<T> *p = m_head;
    LLNode<T> *q = rhs.m_head;
    while (q->m_next != NULL)
    {
        insert(q->m_data, p);
        q = q->m_next;
        p = p->m_next;
    }
    m_size = rhs.m_size;
    return *this;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)
{
    m_head = new LLNode<T>;
    m_size = 0;
    LLNode<T> *p = m_head;
    LLNode<T> *q = rhs.m_head;
    while (q->m_next != NULL)
    {
        insert(q->m_data, p);
        q = q->m_next;
        p = p->m_next;
    }
    m_size = rhs.m_size;
    return;
}

template <typename T>
int LinkedList<T>::size() const
{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return m_size == 0;
}

template <typename T>
LLNode<T> *LinkedList<T>::getFirstPtr()
{
    if (m_head->m_next != NULL)
        return m_head;
    else
        cout << "!!! ERROR : PANIC in LINKEDLIST !!!" << endl
             << "Empty List: Please insert values into linked list" << endl;
    return NULL;
}

template <typename T>
LLNode<T> *LinkedList<T>::getAtPtr(int i)
{
    if (0 <= i && i <= m_size)
    {
        LLNode<T> *rp = m_head;
        for (int k = 0; k < i; k++)
        {
            rp = rp->m_next;
        }
        return rp;
    }
    else
    {
        cout << "!!! ERROR : PANIC in LINKEDLIST !!!" << endl
             << "Index outside of linked list range: please use a valid index" << endl;
        return NULL;
    }
}

template <typename T>
void LinkedList<T>::clear()
{
    while (m_head->m_next != NULL)
    {
        remove_front();
    }
    m_size = 0;
    return;
}

template <typename T>
void LinkedList<T>::insert_front(const T &x)
{
    LLNode<T> *tmp = new LLNode<T>;
    tmp->m_data = x;
    tmp->m_next = m_head;
    m_head = tmp;
    m_size++;
    return;
}

template <typename T>
void LinkedList<T>::insert_back(const T &x)
{
    if (m_size == 0)
        insert_front(x);
    else
        insert(x, getAtPtr(m_size));
    return;
}

template <typename T>
void LinkedList<T>::insert(const T &x, LLNode<T> *pos)
{
    LLNode<T> *tmp = new LLNode<T>;
    tmp->m_data = pos->m_data;
    tmp->m_next = pos->m_next;
    pos->m_next = tmp;
    pos->m_data = x;
    m_size++;
    tmp = NULL;
    return;
}

template <typename T>
void LinkedList<T>::remove_front()
{
    if (m_head != NULL)
    {
        remove(m_head);
    }
    else
        cout << "!!! ERROR : PANIC in LINKEDLIST !!!" << endl
             << "Empty List: Please insert values into linked list" << endl;
    return;
}

template <typename T>
void LinkedList<T>::remove_back()
{
    if (m_head != NULL)
    {
        remove(getAtPtr(m_size - 1));
    }
    else
        cout << "!!! ERROR : PANIC in LINKEDLIST !!!" << endl
             << "Empty List: Please insert values into linked list" << endl;
    return;
}

template <typename T>
void LinkedList<T>::remove(LLNode<T> *pos)
{
    if (m_head != NULL)
    {

        LLNode<T> *tmp = pos->m_next;
        pos->m_data = tmp->m_data;
        pos->m_next = tmp->m_next;
        m_size--;
        delete tmp;
        tmp = NULL;
    }
    else
        cout << "!!! ERROR : PANIC in LINKEDLIST !!!" << endl
             << "Empty List: Please insert values into linked list" << endl;
    return;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const
{
    LLNode<T> *rp1 = m_head;
    LLNode<T> *rp2 = rhs.m_head;
    if (m_size != rhs.m_size)
    {
        return false;
    }
    while (rp1->m_next != NULL)
    {
        if (rp1->m_data != rp2->m_data)
        {
            return false;
        }
        rp1 = rp1->m_next;
        rp2 = rp2->m_next;
    }
    return true;
}

template <typename T>
LLNode<T> *LinkedList<T>::find(const T &x)
{
    LLNode<T> *rp = m_head;
    while (rp->m_data != x && rp->m_next != NULL)
    {
        rp = rp->m_next;
    }
    if (rp->m_next != NULL)
    {
        return rp;
    }
    else
    {
        cout << "!!! ERROR : PANIC in LINKEDLIST !!!" << endl
             << "Object not found in linked list" << endl;
        return NULL;
    }
}

template <typename T>
void LinkedList<T>::reverse()
{
    LLNode<T> *current = m_head;
    LLNode<T> *prev = NULL;
    LLNode<T> *next = NULL;

    while (current->m_next != NULL)
    {

        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
    delete current;
    current = NULL;
    next = NULL;
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T> &l2)
{
    LLNode<T> *rp = l2.m_head;
    for (int i = 0; i < l2.size(); i++)
    {
        insert_back(rp->m_data);
        rp = rp->m_next;
    }
    rp = NULL;
    delete rp;
}
template <typename T>
void LinkedList<T>::slice(const LinkedList<T> &l2, LLNode<T> *start, LLNode<T> *stop)
{
    l2.size();
    do
    {
        insert_back(start->m_data);
        start = start->m_next;
    } while (start != stop);
    return;
}

template <typename T>
ostream &operator<<(ostream &out, const LinkedList<T> &list)
{
    out << "[ ";
    LLNode<T> *rp = list.m_head;
    for (int k = 0; k < list.size(); k++)
    {
        out << rp->m_data << ", ";
        rp = rp->m_next;
    }
    out << "]";
    rp = NULL;
    return out;
}